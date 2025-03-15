#pragma once

extern "C" {
#include "sai.h"
}

#include "meta/SaiInterface.h"
#include "meta/sai_serialize_ext.h"

#include <functional>
#include <memory>
#include <vector>

namespace syncd
{
    class BaseCounterContext;

    class FlexCounterExt
    {
    public:
        FlexCounterExt(
                std::function<std::shared_ptr<BaseCounterContext>(_In_ const std::string &name)> getCounterContext,
                std::function<bool(_In_ const std::string &name)> hasCounterContext);
        virtual ~FlexCounterExt();

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
        static const std::string COUNTER_TYPE_OCS_CROSS_CONNECT_STATS;
        static const std::string COUNTER_TYPE_OCS_PORT_STATS;
        static const std::string COUNTER_TYPE_OCS_CROSS_CONNECT_ATTRS;
        static const std::string COUNTER_TYPE_OCS_PORT_ATTRS;


    private:
        std::function<std::shared_ptr<BaseCounterContext>(_In_ const std::string &name)> m_getCounterContext;
        std::function<bool(_In_ const std::string &name)> m_hasCounterContext;
    };


    #define OTN_SPECIALIZATION_IMPLEMENT()                          \
    std::shared_ptr<BaseCounterContext> createExtCounterContext(   \
            _In_ const std::string &context_name,                   \
            _In_ std::shared_ptr<sairedis::SaiInterface> vendorSai, \
            _In_ sai_stats_mode_t statsMode)                        \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        if (context_name == FlexCounterExt::COUNTER_TYPE_OCS_CROSS_CONNECT_STATS)\
        {                                                           \
            return std::make_shared<CounterContext<sai_ocs_cross_connect_stat_t>>(context_name, (sai_object_type_t)SAI_OBJECT_TYPE_OCS_CROSS_CONNECT, vendorSai.get(), statsMode);\
        }                                                           \
                                                                    \
        if (context_name == FlexCounterExt::COUNTER_TYPE_OCS_PORT_STATS) \
        {                                                           \
            return std::make_shared<CounterContext<sai_ocs_port_stat_t>>(context_name, (sai_object_type_t)SAI_OBJECT_TYPE_OCS_PORT, vendorSai.get(), statsMode);\
        }                                                           \
                                                                    \
        if (context_name == FlexCounterExt::COUNTER_TYPE_OCS_CROSS_CONNECT_ATTRS)\
        {                                                           \
            return std::make_shared<AttrContext<sai_ocs_cross_connect_attr_t>>(context_name, (sai_object_type_t)SAI_OBJECT_TYPE_OCS_CROSS_CONNECT, vendorSai.get(), statsMode);\
        }                                                           \
                                                                    \
        if (context_name == FlexCounterExt::COUNTER_TYPE_OCS_PORT_ATTRS) \
        {                                                           \
            return std::make_shared<AttrContext<sai_ocs_port_attr_t>>(context_name, (sai_object_type_t)SAI_OBJECT_TYPE_OCS_PORT, vendorSai.get(), statsMode);\
        }                                                           \
                                                                    \
        return nullptr;                                             \
    }                                                               \
                                                                    \
    template <>                                                     \
    std::string serializeStat(                                      \
            _In_ const sai_ocs_cross_connect_stat_t stat)      \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        return sai_serialize_ocs_cross_connect_stat(stat);     \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeStat(                                           \
            _In_ const char *name,                                  \
            _Out_ sai_ocs_cross_connect_stat_t *stat)          \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
         sai_deserialize_ocs_cross_connect_stat(name, stat);   \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeAttr(                                           \
            _In_ const std::string &name,                           \
            _Out_ sai_ocs_cross_connect_attr_t &attr)          \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        sai_deserialize_ocs_cross_connect_attr(name, attr);    \
    }                                                               \
                                                                    \
    template <>                                                     \
    std::string serializeStat(                                      \
            _In_ const sai_ocs_port_stat_t stat)                \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        return sai_serialize_ocs_port_stat(stat);              \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeStat(                                           \
            _In_ const char *name,                                  \
            _Out_ sai_ocs_port_stat_t *stat)                   \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        sai_deserialize_ocs_port_stat(name, stat);             \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeAttr(                                           \
            _In_ const std::string &name,                           \
            _Out_ sai_ocs_port_attr_t &attr)                   \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        sai_deserialize_ocs_port_attr(name, attr);             \
    }
}
