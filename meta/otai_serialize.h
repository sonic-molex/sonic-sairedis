#pragma once

extern "C" {
#include "sai.h"
#include "saimetadata.h"
}

#include <string>

// attenuator
std::string sai_serialize_otai_attenuator_attr(
        _In_ const sai_otai_attenuator_attr_t counter);

std::string sai_serialize_otai_attenuator_stat(
        _In_ const sai_otai_attenuator_stat_t counter);

void sai_deserialize_otai_attenuator_attr(
        _In_ const std::string& s,
        _Out_ sai_otai_attenuator_attr_t& attr);

// oa
std::string sai_serialize_otai_otdr_attr(
        _In_ const sai_otai_oa_attr_t counter);

std::string sai_serialize_otai_oa_stat(
        _In_ const sai_otai_oa_stat_t counter);

void sai_deserialize_otai_oa_attr(
        _In_ const std::string& s,
        _Out_ sai_otai_oa_attr_t& attr);

// ocm
std::string sai_serialize_otai_ocm_attr(
        _In_ const sai_otai_ocm_attr_t counter);

std::string sai_serialize_otai_ocm_stat(
        _In_ const sai_otai_ocm_stat_t counter);

void sai_deserialize_otai_ocm_attr(
        _In_ const std::string& s,
        _Out_ sai_otai_ocm_attr_t& attr);

// ocm channel
std::string sai_serialize_otai_ocm_channel_attr(
        _In_ const sai_otai_ocm_channel_attr_t counter);

std::string sai_serialize_otai_ocm_channel_stat(
        _In_ const sai_otai_ocm_channel_stat_t counter);

void sai_deserialize_otai_ocm_channel_attr(
        _In_ const std::string& s,
        _Out_ sai_otai_ocm_channel_attr_t& attr);

// osc
std::string sai_serialize_otai_osc_attr(
        _In_ const sai_otai_osc_attr_t counter);

std::string sai_serialize_otai_osc_stat(
        _In_ const sai_otai_osc_stat_t counter);

void sai_deserialize_otai_osc_attr(
        _In_ const std::string& s,
        _Out_ sai_otai_osc_attr_t& attr);

// otdr
std::string sai_serialize_otai_otdr_attr(
        _In_ const sai_otai_otdr_attr_t counter);

std::string sai_serialize_otai_otdr_stat(
        _In_ const sai_otai_otdr_stat_t counter);

void sai_deserialize_otai_otdr_attr(
        _In_ const std::string& s,
        _Out_ sai_otai_otdr_attr_t& attr);

// ocs cross connect
std::string sai_serialize_otai_ocs_cross_connect_attr(
        _In_ const sai_otai_ocs_cross_connect_attr_t counter);

std::string sai_serialize_otai_ocs_cross_connect_stat(
        _In_ const sai_otai_ocs_cross_connect_stat_t counter);

void sai_deserialize_otai_ocs_cross_connect_attr(
        _In_ const std::string& s,
        _Out_ sai_otai_ocs_cross_connect_attr_t& attr);