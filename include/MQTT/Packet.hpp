/**
 * @file Packet.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-08-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once

#include <memory>

namespace MQTT{
    class Packet{
    public:
        enum ControlType{
            Reserved = 0,
            CONNECT,
            CONNACK,
            PUBLISH,
            PUBACK,
            PUBREC,
            PUBREL,
            PUBCOMP,
            SUBSCRIBE,
            SUBACK,
            UNSUBSCRIBE,
            UNSUBACK,
            PINGREQ,
            PINGRESP,
            DISCONNECT
        };

        enum QOS{
            QOS0,
            QOS1,
            QOS2
        };
        /**
         * @brief Construct a new Packet object
         * 
         */
        Packet();

        /**
         * @brief Destroy the Packet object
         * 
         */
        ~Packet();

        Packet(const Packet &) = delete;
        Packet &operator=(const Packet &) = delete;
        Packet(Packet &&) = delete;
        Packet &operator=(const Packet &&) = delete;

        /**
         * @brief Get the packet control type
         * 
         * @return ControlType 
         */
        ControlType getControlType();

        /**
         * @brief Get the packet control type
         * 
         * @param ct 
         */
        void setControlType(ControlType ct);

        /**
         * @brief Get the Dup Flag
         * 
         * @return true 
         * @return false 
         */
        bool getDupFlag();

        /**
         * @brief Set the Dup Flag
         * 
         * @param dup 
         */
        void setDupFlag(bool dup);

        /**
         * @brief Get QOS
         * 
         * @return QOS 
         */
        QOS getQOS();
        /**
         * @brief Set QOS
         * 
         * @param qos 
         */
        void setQOS(QOS qos);

        /**
         * @brief Get the Retain
         * 
         * @return true 
         * @return false 
         */
        bool getRetain();
        /**
         * @brief Set the Retain
         * 
         * @param retain 
         */
        void setRetain(bool retain);

        /**
         * @brief Get the Header Remaing Length
         * 
         * @return uint8_t 
         */
        uint8_t getHeaderRemaingLength();

        /**
         * @brief Set the Header Remaing Length
         * 
         * @param len 
         */
        void setHeaderRemaingLength(uint8_t len);

        /**
         * @brief Get the Protocol Name
         * 
         * @return std::string 
         */
        std::string getProtocolName();

        /**
         * @brief Set the Protocol Name
         * 
         * @param protocolName 
         */
        void setProtocolName(std::string protocolName);

    private:
        struct impl;
        std::unique_ptr<impl> pimpl;
    };

} // namespace MQTT
