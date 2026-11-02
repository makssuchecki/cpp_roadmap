cmake_minimum_required(VERSION 3.16)
project(cv_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(cv_demo main.cpp)
target_link_libraries(cv_demo PRIVATE ${OpenCV_LIBS})