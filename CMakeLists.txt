cmake_minimum_required(VERSION 3.8)

set(this mqtt)

set(CMAKE_CXX_STANDARD 11)

set(include
        include/MQTT/Parser.hpp
        include/MQTT/Packet.hpp
        include/MQTT/Connect.hpp
    )

set(source
        source/Parser.cpp
        source/Packet.cpp
        source/Connect.cpp
    )

add_library(${this} STATIC ${source})

set_target_properties(${this} PROPERTIES
    FOLDER Libraries
)

target_include_directories(${this} PUBLIC include)

add_subdirectory(tests)