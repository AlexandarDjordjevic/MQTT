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
    
private:
    struct impl;
    std::unique_ptr<impl> pimpl;
};
}