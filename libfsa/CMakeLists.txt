cmake_minimum_required(VERSION 3.8)

project(libfsa)

set(CMAKE_CXX_STANDARD 14)

set(${${PROJECT_NAME}_INCLUDE} ${PROJECT_SOURCE_DIR}/include)

file(GLOB PUBLIC_HEADERS "${${PROJECT_NAME}_INCLUDE}/*.hpp")
file(GLOB SOURCES "src/*.cpp")

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${PUBLIC_HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME})