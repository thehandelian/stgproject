cmake_minimum_required(VERSION 3.0)

include_directories(include)
set(PROJ_NAME "stgproject")
project(${PROJ_NAME})

set(EXEC_NAME "stgproject")

file(GLOB SOURCES "src/*.cpp")
add_executable(${EXEC_NAME} ${SOURCES})

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(${EXEC_NAME} ${SDL2_LIBRARIES})
