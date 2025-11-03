cmake_minimum_required(VERSION 4.0)
project(Project_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(src)
include_directories(data)

add_executable(Project_2
        include/movie.h
        include/parser.h
        src/main.cpp
        src/parser.cpp)
