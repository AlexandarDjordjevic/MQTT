#include <gtest/gtest.h>
#include <MQTT/Packet.hpp>
#include <MQTT/Parser.hpp>

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

class testControlPacketConnect: public ::testing::Test { 
public: 
   testControlPacketConnect( ) { 

   } 

   void SetUp( ) { 
   }

   void TearDown( ) { 
   }

   ~testControlPacketConnect( )  { 
   }

   const uint8_t raw_buffer[18] = {
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
};

TEST_F(testControlPacketConnect, Parse_Header_Packet_Type){
    auto message = MQTT::Parser::parse(raw_buffer, sizeof(raw_buffer));
    ASSERT_EQ(message->getControlType(), MQTT::Packet::ControlType::CONNECT);
}
