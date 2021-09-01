cmake_minimum_required(VERSION 3.16)
project(cmake_unixc_examples C)

set(CMAKE_C_STANDARD 11)

link_libraries(m)
add_executable(examples_leetcode examples_leetcode/compare-version-numbers.c)
