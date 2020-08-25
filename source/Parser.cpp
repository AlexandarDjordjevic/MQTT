#include <MQTT/Parser.hpp>

namespace MQTT{
    /**
     * @brief Pimpl implementatio
     * 
     */
    struct Parser::impl
    {
        
    };
    
    /**
     * @brief Construct a new Parser::Parser object
     * 
     */
    Parser::Parser()
        : pimpl(new Parser::impl())
    {

    }
} // namespace MQTT