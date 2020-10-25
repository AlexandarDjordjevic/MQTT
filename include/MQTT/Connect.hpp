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

    enum class QOS : uint8_t
    {
        QOS_0 = 0x00,
        QOS_1 = 0x01,
        QOS_2 = 0x02
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

        struct Flags{
            uint8_t Username        : 1;
            uint8_t Password        : 1;
            uint8_t WillRETAIN      : 1;
            uint8_t WillQoS         : 2;
            uint8_t Willflag        : 1;
            uint8_t CleanSession    : 1;
            uint8_t Reserved        : 1;
        };

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
         * @brief Get the Username Flag
         * 
         * @return true 
         * @return false 
         */
        bool getUsernameFlag();

        /**
         * @brief Get the Password Flag
         * 
         * @return true 
         * @return false 
         */
        bool getPasswordFlag();

        /**
         * @brief Get the Will Retain Flag
         * 
         * @return true 
         * @return false 
         */
        bool getWillRetainFlag();

        /**
         * @brief Get the Will QOS
         * 
         * @return QOS 
         */
        QOS getWillQOS();

        /**
         * @brief Get the Will Flag
         * 
         * @return true 
         * @return false 
         */
        bool getWillFlag();
        
        /**
         * @brief Get the Clean Session Flag
         * 
         * @return true 
         * @return false 
         */
        bool getCleanSessionFlag();

        /**
         * @brief Set the Connect Flags
         * 
         * @param flags 
         */
        void setFlags(uint8_t flags);
        
        /**
         * @brief Get the Keep Alive Timer
         * 
         * @return uint16_t 
         */
        uint16_t getKeepAliveTimer();

        /**
         * @brief Set the Keep Alive Timer
         * 
         * @param keepAlive 
         */
        void setKeepAliveTimer(uint16_t keepAlive);

        /**
         * @brief Set the Client Identifier object
         * 
         * @param clientIdentifier 
         * @return true Identifier is valid (len <= 23)
         * @return false Identifier is invalid (len > 23)
         */
        bool setClientIdentifier(std::string clientIdentifier);

        /**
         * @brief Set the Client Identifier
         * 
         * @return std::string 
         */
        std::string getClientIdentifier();

    private:
        struct impl;
        std::unique_ptr<impl> pimpl;
    };
} // namespace MQTT
