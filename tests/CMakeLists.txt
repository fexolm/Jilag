cmake_minimum_required(VERSION 3.8)

project(Jilag)

include_directories(${CMAKE_SOURCE_DIR}/libfsa/include)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(libfsa.tests)


