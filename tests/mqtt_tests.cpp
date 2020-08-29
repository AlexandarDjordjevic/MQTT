#include <gtest/gtest.h>
#include <MQTT/Packet.hpp>
#include <MQTT/Parser.hpp>
#include <MQTT/Connect.hpp>

/*
https://public.dhe.ibm.com/software/dw/webservices/ws-mqtt/mqtt-v3r1.html
http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/os/mqtt-v3.1.1-os.html#_Toc398718009

The Packet header for each MQTT command Packet contains a fixed header. The table below shows the fixed header format.

bit         |   7 6 5 4     |       3       |       2	1   |   0
----------------------------------------------------------------------
byte 1      | Packet Type   |   DUP flag    |   QoS level   |	RETAIN
byte 2      |             Remaining Length
----------------------------------------------------------------------
Byte 1
Contains the Packet Type and Flags (DUP, QoS level, and RETAIN) fields.

Byte 2
(At least one byte) contains the Remaining Length field. -----> Depends on Packet type!
*/

namespace Packet
{
    const uint8_t Connect[] = 
    {
        //CONNECT fixed header
        0x10, //Control type 1 - Connect
        0x10, // Remaining length 
        //CONNECT variable header
        0x00, //Length MSB
        0x04, //Length LSB 
        'M',
        'Q',
        'T',
        'T',
        //Protocol level
        0x04,
        //CONNECT Flags
        0x02,
        //Keep alive 
        0x0, //Keep alive MSB
        0x3c, //Keep alvie LSB 60 sec
        //Client ID
        0x0, //Length MSB
        0x04, //Length LSB (4)
        'T',
        'E',
        'S',
        'T'
    };

    //in MQTT 3.1 Protocol name is MQISDP
    const uint8_t Connect_V3_1[] = 
    {
        //CONNECT fixed header
        0x10, //Control type 1 - Connect
        0x12, // Remaining length 
        //CONNECT variable header
        0x00, //Length MSB
        0x06, //Length LSB 
        'M',
        'Q',
        'I',
        'S',
        'D',
        'P',
        //Protocol level
        0x04,
        //CONNECT Flags
        0x02,
        //Keep alive 
        0x0, //Keep alive MSB
        0x3c, //Keep alvie LSB 60 sec
        //Client ID
        0x0, //Length MSB
        0x04, //Length LSB (4)
        'T',
        'E',
        'S',
        'T'
    };

    const uint8_t ConnACK[] = 
    {
        0x20,  0x02, 0x00, 0x00
    };

    const uint8_t PingRequest[] = 
    {
        0xC0, 00
    };

    const uint8_t PingResponse[] = 
    {
        0xd0, 00
    };

    const uint8_t SubscribeRequstQOS0[] = 
    {
        0x80, 0x11, 0x00, 0x01, 0x00, 0x0c, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6b, 0x69, 0x74, 0x63, 0x68, 0x65, 0x6e, 0x00
    };

    const uint8_t SubscribeRequstQOS1[] = 
    {
        0x82, 0x11, 0x00, 0x01, 0x00, 0x0c, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6b, 0x69, 0x74, 0x63, 0x68, 0x65, 0x6e, 0x00
    };

    const uint8_t SubscribeRequstQOS2[] = 
    {
        0x84, 0x11, 0x00, 0x01, 0x00, 0x0c, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6b, 0x69, 0x74, 0x63, 0x68, 0x65, 0x6e, 0x00
    };

    const uint8_t SubscribeACK[] = 
    {
        0x90, 0x03, 0x00, 0x01, 0x00
    };
      
    const uint8_t Publish[] = 
    {
        0x30, 0x22, 0x00, 0x14, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x67, 0x61, 0x72, 0x64, 0x65, 0x6e, 0x2f, 0x66, 0x6f, 
        0x75, 0x6e, 0x74, 0x61, 0x69, 0x6e, 0x74, 0x65, 0x73, 0x74, 0x20, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65
    };

    const uint8_t PublishDuplicate[] = 
    {
        0x38, 0x22, 0x00, 0x14, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x67, 0x61, 0x72, 0x64, 0x65, 0x6e, 0x2f, 0x66, 0x6f, 
        0x75, 0x6e, 0x74, 0x61, 0x69, 0x6e, 0x74, 0x65, 0x73, 0x74, 0x20, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65
    };

    const uint8_t PublishRetain[] = 
    {
        0x31, 0x20, 0x00, 0x14, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x67, 0x61, 0x72, 0x64, 0x65, 0x6e, 0x2f, 0x66, 0x6f, 
        0x75, 0x6e, 0x74, 0x61, 0x69, 0x6e, 0x54, 0x65, 0x73, 0x74, 0x20, 0x73, 0x68, 0x69, 0x74, 0x0a
    };
        

    const uint8_t PublishACK[] = 
    {
        0x40, 0x02, 0x00, 0x01
    };

    const uint8_t PublishRecv[] = 
    {
        0x50, 0x02, 0x00, 0x03
    };

    const uint8_t PublishRelease[] =
    {
        0x62, 0x02, 0x00, 0x03
    };
    
    const uint8_t PublishComplete[] =
    {
        0x70, 0x02, 0x00, 0x03
    };
    
    const uint8_t Unsubscribe[] =
    {
        0xa2, 0x18, 0x00, 0x04, 0x00, 0x14, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x67, 0x61, 0x72, 0x64, 0x65, 0x6e, 0x2f, 0x66,
        0x6f, 0x75, 0x6e, 0x74, 0x61, 0x69, 0x6e

    };
    
    const uint8_t UnsubscribeACK[] =
    {
        0xb0, 0x02, 0x00, 0x04
    };
    

    const uint8_t Disconnect[] = 
    {
        0xe0, 0
    };
} // namespace Packet



TEST(ParseFixedHeaderControlType, CONNECT){
    auto packet = MQTT::Parser::parse(Packet::Connect, sizeof(Packet::Connect));
    ASSERT_EQ(packet->getControlType(), MQTT::Packet::ControlType::CONNECT);
    ASSERT_EQ(packet->getHeaderRemaingLength(), Packet::Connect[1]);
}

TEST(ParseFixedHeaderControlType, CONNACK){
    auto packet = MQTT::Parser::parse(Packet::ConnACK, sizeof(Packet::ConnACK));
    ASSERT_EQ(packet->getControlType(), MQTT::Packet::ControlType::CONNACK);
    ASSERT_EQ(packet->getHeaderRemaingLength(), Packet::ConnACK[1]);
}

TEST(ParseFixedHeaderControlType, PINGREQ){
    auto packet = MQTT::Parser::parse(Packet::PingRequest, sizeof(Packet::PingRequest));
    ASSERT_EQ(packet->getControlType(), MQTT::Packet::ControlType::PINGREQ);
    ASSERT_EQ(packet->getHeaderRemaingLength(), Packet::PingRequest[1]);
}

TEST(ParseFixedHeaderControlType, PINGRESP){
    auto packet = MQTT::Parser::parse(Packet::PingResponse, sizeof(Packet::PingResponse));
    ASSERT_EQ(packet->getControlType(), MQTT::Packet::ControlType::PINGRESP);
    ASSERT_EQ(packet->getHeaderRemaingLength(), Packet::PingResponse[1]);
}

TEST(ParseFixedHeaderControlType, SUBSCRIBE){
    auto packet = MQTT::Parser::parse(Packet::SubscribeRequstQOS0, sizeof(Packet::SubscribeRequstQOS0));
    ASSERT_EQ(packet->getControlType(), MQTT::Packet::ControlType::SUBSCRIBE);
    ASSERT_EQ(packet->getHeaderRemaingLength(), Packet::SubscribeRequstQOS0[1]);
}

TEST(ParseFixedHeaderControlType, SUBACK){
    auto packet = MQTT::Parser::parse(Packet::SubscribeACK, sizeof(Packet::SubscribeACK));
    ASSERT_EQ(packet->getControlType(), MQTT::Packet::ControlType::SUBACK);
    ASSERT_EQ(packet->getHeaderRemaingLength(), Packet::SubscribeACK[1]);
}

TEST(ParseFixedHeaderControlType, PUBLISH){
    auto packet = MQTT::Parser::parse(Packet::Publish, sizeof(Packet::Publish));
    ASSERT_EQ(packet->getControlType(), MQTT::Packet::ControlType::PUBLISH);
    ASSERT_EQ(packet->getHeaderRemaingLength(), Packet::Publish[1]);
}

TEST(ParseFixedHeaderControlType, PUBLISHACK){
    auto packet = MQTT::Parser::parse(Packet::PublishACK, sizeof(Packet::PublishACK));
    ASSERT_EQ(packet->getControlType(), MQTT::Packet::ControlType::PUBACK);
    ASSERT_EQ(packet->getHeaderRemaingLength(), Packet::PublishACK[1]);
}

TEST(ParseFixedHeaderControlType, PUBLISRCV){
    auto packet = MQTT::Parser::parse(Packet::PublishRecv, sizeof(Packet::PublishRecv));
    ASSERT_EQ(packet->getControlType(), MQTT::Packet::ControlType::PUBREC);
    ASSERT_EQ(packet->getHeaderRemaingLength(), Packet::PublishRecv[1]);
}

TEST(ParseFixedHeaderControlType, PUBLISHRELEASE){
    auto packet = MQTT::Parser::parse(Packet::PublishRelease, sizeof(Packet::PublishRelease));
    ASSERT_EQ(packet->getControlType(), MQTT::Packet::ControlType::PUBREL);
    ASSERT_EQ(packet->getHeaderRemaingLength(), Packet::PublishRelease[1]);
}

TEST(ParseFixedHeaderControlType, PUBLISHCOMPLETE){
    auto packet = MQTT::Parser::parse(Packet::PublishComplete, sizeof(Packet::PublishComplete));
    ASSERT_EQ(packet->getControlType(), MQTT::Packet::ControlType::PUBCOMP);
    ASSERT_EQ(packet->getHeaderRemaingLength(), Packet::PublishComplete[1]);
}

