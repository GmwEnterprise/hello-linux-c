cmake_minimum_required(VERSION 3.16)
project(network C)

set(CMAKE_C_STANDARD 11)

add_executable(example1_server example1/socket_server.c commons/common.c commons/common.h)
add_executable(example1_client example1/socket_client.c commons/common.c commons/common.h)
