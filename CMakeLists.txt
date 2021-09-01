cmake_minimum_required(VERSION 3.0)

include_directories(include)
set(PROJ_NAME "stgproject")
project(${PROJ_NAME})

set(MAIN_TARGET "stgproject")

file(GLOB SOURCES "src/*.cpp")
add_executable(${MAIN_TARGET} ${SOURCES})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(${MAIN_TARGET} ${SDL2_LIBRARIES})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
target_compile_options(${MAIN_TARGET} PRIVATE -Wall -pedantic -Werror -std=c++20)
