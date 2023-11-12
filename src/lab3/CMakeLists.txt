cmake_minimum_required(VERSION 3.26)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab3 main.cpp
        headers/person.h
        headers/teacher.h
        classes/party_member.cpp
        headers/party_member.h
        classes/person.cpp
        classes/teacher.cpp
        classes/party_teacher.cpp
        headers/party_teacher.h
        headers/header.h
)
