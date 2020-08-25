#include <MQTT/MQTT.hpp>

namespace MQTT{
    /**
     * @brief Pimpl implementatio
     * 
     */
    struct MQTT::impl
    {
        
    };
    
    /**
     * @brief Construct a new MQTT::MQTT object
     * 
     */
    MQTT::MQTT()
        : pimpl(new MQTT::impl())
    {

    }
}