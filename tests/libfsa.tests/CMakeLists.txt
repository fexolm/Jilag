cmake_minimum_required(VERSION 3.8)

project(libfsa.test)

set(CMAKE_CXX_STANDARD 14)

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK -DBOOST_TEST_MAIN)

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})


add_executable(main_test main.cpp)

target_link_libraries(main_test libfsa ${Boost_LIBRARIES})

enable_testing ()
add_test(main main_test)
