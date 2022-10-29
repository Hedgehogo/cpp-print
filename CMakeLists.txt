cmake_minimum_required(VERSION 3.23)
project(print)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE io-src "IO/*.hpp" "IO/*.cpp")

add_executable(print main.cpp ${io-src})
