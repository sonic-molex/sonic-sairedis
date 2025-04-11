#include "otai_serialize.h"
#include "meta/sai_serialize.h"

std::string sai_serialize_otai_attenuator_attr(
        _In_ const sai_otai_attenuator_attr_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otai_attenuator_attr_t);
}

std::string sai_serialize_otai_attenuator_stat(
        _In_ const sai_otai_attenuator_stat_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otai_attenuator_stat_t);
}

void sai_deserialize_otai_attenuator_attr(
        _In_ const std::string& s,
        _Out_ sai_otai_attenuator_attr_t& attr)
{
    SWSS_LOG_ENTER();

    sai_deserialize_enum(s, &sai_metadata_enum_sai_otai_attenuator_attr_t, (int32_t&)attr);
}

std::string sai_serialize_otai_oa_attr(
        _In_ const sai_otai_oa_attr_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otai_oa_attr_t);
}

std::string sai_serialize_otai_oa_stat(
        _In_ const sai_otai_oa_stat_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otai_oa_stat_t);
}

void sai_deserialize_otai_oa_attr(
        _In_ const std::string& s,
        _Out_ sai_otai_oa_attr_t& attr)
{
    SWSS_LOG_ENTER();

    sai_deserialize_enum(s, &sai_metadata_enum_sai_otai_oa_attr_t, (int32_t&)attr);
}

std::string sai_serialize_otai_ocm_attr(
        _In_ const sai_otai_ocm_attr_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otai_ocm_attr_t);
}

std::string sai_serialize_otai_ocm_stat(
        _In_ const sai_otai_ocm_stat_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otai_ocm_stat_t);
}

void sai_deserialize_otai_ocm_attr(
        _In_ const std::string& s,
        _Out_ sai_otai_ocm_attr_t& attr)
{
    SWSS_LOG_ENTER();

    sai_deserialize_enum(s, &sai_metadata_enum_sai_otai_ocm_attr_t, (int32_t&)attr);
}


std::string sai_serialize_otai_ocm_channel_attr(
        _In_ const sai_otai_ocm_channel_attr_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otai_ocm_channel_attr_t);
}

std::string sai_serialize_otai_ocm_channel_stat(
        _In_ const sai_otai_ocm_channel_stat_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otai_ocm_channel_stat_t);
}

void sai_deserialize_otai_ocm_channel_attr(
        _In_ const std::string& s,
        _Out_ sai_otai_ocm_channel_attr_t& attr)
{
    SWSS_LOG_ENTER();

    sai_deserialize_enum(s, &sai_metadata_enum_sai_otai_ocm_channel_attr_t, (int32_t&)attr);
}

std::string sai_serialize_otai_osc_attr(
        _In_ const sai_otai_osc_attr_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otai_osc_attr_t);
}

std::string sai_serialize_otai_osc_stat(
        _In_ const sai_otai_osc_stat_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otai_osc_stat_t);
}

void sai_deserialize_otai_osc_attr(
        _In_ const std::string& s,
        _Out_ sai_otai_osc_attr_t& attr)
{
    SWSS_LOG_ENTER();

    sai_deserialize_enum(s, &sai_metadata_enum_sai_otai_osc_attr_t, (int32_t&)attr);
}

std::string sai_serialize_otai_otdr_attr(
        _In_ const sai_otai_otdr_attr_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otai_otdr_attr_t);
}

std::string sai_serialize_otai_otdr_stat(
        _In_ const sai_otai_otdr_stat_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otai_otdr_stat_t);
}

void sai_deserialize_otai_otdr_attr(
        _In_ const std::string& s,
        _Out_ sai_otai_otdr_attr_t& attr)
{
    SWSS_LOG_ENTER();

    sai_deserialize_enum(s, &sai_metadata_enum_sai_otai_otdr_attr_t, (int32_t&)attr);
}

std::string sai_serialize_otai_ocs_cross_connect_attr(
    _In_ const sai_otai_ocs_cross_connect_attr_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otai_ocs_cross_connect_attr_t);
}

std::string sai_serialize_otai_ocs_cross_connect_stat(
    _In_ const sai_otai_ocs_cross_connect_stat_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otai_ocs_cross_connect_stat_t);
}

void sai_deserialize_otai_ocs_cross_connect_attr(
    _In_ const std::string& s,
    _Out_ sai_otai_ocs_cross_connect_attr_t& attr)
{
    SWSS_LOG_ENTER();

    sai_deserialize_enum(s, &sai_metadata_enum_sai_otai_ocs_cross_connect_attr_t, (int32_t&)attr);
}