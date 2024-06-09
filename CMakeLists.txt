cmake_minimum_required(VERSION 3.28)
project(challenge)

set(CMAKE_CXX_STANDARD 17)

add_executable(challenge main.cpp read_array.hpp parse_array.hpp parallel.hpp)
