#include <MQTT/Parser.hpp>
#include <MQTT/Connect.hpp>

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

    Packet* Parser::parse(const uint8_t* buffer, size_t len){
        Packet* packet = new Packet();
        packet->setControlType(MQTT::Packet::ControlType((buffer[0] & 0xf0) >> 4));
        return packet;
    }

    Packet* Parser::parse(const std::vector<uint8_t>& buffer){
        Packet* packet = new Packet();
        packet->setControlType(MQTT::Packet::ControlType((buffer[0] & 0xf0) >> 4));
        return packet;
    }
} // namespace MQTT