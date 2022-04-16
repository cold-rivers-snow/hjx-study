cmake_minimum_required(VERSION 3.0.0)
project(hello VERSION 0.1.0)

set(src_list main.c)
message(STATUS "This is BINARY dir " ${HELLO_BINARY_DIR})
message(STATUS "This is SOURCE dir "${HELLO_SOURCE_DIR})

add_executable(hello ${src_list})