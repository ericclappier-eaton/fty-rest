/*  =========================================================================
    fty_rest_classes - private header file

    Copyright (C) 2014 - 2018 Eaton

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
    =========================================================================
*/


#ifndef FTY_REST_CLASSES_H_INCLUDED
#define FTY_REST_CLASSES_H_INCLUDED

//  Platform definitions, must come first
#include "platform.h"

//  External API
#include "../include/fty_rest.h"

//  Extra headers

//  Opaque class structures to allow forward references
#ifndef DB_AGENTSTATE_AGENTSTATE_T_DEFINED
typedef struct _db_agentstate_agentstate_t db_agentstate_agentstate_t;
#define DB_AGENTSTATE_AGENTSTATE_T_DEFINED
#endif
#ifndef DB_ASSET_GENERAL_T_DEFINED
typedef struct _db_asset_general_t db_asset_general_t;
#define DB_ASSET_GENERAL_T_DEFINED
#endif
#ifndef DB_INOUT_T_DEFINED
typedef struct _db_inout_t db_inout_t;
#define DB_INOUT_T_DEFINED
#endif
#ifndef DB_INOUT_EXPORTCSV_T_DEFINED
typedef struct _db_inout_exportcsv_t db_inout_exportcsv_t;
#define DB_INOUT_EXPORTCSV_T_DEFINED
#endif
#ifndef DB_INOUT_IMPORTCSV_T_DEFINED
typedef struct _db_inout_importcsv_t db_inout_importcsv_t;
#define DB_INOUT_IMPORTCSV_T_DEFINED
#endif
#ifndef PERSIST_ASSETCRUD_T_DEFINED
typedef struct _persist_assetcrud_t persist_assetcrud_t;
#define PERSIST_ASSETCRUD_T_DEFINED
#endif
#ifndef PERSIST_ASSETTOPOLOGY_T_DEFINED
typedef struct _persist_assettopology_t persist_assettopology_t;
#define PERSIST_ASSETTOPOLOGY_T_DEFINED
#endif
#ifndef PERSIST_DBHELPERS_T_DEFINED
typedef struct _persist_dbhelpers_t persist_dbhelpers_t;
#define PERSIST_DBHELPERS_T_DEFINED
#endif
#ifndef PERSIST_MONITOR_T_DEFINED
typedef struct _persist_monitor_t persist_monitor_t;
#define PERSIST_MONITOR_T_DEFINED
#endif
#ifndef PERSIST_PERSIST_ERROR_T_DEFINED
typedef struct _persist_persist_error_t persist_persist_error_t;
#define PERSIST_PERSIST_ERROR_T_DEFINED
#endif
#ifndef SHARED_MAGIC_T_DEFINED
typedef struct _shared_magic_t shared_magic_t;
#define SHARED_MAGIC_T_DEFINED
#endif
#ifndef WARRANTY_WARRANTY_METRIC_T_DEFINED
typedef struct _warranty_warranty_metric_t warranty_warranty_metric_t;
#define WARRANTY_WARRANTY_METRIC_T_DEFINED
#endif
#ifndef WEB_SRC_ADD_GPIO_T_DEFINED
typedef struct _web_src_add_gpio_t web_src_add_gpio_t;
#define WEB_SRC_ADD_GPIO_T_DEFINED
#endif
#ifndef WEB_SRC_ADMIN_IFACE_T_DEFINED
typedef struct _web_src_admin_iface_t web_src_admin_iface_t;
#define WEB_SRC_ADMIN_IFACE_T_DEFINED
#endif
#ifndef WEB_SRC_ADMIN_IFACES_T_DEFINED
typedef struct _web_src_admin_ifaces_t web_src_admin_ifaces_t;
#define WEB_SRC_ADMIN_IFACES_T_DEFINED
#endif
#ifndef WEB_SRC_ADMIN_SSE_T_DEFINED
typedef struct _web_src_admin_sse_t web_src_admin_sse_t;
#define WEB_SRC_ADMIN_SSE_T_DEFINED
#endif
#ifndef WEB_SRC_ALERT_ACK_T_DEFINED
typedef struct _web_src_alert_ack_t web_src_alert_ack_t;
#define WEB_SRC_ALERT_ACK_T_DEFINED
#endif
#ifndef WEB_SRC_ALERT_LIST_T_DEFINED
typedef struct _web_src_alert_list_t web_src_alert_list_t;
#define WEB_SRC_ALERT_LIST_T_DEFINED
#endif
#ifndef WEB_SRC_ALERT_RULES_DETAIL_T_DEFINED
typedef struct _web_src_alert_rules_detail_t web_src_alert_rules_detail_t;
#define WEB_SRC_ALERT_RULES_DETAIL_T_DEFINED
#endif
#ifndef WEB_SRC_ALERT_RULES_T_DEFINED
typedef struct _web_src_alert_rules_t web_src_alert_rules_t;
#define WEB_SRC_ALERT_RULES_T_DEFINED
#endif
#ifndef WEB_SRC_ALERT_RULES_LIST_T_DEFINED
typedef struct _web_src_alert_rules_list_t web_src_alert_rules_list_t;
#define WEB_SRC_ALERT_RULES_LIST_T_DEFINED
#endif
#ifndef WEB_SRC_ASSET_DELETE_T_DEFINED
typedef struct _web_src_asset_delete_t web_src_asset_delete_t;
#define WEB_SRC_ASSET_DELETE_T_DEFINED
#endif
#ifndef WEB_SRC_ASSET_EXPORT_T_DEFINED
typedef struct _web_src_asset_export_t web_src_asset_export_t;
#define WEB_SRC_ASSET_EXPORT_T_DEFINED
#endif
#ifndef WEB_SRC_ASSET_GET_T_DEFINED
typedef struct _web_src_asset_get_t web_src_asset_get_t;
#define WEB_SRC_ASSET_GET_T_DEFINED
#endif
#ifndef WEB_SRC_ASSET_IMPORT_T_DEFINED
typedef struct _web_src_asset_import_t web_src_asset_import_t;
#define WEB_SRC_ASSET_IMPORT_T_DEFINED
#endif
#ifndef WEB_SRC_ASSET_LIST_T_DEFINED
typedef struct _web_src_asset_list_t web_src_asset_list_t;
#define WEB_SRC_ASSET_LIST_T_DEFINED
#endif
#ifndef WEB_SRC_ASSET_POST_T_DEFINED
typedef struct _web_src_asset_post_t web_src_asset_post_t;
#define WEB_SRC_ASSET_POST_T_DEFINED
#endif
#ifndef WEB_SRC_ASSET_PUT_T_DEFINED
typedef struct _web_src_asset_put_t web_src_asset_put_t;
#define WEB_SRC_ASSET_PUT_T_DEFINED
#endif
#ifndef WEB_SRC_ASSETS_IN_T_DEFINED
typedef struct _web_src_assets_in_t web_src_assets_in_t;
#define WEB_SRC_ASSETS_IN_T_DEFINED
#endif
#ifndef WEB_SRC_AUTH_T_DEFINED
typedef struct _web_src_auth_t web_src_auth_t;
#define WEB_SRC_AUTH_T_DEFINED
#endif
#ifndef WEB_SRC_AUTH_VERIFY_T_DEFINED
typedef struct _web_src_auth_verify_t web_src_auth_verify_t;
#define WEB_SRC_AUTH_VERIFY_T_DEFINED
#endif
#ifndef WEB_SRC_AVERAGE_T_DEFINED
typedef struct _web_src_average_t web_src_average_t;
#define WEB_SRC_AVERAGE_T_DEFINED
#endif
#ifndef WEB_SRC_CONFIG_T_DEFINED
typedef struct _web_src_config_t web_src_config_t;
#define WEB_SRC_CONFIG_T_DEFINED
#endif
#ifndef WEB_SRC_CONF_SCAN_T_DEFINED
typedef struct _web_src_conf_scan_t web_src_conf_scan_t;
#define WEB_SRC_CONF_SCAN_T_DEFINED
#endif
#ifndef WEB_SRC_CURRENT_T_DEFINED
typedef struct _web_src_current_t web_src_current_t;
#define WEB_SRC_CURRENT_T_DEFINED
#endif
#ifndef WEB_SRC_DATACENTER_INDICATORS_T_DEFINED
typedef struct _web_src_datacenter_indicators_t web_src_datacenter_indicators_t;
#define WEB_SRC_DATACENTER_INDICATORS_T_DEFINED
#endif
#ifndef WEB_SRC_EMAIL_FEEDBACK_T_DEFINED
typedef struct _web_src_email_feedback_t web_src_email_feedback_t;
#define WEB_SRC_EMAIL_FEEDBACK_T_DEFINED
#endif
#ifndef WEB_SRC_EMAIL_TEST_T_DEFINED
typedef struct _web_src_email_test_t web_src_email_test_t;
#define WEB_SRC_EMAIL_TEST_T_DEFINED
#endif
#ifndef WEB_SRC_EMAIL_VOTE_T_DEFINED
typedef struct _web_src_email_vote_t web_src_email_vote_t;
#define WEB_SRC_EMAIL_VOTE_T_DEFINED
#endif
#ifndef WEB_SRC_GETLOG_GET_T_DEFINED
typedef struct _web_src_getlog_get_t web_src_getlog_get_t;
#define WEB_SRC_GETLOG_GET_T_DEFINED
#endif
#ifndef WEB_SRC_GPO_ACTION_T_DEFINED
typedef struct _web_src_gpo_action_t web_src_gpo_action_t;
#define WEB_SRC_GPO_ACTION_T_DEFINED
#endif
#ifndef WEB_SRC_INFO_T_DEFINED
typedef struct _web_src_info_t web_src_info_t;
#define WEB_SRC_INFO_T_DEFINED
#endif
#ifndef WEB_SRC_INPUT_POWER_CHAIN_T_DEFINED
typedef struct _web_src_input_power_chain_t web_src_input_power_chain_t;
#define WEB_SRC_INPUT_POWER_CHAIN_T_DEFINED
#endif
#ifndef WEB_SRC_JSON_T_DEFINED
typedef struct _web_src_json_t web_src_json_t;
#define WEB_SRC_JSON_T_DEFINED
#endif
#ifndef WEB_SRC_LICENSE_T_DEFINED
typedef struct _web_src_license_t web_src_license_t;
#define WEB_SRC_LICENSE_T_DEFINED
#endif
#ifndef WEB_SRC_LICENSE_POST_T_DEFINED
typedef struct _web_src_license_post_t web_src_license_post_t;
#define WEB_SRC_LICENSE_POST_T_DEFINED
#endif
#ifndef WEB_SRC_LICENSE_STATUS_T_DEFINED
typedef struct _web_src_license_status_t web_src_license_status_t;
#define WEB_SRC_LICENSE_STATUS_T_DEFINED
#endif
#ifndef WEB_SRC_LICENSE_TEXT_T_DEFINED
typedef struct _web_src_license_text_t web_src_license_text_t;
#define WEB_SRC_LICENSE_TEXT_T_DEFINED
#endif
#ifndef WEB_SRC_LIST_GPIO_T_DEFINED
typedef struct _web_src_list_gpio_t web_src_list_gpio_t;
#define WEB_SRC_LIST_GPIO_T_DEFINED
#endif
#ifndef WEB_SRC_MY_PROFILE_T_DEFINED
typedef struct _web_src_my_profile_t web_src_my_profile_t;
#define WEB_SRC_MY_PROFILE_T_DEFINED
#endif
#ifndef WEB_SRC_NETCFG_T_DEFINED
typedef struct _web_src_netcfg_t web_src_netcfg_t;
#define WEB_SRC_NETCFG_T_DEFINED
#endif
#ifndef WEB_SRC_NOT_FOUND_T_DEFINED
typedef struct _web_src_not_found_t web_src_not_found_t;
#define WEB_SRC_NOT_FOUND_T_DEFINED
#endif
#ifndef WEB_SRC_RACK_TOTAL_T_DEFINED
typedef struct _web_src_rack_total_t web_src_rack_total_t;
#define WEB_SRC_RACK_TOTAL_T_DEFINED
#endif
#ifndef WEB_SRC_SCAN_PROGRESS_T_DEFINED
typedef struct _web_src_scan_progress_t web_src_scan_progress_t;
#define WEB_SRC_SCAN_PROGRESS_T_DEFINED
#endif
#ifndef WEB_SRC_SCAN_RUN_T_DEFINED
typedef struct _web_src_scan_run_t web_src_scan_run_t;
#define WEB_SRC_SCAN_RUN_T_DEFINED
#endif
#ifndef WEB_SRC_SECURITY_HEADERS_T_DEFINED
typedef struct _web_src_security_headers_t web_src_security_headers_t;
#define WEB_SRC_SECURITY_HEADERS_T_DEFINED
#endif
#ifndef WEB_SRC_SERVER_STATUS_T_DEFINED
typedef struct _web_src_server_status_t web_src_server_status_t;
#define WEB_SRC_SERVER_STATUS_T_DEFINED
#endif
#ifndef WEB_SRC_SSL_REDIRECT_T_DEFINED
typedef struct _web_src_ssl_redirect_t web_src_ssl_redirect_t;
#define WEB_SRC_SSL_REDIRECT_T_DEFINED
#endif
#ifndef WEB_SRC_SYSINFO_T_DEFINED
typedef struct _web_src_sysinfo_t web_src_sysinfo_t;
#define WEB_SRC_SYSINFO_T_DEFINED
#endif
#ifndef WEB_SRC_SYSTEMCTL_T_DEFINED
typedef struct _web_src_systemctl_t web_src_systemctl_t;
#define WEB_SRC_SYSTEMCTL_T_DEFINED
#endif
#ifndef WEB_SRC_TIME_T_DEFINED
typedef struct _web_src_time_t web_src_time_t;
#define WEB_SRC_TIME_T_DEFINED
#endif
#ifndef WEB_SRC_UPTIME_T_DEFINED
typedef struct _web_src_uptime_t web_src_uptime_t;
#define WEB_SRC_UPTIME_T_DEFINED
#endif
#ifndef WEB_SRC_TOPOLOGY_LOCATION_FROM2_T_DEFINED
typedef struct _web_src_topology_location_from2_t web_src_topology_location_from2_t;
#define WEB_SRC_TOPOLOGY_LOCATION_FROM2_T_DEFINED
#endif
#ifndef WEB_SRC_TOPOLOGY_LOCATION_FROM_T_DEFINED
typedef struct _web_src_topology_location_from_t web_src_topology_location_from_t;
#define WEB_SRC_TOPOLOGY_LOCATION_FROM_T_DEFINED
#endif
#ifndef WEB_SRC_TOPOLOGY_LOCATION_TO_T_DEFINED
typedef struct _web_src_topology_location_to_t web_src_topology_location_to_t;
#define WEB_SRC_TOPOLOGY_LOCATION_TO_T_DEFINED
#endif
#ifndef WEB_SRC_TOPOLOGY_POWER_T_DEFINED
typedef struct _web_src_topology_power_t web_src_topology_power_t;
#define WEB_SRC_TOPOLOGY_POWER_T_DEFINED
#endif
#ifndef WEB_SRC_ADMIN_PASSWD_T_DEFINED
typedef struct _web_src_admin_passwd_t web_src_admin_passwd_t;
#define WEB_SRC_ADMIN_PASSWD_T_DEFINED
#endif
#ifndef WEB_SRC_SECURITY_REMOVEHEADERS_T_DEFINED
typedef struct _web_src_security_removeheaders_t web_src_security_removeheaders_t;
#define WEB_SRC_SECURITY_REMOVEHEADERS_T_DEFINED
#endif
#ifndef WEB_SRC_HW_CAPABILITY_T_DEFINED
typedef struct _web_src_hw_capability_t web_src_hw_capability_t;
#define WEB_SRC_HW_CAPABILITY_T_DEFINED
#endif

