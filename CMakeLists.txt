cmake_minimum_required(VERSION 3.10)
project(OOP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    main.cpp
    functions.cpp
    masyvas.cpp
    vektoriai.cpp
    deque_test.cpp
    list_test.cpp
    vector_test.cpp
)

add_executable(studentai ${SOURCES})