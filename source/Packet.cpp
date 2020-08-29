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
        Packet::ControlType controlType;
        uint8_t headerRemainingLength;
        bool dup;
        Packet::QOS qos;
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

    Packet::ControlType Packet::getControlType(){
        return pimpl->controlType;
    }

    void Packet::parseControlType(Packet::ControlType controlType){
        pimpl->controlType = controlType;
    }

    bool Packet::getDupFlag(){
        return pimpl->dup;
    }
    void Packet::parseDupFlag(bool dup){
        pimpl->dup = dup;
    }

    Packet::QOS Packet::getQOS(){
        return pimpl->qos;
    }
    void Packet::parseQOS(Packet::QOS qos){
        pimpl->qos = qos;
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

    uint8_t Packet::getHeaderRemaingLength(){
        return pimpl->headerRemainingLength;
    }

    std::shared_ptr<IVariableHeader> Packet::getVariableHeader(){
        return pimpl->variableHeader;
    }

    std::string Packet::parseStringField(uint8_t* buffer){
        return std::string((char*)&buffer[2], buffer[0] * 256 + buffer[1]);
    }


    void Packet::parseVariableHead(uint8_t* data, size_t len){
        if(len == 0) return;
        switch (getControlType())
        {
        case Packet::ControlType::CONNECT:
            {
                pimpl->variableHeader = std::make_shared<Connect>();
                auto varHeader = std::dynamic_pointer_cast<Connect>(pimpl->variableHeader);
                auto name = parseStringField(data);
                varHeader->setProtocolName(name);
                varHeader->setProtocolLevel(ProtocolVersion(data[name.length() + 2]));
                if (name == "MQTT") {
                    if (varHeader->getProtocolVersion() != ProtocolVersion::MQTT_3_1_1){
                        pimpl->valid = false;                        
                    }
                }else if (name == "MQISDP"){
                    if (varHeader->getProtocolVersion() != ProtocolVersion::MQTT_3_1){
                        pimpl->valid = false;                        
                    }
                }else{
                    //Invalid packet
                    pimpl->valid = false; 
                }
            }
            break;
        
        default:
            break;
        }
    }


} // namespace MQTT