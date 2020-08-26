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

    void Packet::setHeaderRemaingLength(uint8_t len){
        pimpl->headerRemainingLength = len;
    }

    uint8_t Packet::getHeaderRemaingLength(){
        return pimpl->headerRemainingLength;
    }
} // namespace MQTT