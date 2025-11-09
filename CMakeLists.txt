cmake_minimum_required(VERSION 3.30)
project(${CMAKE_PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE PROJECT_SOURCES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*.h
)

file(GLOB_RECURSE PROJECT_SOURCES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*.h
)

add_executable(HashTableCLI
    include/CLI.h
    include/hashOpenAddress.h
    include/hashSeparateAddress.h
    include/movie.h
    include/parser.h
    src/CLI.cpp
    src/main.cpp
    src/parser.cpp
    )

