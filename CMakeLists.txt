cmake_minimum_required(VERSION 4.0)
project(LabAssignments)

set(CMAKE_CXX_STANDARD 20)

add_executable(LabAssignments Lab14/main.cpp
        Lab14/Artist.h
        Lab14/Artwork.h
        Lab14/Artwork.cpp
        Lab14/Artist.cpp)
