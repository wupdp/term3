cmake_minimum_required(VERSION 3.26)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1 main.cpp
        massive.cpp
        headers/massive.h
        menu_functions.cpp
        headers/menu_functions.h
        )
