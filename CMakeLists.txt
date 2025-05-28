cmake_minimum_required(VERSION 3.10)
project(OOP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(vektoriai vector_test.cpp)
add_executable(list list_test.cpp)
add_executable(deque deque_test.cpp)