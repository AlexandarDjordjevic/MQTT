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
        //Types
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
    private:
        struct impl;
        std::unique_ptr<impl> pimpl;
    };

} // namespace MQTT
