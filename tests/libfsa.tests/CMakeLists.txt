cmake_minimum_required(VERSION 3.10)

project(libfsa.test)

set(CMAKE_CXX_STANDARD 14)

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK -DBOOST_TEST_MAIN)

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(fsa_test fsa.cpp)
add_executable(re_test re_test.cpp)
add_executable(re_test2 re_test2.cpp)
add_executable(re_test3 re_test3.cpp)


target_link_libraries(fsa_test fsa ${Boost_LIBRARIES})
target_link_libraries(re_test re ${Boost_LIBRARIES})
target_link_libraries(re_test2 re ${Boost_LIBRARIES})
target_link_libraries(re_test3 re ${Boost_LIBRARIES})


add_test(fsa_test fsa_test)
add_test(re_test re_test)
add_test(re_test2 re_test2)
add_test(re_test3 re_test2)
