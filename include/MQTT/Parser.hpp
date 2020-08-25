/**
 * @file Parser.hpp
 * @author Aleksandar Djordjevic
 * @brief 
 * @version 0.1
 * @date 2020-08-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once
#include <memory>
#include <MQTT/Packet.hpp>
#include <vector>

namespace MQTT{
    class Parser{
    public:
        /**
         * @brief Construct a new Parser object
         * 
         */
        Parser();
        /**
         * @brief Destroy the Parser object
         * 
         */
        ~Parser();

        Parser(const Parser &) = delete;
        Parser &operator=(const Parser &) = delete;
        Parser(Parser &&) = delete;
        Parser &operator=(const Parser &&) = delete;
        
        /**
         * @brief Parse MQTT message from buffer
         * 
         * @param buffer 
         * @param len 
         * @return Packet* 
         */
        static Packet* parse(const uint8_t* buffer, size_t len);

        /**
         * @brief Parse MQTT message from vector
         * 
         * @param buffer 
         * @return Packet* 
         */
        static Packet* parse(const std::vector<uint8_t>& buffer);
    private:
        struct impl;
        std::unique_ptr<impl> pimpl;
    };
}