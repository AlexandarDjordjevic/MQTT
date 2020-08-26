#include <MQTT/Parser.hpp>
#include <MQTT/Connect.hpp>
#include <string.h>

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

    std::string Parser::parseStringField(uint8_t* buffer){
        return std::string((char*)&buffer[2], buffer[0] * 256 + buffer[1]);
    }

    Packet* Parser::parse(const uint8_t* buffer, size_t len){
        Packet* packet = new Packet();
        packet->setControlType(MQTT::Packet::ControlType((buffer[0] & 0xf0) >> 4));
        packet->setDupFlag((buffer[0] & 0x08));
        packet->setQOS(MQTT::Packet::QOS((buffer[0] & 0x06) >> 1));
        packet->setRetain(buffer[0] & 0x01);
        packet->setHeaderRemaingLength(buffer[1]);
        packet->setProtocolName(parseStringField((uint8_t*)(&buffer[2])));
        return packet;
    }

    Packet* Parser::parse(const std::vector<uint8_t>& buffer){
        auto packet = parse((uint8_t*)buffer.data(), buffer.size());
        return packet;
    }
} // namespace MQTT