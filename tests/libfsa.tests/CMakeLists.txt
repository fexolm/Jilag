cmake_minimum_required(VERSION 3.10)

project(libfsa.test)

set(CMAKE_CXX_STANDARD 14)

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK -DBOOST_TEST_MAIN)

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(fsa_test fsa.cpp)

target_link_libraries(fsa_test fsa ${Boost_LIBRARIES})

add_test(fsa_test fsa_test)
