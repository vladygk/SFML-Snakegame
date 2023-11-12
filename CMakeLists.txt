cmake_minimum_required(VERSION 3.26)
project(snake_game)

set(CMAKE_CXX_STANDARD 17)

add_executable(snake_game main.cpp)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(snake_game sfml-graphics sfml-audio)