//  Internal API

#include "db/agentstate/agentstate.h"
#include "db/asset_general.h"
#include "db/inout.h"
#include "db/inout/exportcsv.h"
#include "db/inout/importcsv.h"
#include "persist/assetcrud.h"
#include "persist/assettopology.h"
#include "persist/dbhelpers.h"
#include "persist/monitor.h"
#include "persist/persist_error.h"
#include "shared/magic.h"
#include "warranty/warranty_metric.h"
#include "web/src/add_gpio.h"
#include "web/src/admin_iface.h"
#include "web/src/admin_ifaces.h"
#include "web/src/admin_sse.h"
#include "web/src/alert_ack.h"
#include "web/src/alert_list.h"
#include "web/src/alert_rules_detail.h"
#include "web/src/alert_rules.h"
#include "web/src/alert_rules_list.h"
#include "web/src/asset_DELETE.h"
#include "web/src/asset_export.h"
#include "web/src/asset_GET.h"
#include "web/src/asset_import.h"
#include "web/src/asset_list.h"
#include "web/src/asset_POST.h"
#include "web/src/asset_PUT.h"
#include "web/src/assets_in.h"
#include "web/src/auth.h"
#include "web/src/auth_verify.h"
#include "web/src/average.h"
#include "web/src/config.h"
#include "web/src/conf_scan.h"
#include "web/src/current.h"
#include "web/src/datacenter_indicators.h"
#include "web/src/email_feedback.h"
#include "web/src/email_test.h"
#include "web/src/email_vote.h"
#include "web/src/getlog_GET.h"
#include "web/src/gpo_action.h"
#include "web/src/info.h"
#include "web/src/input_power_chain.h"
#include "web/src/json.h"
#include "web/src/license.h"
#include "web/src/license_POST.h"
#include "web/src/license_status.h"
#include "web/src/license_text.h"
#include "web/src/list_gpio.h"
#include "web/src/my_profile.h"
#include "web/src/netcfg.h"
#include "web/src/not_found.h"
#include "web/src/rack_total.h"
#include "web/src/scan_progress.h"
#include "web/src/scan_run.h"
#include "web/src/security_headers.h"
#include "web/src/server_status.h"
#include "web/src/ssl_redirect.h"
#include "web/src/sysinfo.h"
#include "web/src/systemctl.h"
#include "web/src/time.h"
#include "web/src/uptime.h"
#include "web/src/topology_location_from2.h"
#include "web/src/topology_location_from.h"
#include "web/src/topology_location_to.h"
#include "web/src/topology_power.h"
#include "web/src/admin_passwd.h"
#include "web/src/security_removeheaders.h"
#include "web/src/hw_capability.h"

//  *** To avoid double-definitions, only define if building without draft ***
#ifndef FTY_REST_BUILD_DRAFT_API

//  Self test for private classes
FTY_REST_PRIVATE void
    fty_rest_private_selftest (bool verbose);

#endif // FTY_REST_BUILD_DRAFT_API

#endif
