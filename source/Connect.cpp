#include <MQTT/Connect.hpp>

namespace MQTT{
    /**
     * @brief Pimpl implementatio
     * 
     */
    struct Connect::impl
    {
        std::string protocolName;
        std::string clientIdentifier;
        uint16_t keepAliveTimer;
        ProtocolVersion protocolVersion;
        Flags flags;
    };
    
    /**
     * @brief Construct a new Connect::Connect object
     * 
     */
    Connect::Connect()
        : pimpl(new Connect::impl())
    {
        pimpl->flags.CleanSession = true;
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

    void Connect::setFlags(uint8_t flags){
        pimpl->flags.CleanSession = (flags & 0x02) == 0x02;
        pimpl->flags.Willflag = (flags & 0x04) == 0x04;
        pimpl->flags.WillQoS = (flags & 0x18) >> 3;
        pimpl->flags.WillRETAIN = (flags & 0x20) == 0x20;
        pimpl->flags.Password = (flags & 0x40) == 0x40;
        pimpl->flags.Username = (flags & 0x80) == 0x80;
    }
    
    uint16_t Connect::getKeepAliveTimer() 
    {
        return pimpl->keepAliveTimer;
    }
    
    void Connect::setKeepAliveTimer(uint16_t keepAlive) 
    {
        pimpl->keepAliveTimer = keepAlive;
    }
    
    bool Connect::setClientIdentifier(std::string clientIdentifier) 
    {
        if (clientIdentifier.length() > 23) return false;
        pimpl->clientIdentifier = clientIdentifier;
        return true;
    }
    
    std::string Connect::getClientIdentifier() 
    {
        return pimpl->clientIdentifier;
    }

    bool Connect::getCleanSessionFlag(){
        return pimpl->flags.CleanSession;
    }
    
    bool Connect::getUsernameFlag(){
        return pimpl->flags.Username;
    }
    
    bool Connect::getPasswordFlag(){
        return pimpl->flags.Password;
    }
    
    bool Connect::getWillRetainFlag(){
        return pimpl->flags.WillRETAIN;
    }
    
    MQTT::QOS Connect::getWillQOS(){
        return MQTT::QOS(pimpl->flags.WillQoS);
    }
    
    bool Connect::getWillFlag(){
        return pimpl->flags.Willflag;
    }
    
    
} // namespace MQTT