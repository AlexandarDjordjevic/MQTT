/**
 * @file Message.hpp
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
    class Message{
    public:
        Message();
        ~Message();

        Message(const Message &) = delete;
        Message &operator=(const Message &) = delete;
        Message(Message &&) = delete;
        Message &operator=(const Message &&) = delete;
    private:
        struct impl;
        std::unique_ptr<impl> pimpl;
    };
} // namespace MQTT
