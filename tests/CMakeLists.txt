cmake_minimum_required(VERSION 3.10)

project(Jilag)

include_directories(${CMAKE_SOURCE_DIR}/libfsa/include)

include_directories(${CMAKE_SOURCE_DIR}/libre/include)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(libfsa.tests)


