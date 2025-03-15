#pragma once

extern "C" {
#include "sai.h"
#include "saimetadata.h"
}

#include <string>

// ocs cross connect
std::string sai_serialize_ocs_cross_connect_attr(
        _In_ const sai_ocs_cross_connect_attr_t attr);

std::string sai_serialize_ocs_cross_connect_stat(
        _In_ const sai_ocs_cross_connect_stat_t counter);

void sai_deserialize_ocs_cross_connect_attr(
        _In_ const std::string& s,
        _Out_ sai_ocs_cross_connect_attr_t& attr);

// ocs port
std::string sai_serialize_ocs_port_attr(
        _In_ const sai_ocs_port_attr_t attr);

std::string sai_serialize_ocs_port_stat(
        _In_ const sai_ocs_port_stat_t counter);

void sai_deserialize_ocs_port_attr(
        _In_ const std::string& s,
        _Out_ sai_ocs_port_attr_t& attr);
