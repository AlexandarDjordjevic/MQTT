/**
 * @file Connect.hpp
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

namespace MQTT
{
    enum class ProtocolVersion : uint8_t
    {
        MQTT_3_1 = 0x03,
        MQTT_3_1_1 = 0x04
    };
    class Connect
        : public IVariableHeader
    {
    public:
        /**
         * @brief Construct a new Connect object
         * 
         */
        Connect();
        /**
         * @brief Destroy the Connect object
         * 
         */
        ~Connect();

        Connect(const Connect &) = delete;
        Connect &operator=(const Connect &) = delete;
        Connect(Connect &&) = delete;
        Connect &operator=(const Connect &&) = delete;

        /**
         * @brief Get the Protocol Name from variable header
         * 
         * @return std::string Protocol name
         */
        std::string getProtocolName();

        /**
         * @brief Set the Protocol Name object
         * 
         * @param protocolName 
         */
        void setProtocolName(std::string protocolName);

        /**
         * @brief Get the Protocol Level
         * 
         * @return ProtocolVersion 
         */
        ProtocolVersion getProtocolVersion();

        /**
         * @brief Set the Protocol Level
         * 
         */
        void setProtocolLevel(ProtocolVersion);

        /**
         * @brief Get the Clean Session object
         * 
         * @return true 
         * @return false 
         */
        bool getCleanSession();



    private:
        struct impl;
        std::unique_ptr<impl> pimpl;
    };
} // namespace MQTT
