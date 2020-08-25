#include <gtest/gtest.h>
#include <MQTT/Packet.hpp>
#include <MQTT/Parser.hpp>

/*
https://public.dhe.ibm.com/software/dw/webservices/ws-mqtt/mqtt-v3r1.html
http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/os/mqtt-v3.1.1-os.html#_Toc398718009

The Packet header for each MQTT command Packet contains a fixed header. The table below shows the fixed header format.

bit	       |    7 6 5 4	  |    3	 |    2	1	    |   0
-----------------------------------------------------------------
byte 1     | Packet Type |	DUP flag |	QoS level   |	RETAIN
byte 2	   |             Remaining Length
-----------------------------------------------------------------
Byte 1
Contains the Packet Type and Flags (DUP, QoS level, and RETAIN) fields.

Byte 2
(At least one byte) contains the Remaining Length field. -----> Depends on Packet type!
*/
TEST(MQTT_Header, Parse_Header_Packet_Type){
    // uint8_t Packet[] = {0x10, };
    // MQTT::Packet Packet;
    // ASSERT_TRUE(Packet.valid());
    ASSERT_TRUE(true);
}

TEST(MQTT_Header, Parese_Invalid_Header){
    ASSERT_TRUE(true);
}