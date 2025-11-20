cmake_minimum_required(VERSION 3.15)
project(Project2)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Project2
        main.cpp
        Node.h
        Stack.h)
