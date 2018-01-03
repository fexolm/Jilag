cmake_minimum_required(VERSION 3.8)

project(Jilag)

set(CMAKE_CXX_STANDARD 14)

file(GLOB PUBLIC_HEADERS "include/*.hpp")
file(GLOB SOURCES "src/*.cpp")

include_directories(include)

add_executable(Jilag ${PUBLIC_HEADERS} ${SOURCES} main.cpp)