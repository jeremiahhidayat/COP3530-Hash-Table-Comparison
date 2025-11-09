cmake_minimum_required(VERSION 3.30)
project(Project2_Part_2)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(Project2_Part_2
    include/CLI.h
    include/hashOpenAddress.h
    include/hashSeparateAddress.h
    include/movie.h
    include/parser.h
    src/CLI.cpp
    src/main.cpp
    src/parser.cpp)
