cmake_minimum_required(VERSION 3.10)

project(Jilag)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(libfsa)
add_subdirectory(libre)
add_subdirectory(tests)
