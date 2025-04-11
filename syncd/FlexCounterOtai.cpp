#include "FlexCounterOtai.h"
#include "FlexCounter.h"

using namespace syncd;
using namespace std;


const std::string FlexCounterOtai::COUNTER_TYPE_ATTENUATOR_STATS = "Attenuator Stats Counter";
const std::string FlexCounterOtai::COUNTER_TYPE_OA_STATS = "OA Stats Counter";
const std::string FlexCounterOtai::COUNTER_TYPE_OCM_STATS = "OCM Stats Counter";
const std::string FlexCounterOtai::COUNTER_TYPE_OCM_CHANNEL_STATS = "OCM Channel Stats Counter";
const std::string FlexCounterOtai::COUNTER_TYPE_OSC_STATS = "OSC Stats Counter";
const std::string FlexCounterOtai::COUNTER_TYPE_OTDR_STATS = "OTDR Stats Counter";
const std::string FlexCounterOtai::COUNTER_TYPE_OCS_CROSS_CONNECT_STATS = "OCS Cross Connect Stats Counter";


FlexCounterOtai::FlexCounterOtai(
        std::function<std::shared_ptr<BaseCounterContext>(_In_ const std::string &name)> getCounterContext,
        std::function<bool(_In_ const std::string &name)> hasCounterContext):
m_getCounterContext(getCounterContext),
m_hasCounterContext(hasCounterContext)
{
    SWSS_LOG_ENTER();
}

FlexCounterOtai::~FlexCounterOtai()
{
    SWSS_LOG_ENTER();
}

bool FlexCounterOtai::addCounter(
        _In_ sai_object_id_t vid,
        _In_ sai_object_id_t rid,
        _In_ sai_object_type_t objectType,
        _In_ const std::string &field,
        _In_ const std::vector<std::string> &idStrings)
{
    SWSS_LOG_ENTER();

    sai_object_type_extensions_t extObjectType = (sai_object_type_extensions_t)objectType;
    if (extObjectType == SAI_OBJECT_TYPE_OTAI_ATTENUATOR && field == ATTENUATOR_COUNTER_STATS_LIST)
    {
        m_getCounterContext(COUNTER_TYPE_ATTENUATOR_STATS)->addObject(
                vid,
                rid,
                idStrings,
                "");
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTAI_OA && field == OA_COUNTER_STATS_LIST)
    {
        m_getCounterContext(COUNTER_TYPE_OA_STATS)->addObject(
                vid,
                rid,
                idStrings,
                "");
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTAI_OCM && field == OCM_COUNTER_STATS_LIST)
    {
        m_getCounterContext(COUNTER_TYPE_OCM_STATS)->addObject(
                vid,
                rid,
                idStrings,
                "");
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTAI_OCM_CHANNEL && field == OCM_CHANNEL_COUNTER_STATS_LIST)
    {
        m_getCounterContext(COUNTER_TYPE_OCM_CHANNEL_STATS)->addObject(
                vid,
                rid,
                idStrings,
                "");
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTAI_OSC && field == OSC_COUNTER_STATS_LIST)
    {
        m_getCounterContext(COUNTER_TYPE_OSC_STATS)->addObject(
                vid,
                rid,
                idStrings,
                "");
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTAI_OTDR && field == OTDR_COUNTER_STATS_LIST)
    {
        m_getCounterContext(COUNTER_TYPE_OTDR_STATS)->addObject(
                vid,
                rid,
                idStrings,
                "");
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTAI_OCS_CROSS_CONNECT && field == OCS_CROSS_CONNECT_COUNTER_STATS_LIST)
    {
        m_getCounterContext(COUNTER_TYPE_OCS_CROSS_CONNECT_STATS)->addObject(
                vid,
                rid,
                idStrings,
                "");
        return true;
    }

    return false;
}

bool FlexCounterOtai::removeCounter(
        _In_ sai_object_id_t vid,
        _In_ sai_object_type_t objectType)
{
    SWSS_LOG_ENTER();

    sai_object_type_extensions_t extObjectType = (sai_object_type_extensions_t)objectType;
    if (extObjectType == SAI_OBJECT_TYPE_OTAI_ATTENUATOR)
    {
        if (m_hasCounterContext(COUNTER_TYPE_ATTENUATOR_STATS))
        {
            m_getCounterContext(COUNTER_TYPE_ATTENUATOR_STATS)->removeObject(vid);
        }
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTAI_OA)
    {
        if (m_hasCounterContext(COUNTER_TYPE_OA_STATS))
        {
            m_getCounterContext(COUNTER_TYPE_OA_STATS)->removeObject(vid);
        }
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTAI_OCM)
    {
        if (m_hasCounterContext(COUNTER_TYPE_OCM_STATS))
        {
            m_getCounterContext(COUNTER_TYPE_OCM_STATS)->removeObject(vid);
        }
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTAI_OCM_CHANNEL)
    {
        if (m_hasCounterContext(COUNTER_TYPE_OCM_CHANNEL_STATS))
        {
            m_getCounterContext(COUNTER_TYPE_OCM_CHANNEL_STATS)->removeObject(vid);
        }
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTAI_OSC)
    {
        if (m_hasCounterContext(COUNTER_TYPE_OSC_STATS))
        {
            m_getCounterContext(COUNTER_TYPE_OSC_STATS)->removeObject(vid);
        }
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTAI_OTDR)
    {
        if (m_hasCounterContext(COUNTER_TYPE_OTDR_STATS))
        {
            m_getCounterContext(COUNTER_TYPE_OTDR_STATS)->removeObject(vid);
        }
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTAI_OCS_CROSS_CONNECT)
    {
        if (m_hasCounterContext(COUNTER_TYPE_OCS_CROSS_CONNECT_STATS))
        {
            m_getCounterContext(COUNTER_TYPE_OCS_CROSS_CONNECT_STATS)->removeObject(vid);
        }
        return true;
    }

    return false;
}

bool FlexCounterOtai::addCounterPlugin(
        _In_ const std::string &field,
        _In_ const std::vector<std::string> &shaStrings)
{
    SWSS_LOG_ENTER();

    if (field == ATTENUATOR_STATS_PLUGIN_FIELD)
    {
        m_getCounterContext(COUNTER_TYPE_ATTENUATOR_STATS)->addPlugins(shaStrings);
        return true;
    }

    if (field == OA_STATS_PLUGIN_FIELD)
    {
        m_getCounterContext(COUNTER_TYPE_OA_STATS)->addPlugins(shaStrings);
        return true;
    }

    if (field == OCM_STATS_PLUGIN_FIELD)
    {
        m_getCounterContext(COUNTER_TYPE_OCM_STATS)->addPlugins(shaStrings);
        return true;
    }

    if (field == OCM_CHANNEL_STATS_PLUGIN_FIELD)
    {
        m_getCounterContext(COUNTER_TYPE_OCM_CHANNEL_STATS)->addPlugins(shaStrings);
        return true;
    }

    if (field == OSC_STATS_PLUGIN_FIELD)
    {
        m_getCounterContext(COUNTER_TYPE_OSC_STATS)->addPlugins(shaStrings);
        return true;
    }

    if (field == OTDR_STATS_PLUGIN_FIELD)
    {
        m_getCounterContext(COUNTER_TYPE_OTDR_STATS)->addPlugins(shaStrings);
        return true;
    }

    if (field == OCS_CROSS_CONNECT_STATS_PLUGIN_FIELD)
    {
        m_getCounterContext(COUNTER_TYPE_OCS_CROSS_CONNECT_STATS)->addPlugins(shaStrings);
        return true;
    }

    return false;
}