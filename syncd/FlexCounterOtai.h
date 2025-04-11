#pragma once

extern "C" {
#include "sai.h"
}

#include "meta/SaiInterface.h"
#include "meta/otai_serialize.h"

#include <functional>
#include <memory>
#include <vector>

namespace syncd
{
    class BaseCounterContext;

    class FlexCounterOtai
    {
    public:
        FlexCounterOtai(
                std::function<std::shared_ptr<BaseCounterContext>(_In_ const std::string &name)> getCounterContext,
                std::function<bool(_In_ const std::string &name)> hasCounterContext);
        virtual ~FlexCounterOtai();

        bool addCounter(
                _In_ sai_object_id_t vid,
                _In_ sai_object_id_t rid,
                _In_ sai_object_type_t objectType,
                _In_ const std::string &field,
                _In_ const std::vector<std::string> &idStrings);

        bool removeCounter(
                _In_ sai_object_id_t vid,
                _In_ sai_object_type_t objectType);

        bool addCounterPlugin(
                _In_ const std::string &field,
                _In_ const std::vector<std::string> &shaStrings);

    public:
        static const std::string COUNTER_TYPE_ATTENUATOR_STATS;
        static const std::string COUNTER_TYPE_OA_STATS;
        static const std::string COUNTER_TYPE_OCM_STATS;
        static const std::string COUNTER_TYPE_OCM_CHANNEL_STATS;
        static const std::string COUNTER_TYPE_OSC_STATS;
        static const std::string COUNTER_TYPE_OTDR_STATS;
        static const std::string COUNTER_TYPE_OCS_CROSS_CONNECT_STATS;

    private:
        std::function<std::shared_ptr<BaseCounterContext>(_In_ const std::string &name)> m_getCounterContext;
        std::function<bool(_In_ const std::string &name)> m_hasCounterContext;
    };


    #define OTN_SPECIALIZATION_IMPLEMENT()                          \
    std::shared_ptr<BaseCounterContext> createOtaiCounterContext(   \
            _In_ const std::string &context_name,                   \
            _In_ std::shared_ptr<sairedis::SaiInterface> vendorSai, \
            _In_ sai_stats_mode_t statsMode)                        \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        if (context_name == FlexCounterOtai::COUNTER_TYPE_ATTENUATOR_STATS)\
        {                                                           \
            return std::make_shared<CounterContext<sai_otai_attenuator_stat_t>>(context_name, (sai_object_type_t)SAI_OBJECT_TYPE_OTAI_ATTENUATOR, vendorSai.get(), statsMode);\
        }                                                           \
                                                                    \
        if (context_name == FlexCounterOtai::COUNTER_TYPE_OA_STATS) \
        {                                                           \
            return std::make_shared<CounterContext<sai_otai_oa_stat_t>>(context_name, (sai_object_type_t)SAI_OBJECT_TYPE_OTAI_OA, vendorSai.get(), statsMode);\
        }                                                           \
                                                                    \
        if (context_name == FlexCounterOtai::COUNTER_TYPE_OCM_CHANNEL_STATS)\
        {                                                           \
            return std::make_shared<CounterContext<sai_otai_ocm_channel_stat_t>>(context_name, (sai_object_type_t)SAI_OBJECT_TYPE_OTAI_OCM_CHANNEL, vendorSai.get(), statsMode);\
        }                                                           \
                                                                    \
        if (context_name == FlexCounterOtai::COUNTER_TYPE_OSC_STATS)\
        {                                                           \
            return std::make_shared<CounterContext<sai_otai_osc_stat_t>>(context_name, (sai_object_type_t)SAI_OBJECT_TYPE_OTAI_OSC, vendorSai.get(), statsMode);\
        }                                                           \
                                                                    \
        if (context_name == FlexCounterOtai::COUNTER_TYPE_OCS_CROSS_CONNECT_STATS)\
        {                                                           \
            return std::make_shared<CounterContext<sai_otai_ocs_cross_connect_stat_t>>(context_name, (sai_object_type_t)SAI_OBJECT_TYPE_OTAI_OCS_CROSS_CONNECT, vendorSai.get(), statsMode);\
        }                                                           \
                                                                    \
        return nullptr;                                             \
    }                                                               \
                                                                    \
    template <>                                                     \
    std::string serializeStat(                                      \
            _In_ const sai_otai_attenuator_stat_t stat)             \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        return sai_serialize_otai_attenuator_stat(stat);            \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeStat(                                           \
            _In_ const char *name,                                  \
            _Out_ sai_otai_attenuator_stat_t *stat)                 \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
         sai_deserialize_otai_attenuator_stat(name, stat);          \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeAttr(                                           \
            _In_ const std::string &name,                           \
            _Out_ sai_otai_attenuator_attr_t &attr)                 \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        sai_deserialize_otai_attenuator_attr(name, attr);           \
    }                                                               \
                                                                    \
    template <>                                                     \
    std::string serializeStat(                                      \
            _In_ const sai_otai_oa_stat_t stat)                     \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        return sai_serialize_otai_oa_stat(stat);                    \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeStat(                                           \
            _In_ const char *name,                                  \
            _Out_ sai_otai_oa_stat_t *stat)                         \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
         sai_deserialize_otai_oa_stat(name, stat);                  \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeAttr(                                           \
            _In_ const std::string &name,                           \
            _Out_ sai_otai_oa_attr_t &attr)                         \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        sai_deserialize_otai_oa_attr(name, attr);                   \
    }                                                               \
                                                                    \
    template <>                                                     \
    std::string serializeStat(                                      \
            _In_ const sai_otai_ocm_channel_stat_t stat)            \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        return sai_serialize_otai_ocm_channel_stat(stat);           \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeStat(                                           \
            _In_ const char *name,                                  \
            _Out_ sai_otai_ocm_channel_stat_t *stat)                \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
         sai_deserialize_otai_ocm_channel_stat(name, stat);         \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeAttr(                                           \
            _In_ const std::string &name,                           \
            _Out_ sai_otai_ocm_channel_attr_t &attr)                \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        sai_deserialize_otai_ocm_channel_attr(name, attr);          \
    }                                                               \
                                                                    \
    template <>                                                     \
    std::string serializeStat(                                      \
            _In_ const sai_otai_osc_stat_t stat)                    \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        return sai_serialize_otai_osc_stat(stat);                   \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeStat(                                           \
            _In_ const char *name,                                  \
            _Out_ sai_otai_osc_stat_t *stat)                        \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
         sai_deserialize_otai_osc_stat(name, stat);                 \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeAttr(                                           \
            _In_ const std::string &name,                           \
            _Out_ sai_otai_osc_attr_t &attr)                        \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        sai_deserialize_otai_osc_attr(name, attr);                  \
    }                                                               \
                                                                    \
    template <>                                                     \
    std::string serializeStat(                                      \
            _In_ const sai_otai_ocs_cross_connect_stat_t stat)      \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        return sai_serialize_otai_ocs_cross_connect_stat(stat);     \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeStat(                                           \
            _In_ const char *name,                                  \
            _Out_ sai_otai_ocs_cross_connect_stat_t *stat)          \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
         sai_deserialize_otai_ocs_cross_connect_stat(name, stat);   \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeAttr(                                           \
            _In_ const std::string &name,                           \
            _Out_ sai_otai_ocs_cross_connect_attr_t &attr)          \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        sai_deserialize_otai_ocs_cross_connect_attr(name, attr);    \
    }

}