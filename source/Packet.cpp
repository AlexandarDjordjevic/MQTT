#include <MQTT/Packet.hpp>
#include <MQTT/Connect.hpp>
#include <string.h>
namespace MQTT{
    /**
     * @brief Pimpl implementation
     * 
     */
    struct Packet::impl
    {
        FixedHeader fixedHeader;
        uint8_t headerRemainingLength;
        bool dup;
        bool retain;
        std::string protocolName;
        std::shared_ptr<IVariableHeader> variableHeader;
        bool valid;
    };
    
    /**
     * @brief Construct a new Packet::Packet object
     * 
     */
    Packet::Packet()
        : pimpl(new Packet::impl())
    {
        pimpl->valid = true;
    }

    Packet::~Packet(){
        
    }
    
    bool Packet::isValid(){
        return pimpl->valid;
    }

    void Packet::setInvalid(){
        pimpl->valid = false;
    }

    ControlType Packet::getControlType(){
        return pimpl->fixedHeader.getControlType();
    }

    bool Packet::getDupFlag(){
        return pimpl->dup;
    }
    void Packet::parseDupFlag(bool dup){
        pimpl->dup = dup;
    }

    QOS Packet::getQOS(){
        return pimpl->fixedHeader.getQOS();
    }

    bool Packet::getRetain(){
        return pimpl->retain;
    }

    void Packet::parseRetain(bool retain){
        pimpl->retain = retain;
    }

    void Packet::parseHeaderReminingLen(uint8_t len){
        pimpl->headerRemainingLength = len;
    }

    size_t Packet::getHeaderRemaingLength(){
        return pimpl->fixedHeader.getRemainingLength();
    }

    std::shared_ptr<IVariableHeader> Packet::getVariableHeader(){
        return pimpl->variableHeader;
    }

    std::string Packet::parseStringField(uint8_t* buffer){
        return std::string((char*)&buffer[2], buffer[0] * 256 + buffer[1]);
    }


    void Packet::parseVariableHeader(uint8_t* data, size_t len){
        if(len == 0) return;
        switch (getControlType())
        {
            case ControlType::CONNECT:
                {
                    pimpl->variableHeader = std::make_shared<Connect>();
                    auto varHeader = std::dynamic_pointer_cast<Connect>(pimpl->variableHeader);
                    auto name = parseStringField(data);
                    varHeader->setProtocolName(name);
                    varHeader->setProtocolLevel(ProtocolVersion(data[name.length() + 2]));
                    if (name == "MQTT") {
                        if (varHeader->getProtocolVersion() != ProtocolVersion::MQTT_3_1_1){
                            pimpl->valid = false;  
                            return;                      
                        }
                    }else if (name == "MQISDP"){
                        if (varHeader->getProtocolVersion() != ProtocolVersion::MQTT_3_1){
                            pimpl->valid = false;
                            return;                        
                        }
                    }else{
                        //Invalid packet
                        pimpl->valid = false;
                        return;
                    }
                    varHeader->setFlags(data[name.length() + 3]);
                    varHeader->setKeepAliveTimer(uint16_t(data[name.length() + 4] * 256 + data[name.length() + 5]));
                    size_t clientIdLen = data[name.length() + 6] * 256 + data[name.length() + 7];
                    if (varHeader->setClientIdentifier(std::string((char*)&data[name.length() + 8], clientIdLen)) == false){
                        pimpl->valid = false;
                        return;
                    }
                }
                break;
        
        default:
            break;
        }
    }
    
    bool Packet::parseFixedHeader(const uint8_t* buffer) 
    {
        pimpl->fixedHeader.setControlType(MQTT::ControlType((buffer[0] & 0xf0) >> 4));
        pimpl->fixedHeader.setFlags(buffer[0] & 0x0f);
        pimpl->fixedHeader.setRemainingLength(&buffer[1]);
        return true;
    }


} // namespace MQTT