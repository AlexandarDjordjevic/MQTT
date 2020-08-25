#include <gtest/gtest.h>

/*
https://public.dhe.ibm.com/software/dw/webservices/ws-mqtt/mqtt-v3r1.html

The message header for each MQTT command message contains a fixed header. The table below shows the fixed header format.

bit	       |    7 6 5 4	  |    3	 |    2	1	    |   0
-----------------------------------------------------------------
byte 1     | Message Type |	DUP flag |	QoS level   |	RETAIN
byte 2	   |             Remaining Length
-----------------------------------------------------------------
Byte 1
Contains the Message Type and Flags (DUP, QoS level, and RETAIN) fields.

Byte 2
(At least one byte) contains the Remaining Length field. -----> Depends on message type!
*/
TEST(MQTT_Header, Parse_Header_Message_Type){
    ASSERT_TRUE(true);
}

TEST(MQTT_Header, Parese_Invalid_Header){
    ASSERT_TRUE(true);
}