# MQTT

This library iplements encodind and decoding MQTT V3.1 protocol messages.


MQTT(Message Queuing Telemetry Transport) is an open and lightweight, publish-subscribe network protocol that transports messages between devices. The protocol usually runs over TCP/IP; however, any network protocol that provides ordered, lossless, bi-directional connections can support MQTT. It is designed for connections with remote locations where a "small code footprint" is required or the network bandwidth is limited.

## Supported platforms / recommended toolchains

This is a C++11 library which depends only on the C++11 compiler and standard library.  
Supported platform are:

- Linux -- clang or gcc
- Widnows  -- Stefan will do this part!

## Building

This project can stand alone or be included in larger projects. CMake files are included for your convenience to generate a build system to compile the source code and link them into programs you can run.

There are two distinct steps in the build process using CMake:

Generation of the build system, using CMake
Compiling, linking, etc., using CMake-compatible toolchain

## Prerequisites

CMake version 3.8 or newer
C++11 toolchain compatible with CMake for your development platform
