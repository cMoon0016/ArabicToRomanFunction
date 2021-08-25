cmake_minimum_required(VERSION 3.19)
project(ArabicToRomanNumbers_with_tests)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(ArabicToRomanNumbers_with_tests main.cpp tests.cpp ArabicToRoman.h)
target_link_libraries(ArabicToRomanNumbers_with_tests gtest gtest_main)