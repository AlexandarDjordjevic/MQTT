#include <MQTT/Packet.hpp>

namespace MQTT{
    /**
     * @brief Pimpl implementatio
     * 
     */
    struct Packet::impl
    {
        Packet::ControlType controlType;
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
} // namespace MQTT