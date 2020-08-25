#include <MQTT/Packet.hpp>

namespace MQTT{
    /**
     * @brief Pimpl implementatio
     * 
     */
    struct Packet::impl
    {
        
    };
    
    /**
     * @brief Construct a new Packet::Packet object
     * 
     */
    Packet::Packet()
        : pimpl(new Packet::impl())
    {

    }
} // namespace MQTT