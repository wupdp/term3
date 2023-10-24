cmake_minimum_required(VERSION 3.26)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab3 main.cpp
        person.h
        teacher.h
        party_member.cpp
        party_member.h
        person.cpp
        teacher.cpp
        party_teacher.cpp
        party_teacher.h
)
