#include <MQTT/Connect.hpp>

namespace MQTT{
    /**
     * @brief Pimpl implementatio
     * 
     */
    struct Connect::impl
    {
        bool cleanSession;
        std::string protocolName;
        ProtocolVersion protocolVersion;
    };
    
    /**
     * @brief Construct a new Connect::Connect object
     * 
     */
    Connect::Connect()
        : pimpl(new Connect::impl())
    {
        pimpl->cleanSession = true;
    }
    
    Connect::~Connect(){};

    std::string Connect::getProtocolName(){
        return pimpl->protocolName;
    }

    void Connect::setProtocolName(std::string protocolName){
        pimpl->protocolName = protocolName;
    }

    ProtocolVersion Connect::getProtocolVersion(){
        return pimpl->protocolVersion;
    }

    void Connect::setProtocolLevel(ProtocolVersion level){
        pimpl->protocolVersion = level;
    }

    bool Connect::getCleanSession(){
        return pimpl->cleanSession;
    }
} // namespace MQTT