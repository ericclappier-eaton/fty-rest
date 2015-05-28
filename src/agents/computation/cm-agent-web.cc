/*
Copyright (C) 2015 Eaton

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*!
 \file   cm-agent-web.cc
 \brief  TODO
 \author Karol Hrdina <KarolHrdina@eaton.com>
*/


#include "bios_agent.h"
#include "agents.h"
#include "defs.h"
#include "log.h"
#include "str_defs.h"
#include "utils.h"
#include "utils_ymsg.h"
#include "utils_ymsg++.h"

#include "db/measurements.h"
#include "cm-agent-utils.h"
#include "cm-agent-web.h"
#include "cleanup.h"

static int 
request_averages 
(int64_t element_id, const char *source, const char *type, const char *step, int64_t start_timestamp, int64_t end_timestamp,
 std::map<int64_t, double>& averages, std::string& unit, int64_t& last_average_timestamp, ymsg_t *message_out);

static int
request_sampled
(int64_t element_id, const char *topic, int64_t start_timestamp, int64_t end_timestamp,
 std::map<int64_t, double>& samples, std::string& unit, ymsg_t *message_out);

void
process_web_average
(bios_agent_t *agent, ymsg_t *message_in, const char *sender, ymsg_t **message_out) {
    assert (agent);
    assert (message_in);
    assert (sender);
    assert (message_out);

    log_info ("start");

    int64_t start_ts = -1, end_ts = -1;
    char *type = NULL, *step = NULL, *source = NULL;
    uint64_t element_id = 0;

    try {                
        *message_out = ymsg_new (YMSG_REPLY);
        assert (*message_out);

        // Decode web average request
        int rv = bios_web_average_request_extract (message_in, &start_ts, &end_ts, &type, &step, &element_id, &source);
        if (rv != 0) {
            log_error ("bios_web_average_request_extract () failed.");
            ymsg_set_status (*message_out, false);
            ymsg_set_errmsg (*message_out, "Internal error: Protocol failure.");
            return;       
        }

        // Resolve device name from element id        
        std::string device_name;
        {
            auto ret = persist::get_device_name_from_element_id (element_id, device_name);
            if (ret.rv == -1)
                log_error ("Could not resolve device name from element id: %" PRId64". Can not publish computed values on stream.", element_id);
            else
                log_debug ("Device name resolved from element id: '%" PRId64"' is '%s'", element_id, device_name.c_str ());
        }

        
        // First, try to request the averages
        std::string unit;
        int64_t last_average_ts;
        std::map<int64_t, double> averages;
        if (!request_averages (element_id, source, type, step, start_ts, end_ts, averages, unit, last_average_ts, *message_out)) {
            return;
        } 

        std::string json_out (BIOS_WEB_AVERAGE_REPLY_JSON_TMPL); // resulting output json           
        json_out.replace (json_out.find ("##UNITS##"), strlen ("##UNITS##"), unit);
        json_out.replace (json_out.find ("##SOURCE##"), strlen ("##SOURCE##"), source);
        json_out.replace (json_out.find ("##STEP##"), strlen ("##STEP##"), step);
        json_out.replace (json_out.find ("##TYPE##"), strlen ("##TYPE##"), type);
        json_out.replace (json_out.find ("##ELEMENT_ID##"), strlen ("##ELEMENT_ID##"), std::to_string (element_id));
        json_out.replace (json_out.find ("##START_TS##"), strlen ("##START_TS##"), std::to_string (start_ts));
        json_out.replace (json_out.find ("##END_TS##"), strlen ("##END_TS##"), std::to_string (end_ts));
   

        std::map <int64_t, double> samples;
        assert (samples.empty ());

        int64_t start_sampled_ts = 0;
        std::string data_str; // json; member 'data'
        int comma_counter = 0;

        // Check if returned averages are complete
        if (averages.empty ()) {
            log_info ("averages empty");
            if (last_average_ts < start_ts) {
                // requesting stored averages returned an empty set + last stored averages timestamp's < start of requested interval
                // => we need to compute the whole requested interval
                log_info ("last average timestamp < start timestamp");
                start_sampled_ts = average_extend_left_margin (start_ts, step);
                if (!request_sampled (element_id, source, start_sampled_ts,
                                      end_ts + AGENT_NUT_REPEAT_INTERVAL_SEC, samples, unit, *message_out)) {
                    return;
                }
            }
            else if (start_ts <= last_average_ts && last_average_ts <= end_ts) {                        
                log_error ("persist::get_measurements_averages ('%" PRIu64"', %s, %s, %" PRId64 ", %" PRId64", ...) "
                           "returned last average timestamp: %" PRId64", that falls inside <start_timestamp, end_timestamp> "
                           "but returned map of averages is empty.",
                           element_id, source, step, start_ts, end_ts, last_average_ts);
                ymsg_set_status (*message_out, false);
                ymsg_set_errmsg (*message_out, "Internal error: Extracting data from database failed.");
                return; 
            }
            else // untreated case is end_ts < last_average_ts -> nothing to do
                log_info ("last average timestamp > end timestamp");
        }
        else {
            log_info ("averages NOT empty");
            // put the stored averages into json
            for (const auto &p : averages) {
                std::string item = BIOS_WEB_AVERAGE_REPLY_JSON_DATA_ITEM_TMPL;
                item.replace (item.find ("##VALUE##"), strlen ("##VALUE##"), std::to_string (p.second));
                item.replace (item.find ("##TIMESTAMP##"), strlen ("##TIMESTAMP##"), std::to_string (p.first));
                if (comma_counter == 0) 
                    ++comma_counter;
                else
                    data_str += ",\n";           
                data_str += item;
            }
            // check if all requested averages were returned and if we need to compute something from sampled
            auto it = averages.end (); it--;
            int64_t last_container_ts = it->first;
            int64_t new_start;
            rv = check_completeness (last_container_ts, last_average_ts, end_ts, step, new_start);
            if (rv == 0) {
                log_info ("returned averages NOT complete");
                start_sampled_ts = average_extend_left_margin (new_start, step);
                if (!request_sampled (element_id, source, start_sampled_ts, end_ts + AGENT_NUT_REPEAT_INTERVAL_SEC,
                                      samples, unit, *message_out)) {
                    return;
                }
            }
            else
                log_info ("returned averages complete");
        }

        if (!samples.empty ()) {
            printf ("samples directly from db:\n"); // TODO: remove when done testing
            for (const auto &p : samples) {
                printf ("%" PRId64" => %f\n", p.first, p.second);
            }
            process_db_measurement_solve_left_margin (samples, start_sampled_ts);
            printf ("samples after solving left margin:\n"); // TODO: remove when done testing
            for (const auto &p : samples) {
                printf ("%" PRId64" => %f\n", p.first, p.second);
            }

            int64_t first_ts = samples.cbegin()->first;
            int64_t second_ts = average_first_since (first_ts, step);
            double comp_result;

            printf ("Starting computation from sampled data. first_ts: %" PRId64"\tsecond_ts: %" PRId64"\tend_ts:%ld",
                       first_ts, second_ts, end_ts);
            while (second_ts <= end_ts) {
                std::string item = BIOS_WEB_AVERAGE_REPLY_JSON_DATA_ITEM_TMPL;
                printf ("calling process_db_measurement_calculate (%ld, %ld)\n", first_ts, second_ts); // TODO: remove when done testing
                rv = process_db_measurement_calculate (samples, first_ts, second_ts, type, comp_result);
                // TODO: better return value check
                if (rv == 0) {
                    printf ("%ld\t%f\n", second_ts, comp_result); // TODO: remove when done testing
                    item.replace (item.find ("##VALUE##"), strlen ("##VALUE##"), std::to_string (comp_result));
                    item.replace (item.find ("##TIMESTAMP##"), strlen ("##TIMESTAMP##"), std::to_string (second_ts));
                    if (comma_counter == 0) 
                        ++comma_counter;
                    else
                        data_str += ",\n";

                    data_str += item;
                } else if (rv == -1) {
                    log_warning ("process_db_measurement_calculate failed"); // TODO
                }
                first_ts = second_ts;
                second_ts += average_step_seconds (step);


                // TODO: publish the measurement here
                /*
                if (!device_name.empty ()) {
                    * rescale value
                    * encode message
                    * bios_agent_send () ? I think subject == source_type_step@device_name, but not sure, too tired
                }
                _scoped_ymsg_t *msg = bios_measurement_encode (
                         const char *device_name, <-- device_name
                         const char *quantity, <-- ?
                         const char *units, <-- unit
                         int32_t value,
                         int32_t scale,
                         int64_t time);
                */ 
            }  
        }
                      
        json_out.replace (json_out.find ("##DATA##"), strlen ("##DATA##"), data_str);
        log_debug ("json that goes to output:\n%s", json_out.c_str ());

        ymsg_set_status (*message_out, true);
        zchunk_t *chunk = zchunk_new (json_out.c_str (), json_out.size ());
        assert (chunk);
        ymsg_set_response (*message_out, &chunk);

    }
    catch (const std::exception& e) {
        ymsg_set_status (*message_out, false);
        ymsg_set_errmsg (*message_out, "Internal error. Please check logs.");
        log_error ("std::exception caught: %s", e.what ());
    }
    catch (...) {
        ymsg_set_status (*message_out, false);
        ymsg_set_errmsg (*message_out, "Internal error. Please check logs.");
        log_error ("unknown exception caught");
    }

    FREE0 (type)
    FREE0 (step)
    FREE0 (source)
    
    return;
}


