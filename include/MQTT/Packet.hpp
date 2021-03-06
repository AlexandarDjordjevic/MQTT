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
#include <MQTT/IVariableHeader.hpp>
#include <MQTT/FixedHeader.hpp>

namespace MQTT{
    class Packet
    {
    public:

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
         * @brief Check if packet is valid
         * 
         * @return true 
         * @return false 
         */
        bool isValid();

        /**
         * @brief Set the flag for invalid packet
         * 
         */
        void setInvalid();

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
        void parseDupFlag(bool dup);

        /**
         * @brief Get QOS
         * 
         * @return QOS 
         */
        QOS getQOS();

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
        void parseRetain(bool retain);

        /**
         * @brief Get the Header Remaing Length
         * 
         * @return size_t 
         */
        size_t getHeaderRemaingLength();

        /**
         * @brief Set the Header Remaing Length
         * 
         * @param len 
         */
        void parseHeaderReminingLen(uint8_t len);

        /**
         * @brief Get the Variable Header object
         * 
         * @return std::shared_ptr<IVariableHeader> 
         */
        std::shared_ptr<IVariableHeader> getVariableHeader();

        /**
         * @brief Parse vairable header from buffer
         * 
         */
        void parseVariableHeader(uint8_t*, size_t);

        /**
         * @brief Parse Fixed Header
         * 
         * @return true 
         * @return false 
         */
        bool parseFixedHeader(const uint8_t* buffer);

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
        std::string parseStringField(uint8_t* buffer);

    private:
        struct impl;
        std::unique_ptr<impl> pimpl;
    };

} // namespace MQTT
