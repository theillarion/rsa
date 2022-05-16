cmake_minimum_required(VERSION 3.21)
project(rsa)

set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_COMPILER clang++)
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgmpxx -lgmp")

add_compile_options(
        "-Wall;-Werror;-Wextra"
        "$<$<CONFIG:DEBUG>:-g>"
        "$<$<CONFIG:RELEASE>:-O3>"
)

include_directories(includes)
include_directories(includes/algorithms/basic_algorithms)
include_directories(includes/algorithms/basic_functions)
include_directories(includes/algorithms/rsa)
include_directories(includes/random)
include_directories(includes/algorithms/check_simple)
include_directories(includes/utilities/utilities.hpp)


set(SRCS     srcs/file/file.cpp
            srcs/encrypt.cpp
            srcs/decrypt.cpp
            srcs/random/random.cpp
            srcs/algorithms/check_simple/miller_rabin_test.cpp
            srcs/utilities/utilities.cpp
            srcs/main.cpp)

set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)

add_executable(rsa ${SRCS})
