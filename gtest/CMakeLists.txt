cmake_minimum_required(VERSION 3.14)
project(demo CXX)
set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)

enable_testing()
add_executable(tests tests.cpp)
target_link_libraries(tests GTest::gtest_main GTest::gmock)

include(GoogleTest)
gtest_discover_tests(tests)