TEST(ParseFixedHeaderControlType, UNSUBSCRIBE){
    auto packet = MQTT::Parser::parse(Packet::Unsubscribe, sizeof(Packet::Unsubscribe));
    ASSERT_EQ(packet->getControlType(), MQTT::Packet::ControlType::UNSUBSCRIBE);
    ASSERT_EQ(packet->getHeaderRemaingLength(), Packet::Unsubscribe[1]);
}

TEST(ParseFixedHeaderControlType, UNSUBSCIBEACK){
    auto packet = MQTT::Parser::parse(Packet::UnsubscribeACK, sizeof(Packet::UnsubscribeACK));
    ASSERT_EQ(packet->getControlType(), MQTT::Packet::ControlType::UNSUBACK);
    ASSERT_EQ(packet->getHeaderRemaingLength(), Packet::UnsubscribeACK[1]);
}

TEST(ParseFixedHeaderControlType, DISCONNECT){
    auto packet = MQTT::Parser::parse(Packet::Disconnect, sizeof(Packet::Disconnect));
    ASSERT_EQ(packet->getControlType(), MQTT::Packet::ControlType::DISCONNECT);
    ASSERT_EQ(packet->getHeaderRemaingLength(), Packet::Disconnect[1]);
}

TEST(ParseFixedHeaderDuplicateFlag, DUP_FLAG_FALSE){
    auto packet = MQTT::Parser::parse(Packet::Publish, sizeof(Packet::Publish));
    ASSERT_FALSE(packet->getDupFlag());
}

TEST(ParseFixedHeaderDuplicateFlag, DUP_FLAG_TRUE){
    auto packet = MQTT::Parser::parse(Packet::Publish, sizeof(Packet::PublishDuplicate));
    ASSERT_FALSE(packet->getDupFlag());
}

TEST(ParseFixedHeaderQOS, QOS0){
    auto packet = MQTT::Parser::parse(Packet::Publish, sizeof(Packet::Publish));
    ASSERT_EQ(packet->getQOS(), MQTT::Packet::QOS::QOS0);
}

TEST(ParseFixedHeaderQOS, QOS1){
    auto packet = MQTT::Parser::parse(Packet::SubscribeRequstQOS1, sizeof(Packet::SubscribeRequstQOS1));
    ASSERT_EQ(packet->getQOS(), MQTT::Packet::QOS::QOS1);
}

TEST(ParseFixedHeaderQOS, QOS2){
    auto packet = MQTT::Parser::parse(Packet::SubscribeRequstQOS2, sizeof(Packet::SubscribeRequstQOS2));
    ASSERT_EQ(packet->getQOS(), MQTT::Packet::QOS::QOS2);
}

TEST(ParseFixedHeaderRetainFlag, Retain_TRUE){
    auto packet = MQTT::Parser::parse(Packet::PublishRetain, sizeof(Packet::PublishRetain));
    ASSERT_TRUE(packet->getRetain());
}

TEST(ParseFixedHeaderRetainFlag, Retain_FALSE){
    auto packet = MQTT::Parser::parse(Packet::SubscribeRequstQOS2, sizeof(Packet::SubscribeRequstQOS2));
    ASSERT_FALSE(packet->getRetain());
}

TEST(ParseVariableHeader, CONNECT_ProtocolName_MQTT3_1_1){
    auto packet = MQTT::Parser::parse(Packet::Connect, sizeof(Packet::Connect));
    auto header = packet->getVariableHeader();
    ASSERT_EQ(std::dynamic_pointer_cast<MQTT::Connect>(header)->getProtocolName(), "MQTT");
}

TEST(ParseVariableHeader, CONNECT_ProtocolName_MQTT3_1){
    auto packet = MQTT::Parser::parse(Packet::Connect_V3_1, sizeof(Packet::Connect_V3_1));
    auto header = packet->getVariableHeader();
    ASSERT_EQ(std::dynamic_pointer_cast<MQTT::Connect>(header)->getProtocolName(), "MQISDP");
}

/**
 * Tests with invalid received packet
 */
TEST(ParseInvalidPackets, InvalidFixedHeaderLen){
    std::vector<uint8_t> invalidPacketHeader = {0x10};
    auto packet = MQTT::Parser::parse(invalidPacketHeader);
    ASSERT_FALSE(packet->isValid());
}

TEST(ParseInvalidPackets,InvalidLength){
    std::vector<uint8_t> invalidPacket = {0x80, 0x11, 0x00, 0x01, 0x00, 0x0c, 0x68, 0x6f, 0x6d, 0x65, 0x2f, 0x6b, 0x69, 0x74, 0x63, 0x68, 0x65, 0x6e};
    auto packet = MQTT::Parser::parse(invalidPacket);
    ASSERT_FALSE(packet->isValid());
}