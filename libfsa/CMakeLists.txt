cmake_minimum_required(VERSION 3.10)

project(fsa)

set(CMAKE_CXX_STANDARD 14)

file(GLOB PUBLIC_HEADERS "include/*.hpp")
file(GLOB SOURCES "src/*.cpp")

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${PUBLIC_HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME})