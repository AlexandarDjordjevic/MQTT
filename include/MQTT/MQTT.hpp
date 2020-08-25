/**
 * @file MQTT.hpp
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

namespace MQTT{
    class MQTT{
    public:
        MQTT();
        ~MQTT();

        MQTT(const MQTT &) = delete;
        MQTT &operator=(const MQTT &) = delete;
        MQTT(MQTT &&) = delete;
        MQTT &operator=(const MQTT &&) = delete;
    private:
        struct impl;
        std::unique_ptr<impl> pimpl;
    };
}