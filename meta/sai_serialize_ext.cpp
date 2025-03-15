#include "sai_serialize_ext.h"
#include "meta/sai_serialize.h"

std::string sai_serialize_ocs_cross_connect_attr(
    _In_ const sai_ocs_cross_connect_attr_t attr)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(attr, &sai_metadata_enum_sai_ocs_cross_connect_attr_t);
}

std::string sai_serialize_ocs_cross_connect_stat(
    _In_ const sai_ocs_cross_connect_stat_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_ocs_cross_connect_stat_t);
}

void sai_deserialize_ocs_cross_connect_attr(
    _In_ const std::string& s,
    _Out_ sai_ocs_cross_connect_attr_t& attr)
{
    SWSS_LOG_ENTER();

    sai_deserialize_enum(s, &sai_metadata_enum_sai_ocs_cross_connect_attr_t, (int32_t&)attr);
}

std::string sai_serialize_ocs_port_attr(
    _In_ const sai_ocs_port_attr_t attr)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(attr, &sai_metadata_enum_sai_ocs_port_attr_t);
}

std::string sai_serialize_ocs_port_stat(
    _In_ const sai_ocs_port_stat_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_ocs_port_stat_t);
}

void sai_deserialize_ocs_port_attr(
    _In_ const std::string& s,
    _Out_ sai_ocs_port_attr_t& attr)
{
    SWSS_LOG_ENTER();

    sai_deserialize_enum(s, &sai_metadata_enum_sai_ocs_port_attr_t, (int32_t&)attr);
}
