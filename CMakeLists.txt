cmake_minimum_required(VERSION 3.8)

set(this mqtt)

set(CMAKE_CXX_STANDARD 11)

set(include
        include/MQTT/MQTT.hpp
    )

set(source
        source/MQTT.cpp
    )

add_library(${this} STATIC ${source})

set_target_properties(${this} PROPERTIES
    FOLDER Libraries
)

target_include_directories(${this} PUBLIC include)

add_subdirectory(tests)