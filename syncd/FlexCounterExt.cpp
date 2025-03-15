#include "FlexCounterExt.h"
#include "FlexCounter.h"

using namespace syncd;


const std::string FlexCounterExt::COUNTER_TYPE_OCS_CROSS_CONNECT_STATS = "OCS Cross Connect Stats Counter";
const std::string FlexCounterExt::COUNTER_TYPE_OCS_PORT_STATS = "OCS Port Stats Counter";
const std::string FlexCounterExt::COUNTER_TYPE_OCS_CROSS_CONNECT_ATTRS = "OCS Cross Connect Attrs Counter";
const std::string FlexCounterExt::COUNTER_TYPE_OCS_PORT_ATTRS = "OCS Port Attrs Counter";


FlexCounterExt::FlexCounterExt(
        std::function<std::shared_ptr<BaseCounterContext>(_In_ const std::string &name)> getCounterContext,
        std::function<bool(_In_ const std::string &name)> hasCounterContext):
m_getCounterContext(getCounterContext),
m_hasCounterContext(hasCounterContext)
{
    SWSS_LOG_ENTER();
}

FlexCounterExt::~FlexCounterExt()
{
    SWSS_LOG_ENTER();
}

bool FlexCounterExt::addCounter(
        _In_ sai_object_id_t vid,
        _In_ sai_object_id_t rid,
        _In_ sai_object_type_t objectType,
        _In_ const std::string &field,
        _In_ const std::vector<std::string> &idStrings)
{
    SWSS_LOG_ENTER();

    sai_object_type_extensions_t extObjectType = (sai_object_type_extensions_t)objectType;

    if (extObjectType == SAI_OBJECT_TYPE_OCS_PORT && field == OCS_PORT_COUNTER_STATS_LIST)
    {
        m_getCounterContext(COUNTER_TYPE_OCS_PORT_STATS)->addObject(
                vid,
                rid,
                idStrings,
                "");
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OCS_PORT && field == OCS_PORT_COUNTER_ATTRS_LIST)
    {
        m_getCounterContext(COUNTER_TYPE_OCS_PORT_ATTRS)->addObject(
                vid,
                rid,
                idStrings,
                "");
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OCS_CROSS_CONNECT && field == OCS_CROSS_CONNECT_COUNTER_STATS_LIST)
    {
        m_getCounterContext(COUNTER_TYPE_OCS_CROSS_CONNECT_STATS)->addObject(
                vid,
                rid,
                idStrings,
                "");
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OCS_CROSS_CONNECT && field == OCS_CROSS_CONNECT_COUNTER_ATTRS_LIST)
    {
        m_getCounterContext(COUNTER_TYPE_OCS_CROSS_CONNECT_ATTRS)->addObject(
                vid,
                rid,
                idStrings,
                "");
        return true;
    }

    return false;
}

bool FlexCounterExt::removeCounter(
        _In_ sai_object_id_t vid,
        _In_ sai_object_type_t objectType)
{
    SWSS_LOG_ENTER();

    sai_object_type_extensions_t extObjectType = (sai_object_type_extensions_t)objectType;

    if (extObjectType == SAI_OBJECT_TYPE_OCS_PORT)
    {
        if (m_hasCounterContext(COUNTER_TYPE_OCS_PORT_STATS))
        {
            m_getCounterContext(COUNTER_TYPE_OCS_PORT_STATS)->removeObject(vid);
        }

        if (m_hasCounterContext(COUNTER_TYPE_OCS_PORT_ATTRS))
        {
            m_getCounterContext(COUNTER_TYPE_OCS_PORT_ATTRS)->removeObject(vid);

        }
    }

    if (extObjectType == SAI_OBJECT_TYPE_OCS_CROSS_CONNECT)
    {
        if (m_hasCounterContext(COUNTER_TYPE_OCS_CROSS_CONNECT_STATS))
        {
            m_getCounterContext(COUNTER_TYPE_OCS_CROSS_CONNECT_STATS)->removeObject(vid);
        }

        if (m_hasCounterContext(COUNTER_TYPE_OCS_CROSS_CONNECT_ATTRS))
        {
            m_getCounterContext(COUNTER_TYPE_OCS_CROSS_CONNECT_ATTRS)->removeObject(vid);
        }
    }

    return true;
}

bool FlexCounterExt::addCounterPlugin(
        _In_ const std::string &field,
        _In_ const std::vector<std::string> &shaStrings)
{
    SWSS_LOG_ENTER();

    if (field == OCS_PORT_STATS_PLUGIN_FIELD)
    {
        m_getCounterContext(COUNTER_TYPE_OCS_PORT_STATS)->addPlugins(shaStrings);
        return true;
    }

    if (field == OCS_PORT_ATTRS_PLUGIN_FIELD)
    {
        m_getCounterContext(COUNTER_TYPE_OCS_PORT_ATTRS)->addPlugins(shaStrings);
        return true;
    }

    if (field == OCS_CROSS_CONNECT_STATS_PLUGIN_FIELD)
    {
        m_getCounterContext(COUNTER_TYPE_OCS_CROSS_CONNECT_STATS)->addPlugins(shaStrings);
        return true;
    }

    if (field == OCS_CROSS_CONNECT_ATTRS_PLUGIN_FIELD)
    {
        m_getCounterContext(COUNTER_TYPE_OCS_CROSS_CONNECT_ATTRS)->addPlugins(shaStrings);
        return true;
    }

    return false;
}
