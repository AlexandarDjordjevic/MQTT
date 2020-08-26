#include <MQTT/Packet.hpp>
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
    };
    
    /**
     * @brief Construct a new Packet::Packet object
     * 
     */
    Packet::Packet()
        : pimpl(new Packet::impl())
    {

    }

    Packet::ControlType Packet::getControlType(){
        return pimpl->controlType;
    }

    void Packet::setControlType(Packet::ControlType controlType){
        pimpl->controlType = controlType;
    }

    bool Packet::getDupFlag(){
        return pimpl->dup;
    }
    void Packet::setDupFlag(bool dup){
        pimpl->dup = dup;
    }

    Packet::QOS Packet::getQOS(){
        return pimpl->qos;
    }
    void Packet::setQOS(Packet::QOS qos){
        pimpl->qos = qos;
    }

    bool Packet::getRetain(){
        return pimpl->retain;
    }
    void Packet::setRetain(bool retain){
        pimpl->retain = retain;
    }

    void Packet::setHeaderRemaingLength(uint8_t len){
        pimpl->headerRemainingLength = len;
    }

    uint8_t Packet::getHeaderRemaingLength(){
        return pimpl->headerRemainingLength;
    }
} // namespace MQTT