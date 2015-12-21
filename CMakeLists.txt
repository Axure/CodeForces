cmake_minimum_required(VERSION 3.3)
project(Codeforces)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(Codeforces ${SOURCE_FILES})

add_subdirectory(build)