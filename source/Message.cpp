#include <MQTT/Message.hpp>

namespace MQTT{
    /**
     * @brief Pimpl implementatio
     * 
     */
    struct Message::impl
    {
        
    };
    
    /**
     * @brief Construct a new Message::Message object
     * 
     */
    Message::Message()
        : pimpl(new Message::impl())
    {

    }
} // namespace MQTT