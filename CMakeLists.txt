cmake_minimum_required(VERSION 3.21)
project(rsa)

set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_COMPILER clang++)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -lgmpxx -lgmp")

include_directories("includes/")

add_executable(rsa srcs/main.cpp includes/algorithms.hpp includes/basic_functions.hpp)
