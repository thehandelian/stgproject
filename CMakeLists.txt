cmake_minimum_required(VERSION 3.7)

set(PROJ_NAME "stgproject")
project(${PROJ_NAME})
set(MAIN_TARGET "stgproject")

file(GLOB SOURCES "src/*.cpp")
add_executable(${MAIN_TARGET} ${SOURCES})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${MAIN_TARGET} include)
#include_directories(${MAIN_TARGET} ${SDL2_INCLUDE_DIRS})
#include_directories(${MAIN_TARGET} ${SDL2_IMAGE_DIRS})

target_link_libraries(${MAIN_TARGET} SDL2::Main SDL2::Image)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
target_compile_options(${MAIN_TARGET} PRIVATE -Wall -pedantic -Werror -std=c++20)
