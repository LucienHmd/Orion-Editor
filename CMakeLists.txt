cmake_minimum_required(VERSION 3.9.1)

project(Orion-Editor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

file(GLOB source src/*.cpp)

message("f e a r m e")

add_executable(orion ${source})
target_link_libraries(orion ${CURSES_LIBRARIES})