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

    std::shared_ptr<Packet> Parser::parse(const uint8_t* buffer, size_t len){
        std::shared_ptr<Packet> packet = std::make_shared<Packet>();
        if (len < 2) {
            packet->setInvalid();
            return packet;
        }

        packet->parseControlType(MQTT::Packet::ControlType((buffer[0] & 0xf0) >> 4));
        packet->parseDupFlag((buffer[0] & 0x08));
        packet->parseQOS(MQTT::Packet::QOS((buffer[0] & 0x06) >> 1));
        packet->parseRetain(buffer[0] & 0x01);
        packet->parseHeaderReminingLen(buffer[1]);

        if (len != (packet->getHeaderRemaingLength() + 2)){
            packet->setInvalid();
            return packet;
        }

        packet->parseVariableHead((uint8_t*)&buffer[2], packet->getHeaderRemaingLength());
        return packet;
    }

    std::shared_ptr<Packet> Parser::parse(const std::vector<uint8_t>& buffer){
        auto packet = parse((uint8_t*)buffer.data(), buffer.size());
        return packet;
    }
} // namespace MQTT