static int
request_averages
(int64_t element_id, const char *source, const char *type, const char *step, int64_t start_timestamp, int64_t end_timestamp,
 std::map<int64_t, double>& averages, std::string& unit, int64_t& last_average_timestamp, ymsg_t *message_out) {
    assert (source);
    assert (type);
    assert (step);
    assert (message_out);

    int return_value = 0;
    std::string message_str;
    auto ret = persist::get_measurements_averages
    (element_id, source, type, step, start_timestamp, end_timestamp, averages, unit, last_average_timestamp);
    switch (ret.rv) {
        case 0:
        {
            return_value = 1;
            break;
        }
        case 1:
        {
            log_info ("Element id: %" PRIu64" does not exist in persistence.", element_id);
            ymsg_set_status (message_out, false);
            message_str.assign ("Element id '").append (std::to_string (element_id)).append ("' does not exist.");
            ymsg_set_errmsg (message_out, message_str.c_str ());
            return_value = 0;
            break;
        }
        case 2:
        {
            log_info ("Topic does not exist for element id: '%" PRIu64"', source: '%s' and step: '%s' or element not in discovered devices.", element_id, source, step);
            return_value = 1;
            break;
        }
        case -1:
        default:
        {
            log_error ("persist::get_measurements_averages ('%" PRIu64"', %s, %s, %s, %" PRId64 ", %" PRId64", ...) failed",
                    element_id, source, type, step, start_timestamp, end_timestamp);
            ymsg_set_status (message_out, false);
            ymsg_set_errmsg (message_out, "Internal error: Extracting data from database failed.");
            return_value = 0;
            break;
        }
    }
    return return_value;
}

