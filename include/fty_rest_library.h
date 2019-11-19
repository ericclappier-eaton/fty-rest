/*  =========================================================================
    fty-rest - generated layer of public API

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

#ifndef FTY_REST_LIBRARY_H_INCLUDED
#define FTY_REST_LIBRARY_H_INCLUDED

//  Set up environment for the application

//  External dependencies
#include <czmq.h>
#include <libcidr.h>
#include <cxxtools/allocator.h>
#include <tnt/tntnet.h>
#include <tntdb.h>
#if defined (HAVE_LIBMAGIC)
#include <magic.h>
#endif
#include <fty_log.h>
#include <fty_common.h>
#include <fty_common_db.h>
#include <fty_common_rest.h>
#include <fty_common_mlm.h>
#include <sasl/sasl.h>
#include <ftyproto.h>
#include <fty_shm.h>
#include <fty_asset_activator.h>
#include <fty_common_messagebus.h>
#include <fty_common_dto.h>

//  FTY_REST version macros for compile-time API detection
#define FTY_REST_VERSION_MAJOR 1
#define FTY_REST_VERSION_MINOR 0
#define FTY_REST_VERSION_PATCH 0

#define FTY_REST_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define FTY_REST_VERSION \
    FTY_REST_MAKE_VERSION(FTY_REST_VERSION_MAJOR, FTY_REST_VERSION_MINOR, FTY_REST_VERSION_PATCH)

#if defined (__WINDOWS__)
#   if defined FTY_REST_STATIC
#       define FTY_REST_EXPORT
#   elif defined FTY_REST_INTERNAL_BUILD
#       if defined DLL_EXPORT
#           define FTY_REST_EXPORT __declspec(dllexport)
#       else
#           define FTY_REST_EXPORT
#       endif
#   elif defined FTY_REST_EXPORTS
#       define FTY_REST_EXPORT __declspec(dllexport)
#   else
#       define FTY_REST_EXPORT __declspec(dllimport)
#   endif
#   define FTY_REST_PRIVATE
#elif defined (__CYGWIN__)
#   define FTY_REST_EXPORT
#   define FTY_REST_PRIVATE
#else
#   if (defined __GNUC__ && __GNUC__ >= 4) || defined __INTEL_COMPILER
#       define FTY_REST_PRIVATE __attribute__ ((visibility ("hidden")))
#       define FTY_REST_EXPORT __attribute__ ((visibility ("default")))
#   else
#       define FTY_REST_PRIVATE
#       define FTY_REST_EXPORT
#   endif
#endif

//  Project has no stable classes, so we build the draft API
#undef  FTY_REST_BUILD_DRAFT_API
#define FTY_REST_BUILD_DRAFT_API

//  Opaque class structures to allow forward references
//  These classes are stable or legacy and built in all releases
//  Draft classes are by default not built in stable releases
#ifdef FTY_REST_BUILD_DRAFT_API
typedef struct _shared_augtool_t shared_augtool_t;
#define SHARED_AUGTOOL_T_DEFINED
typedef struct _shared_cidr_t shared_cidr_t;
#define SHARED_CIDR_T_DEFINED
typedef struct _shared_configure_inform_t shared_configure_inform_t;
#define SHARED_CONFIGURE_INFORM_T_DEFINED
typedef struct _shared_csv_t shared_csv_t;
#define SHARED_CSV_T_DEFINED
typedef struct _shared_data_t shared_data_t;
#define SHARED_DATA_T_DEFINED
typedef struct _shared_ic_t shared_ic_t;
#define SHARED_IC_T_DEFINED
typedef struct _shared_topic_cache_t shared_topic_cache_t;
#define SHARED_TOPIC_CACHE_T_DEFINED
typedef struct _shared_upsstatus_t shared_upsstatus_t;
#define SHARED_UPSSTATUS_T_DEFINED
typedef struct _shared_utils_t shared_utils_t;
#define SHARED_UTILS_T_DEFINED
typedef struct _shared_utilspp_t shared_utilspp_t;
#define SHARED_UTILSPP_T_DEFINED
typedef struct _shared_utils_json_t shared_utils_json_t;
#define SHARED_UTILS_JSON_T_DEFINED
typedef struct _web_src_asset_computed_impl_t web_src_asset_computed_impl_t;
#define WEB_SRC_ASSET_COMPUTED_IMPL_T_DEFINED
typedef struct _web_src_iface_t web_src_iface_t;
#define WEB_SRC_IFACE_T_DEFINED
typedef struct _web_src_sse_t web_src_sse_t;
#define WEB_SRC_SSE_T_DEFINED
#endif // FTY_REST_BUILD_DRAFT_API


//  Public classes, each with its own header file
#include "app.h"
#include "bios_agent.h"
#include "bios_agentpp.h"
#include "bios_export.h"
#include "ymsg.h"
#include "bios_magic.h"
#include "cleanup.h"
#include "dbtypes.h"
#include "preproc.h"
#include "db/dbhelpers.h"
#include "db/types.h"
#ifdef FTY_REST_BUILD_DRAFT_API
#include "shared/augtool.h"
#include "shared/cidr.h"
#include "shared/configure_inform.h"
#include "shared/csv.h"
#include "shared/data.h"
#include "shared/ic.h"
#include "shared/topic_cache.h"
#include "shared/upsstatus.h"
#include "shared/utils.h"
#include "shared/utilspp.h"
#include "shared/utils_json.h"
#include "web/src/asset_computed_impl.h"
#include "web/src/iface.h"
#include "web/src/sse.h"
#endif // FTY_REST_BUILD_DRAFT_API

#ifdef FTY_REST_BUILD_DRAFT_API

#ifdef __cplusplus
extern "C" {
#endif

//  Self test for private classes
FTY_REST_EXPORT void
    fty_rest_private_selftest (bool verbose, const char *subtest);

#ifdef __cplusplus
}
#endif
#endif // FTY_REST_BUILD_DRAFT_API

#endif
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
