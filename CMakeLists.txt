cmake_minimum_required(VERSION 3.21)
project(rsa)

set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_COMPILER clang++)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -lgmpxx -lgmp")

include_directories(includes)
include_directories(includes/algorithms/basic_algorithms)
include_directories(includes/algorithms/basic_functions)
include_directories(includes/algorithms/rsa)
include_directories(includes/random)
include_directories(includes/algorithms/check_simple)

set(SRCS     srcs/file/file.cpp
            srcs/encrypt.cpp
            srcs/decrypt.cpp
            srcs/random/random.cpp
            srcs/algorithms/check_simple/miller_rabin_test.cpp
            srcs/main.cpp)

add_executable(rsa ${SRCS})
