#include <MQTT/Connect.hpp>

namespace MQTT{
    /**
     * @brief Pimpl implementatio
     * 
     */
    struct Connect::impl
    {
        bool cleanSession;
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
    
    bool Connect::getCleanSession(){
        return pimpl->cleanSession;
    }
} // namespace MQTT