static int
request_sampled
(int64_t element_id, const char *topic, int64_t start_timestamp, int64_t end_timestamp,
  std::map<int64_t, double>& samples, std::string& unit, ymsg_t *message_out) {
    assert (topic);
    assert (message_out);

    int return_value = 0;
    std::string message_str;

    auto ret = persist::get_measurements_sampled (element_id, topic, start_timestamp, end_timestamp, samples, unit);
    switch (ret.rv) {
        case 0:
        {
            return_value = 1;
            break;
        }
        case 1:
        {
            log_info ("Element id: %" PRIu64" does not exist in persistence.", element_id);
            ymsg_set_status (message_out, false);
            message_str.assign ("Element id '").append (std::to_string (element_id)).append ("' does not exist.");
            ymsg_set_errmsg (message_out, message_str.c_str ());
            return_value = 0;
            break;
        }
        case 2:
        {
            log_info ("Topic '%s' does not exist for element id: '%" PRIu64"'", topic, element_id);
            ymsg_set_status (message_out, false);
            message_str.assign ("Topic '").append (topic).append ("' does not exist for element id '").append (std::to_string (element_id)).append ("'");
            ymsg_set_errmsg (message_out, message_str.c_str ());
            return_value = 0;
            break;
        }
        case -1:
        default:
        {
            log_error ("persist::get_measurements_sampled ('%" PRIu64"', %s, %" PRId64 ", %" PRId64", ...) failed",
                    element_id, topic, start_timestamp, end_timestamp);
            ymsg_set_status (message_out, false);
            ymsg_set_errmsg (message_out, "Internal error: Extracting data from database failed.");
            return_value = 0;
            break;
        }
    }
    return return_value;  
}

