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
         * @brief Get the Clean Session object
         * 
         * @return true 
         * @return false 
         */
        bool getCleanSession();

        std::string getProtocolName();

        void setProtocolName(std::string protocolName);

    private:
        struct impl;
        std::unique_ptr<impl> pimpl;
    };
} // namespace MQTT
