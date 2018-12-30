cmake_minimum_required(VERSION 3.5)
project(shmup)

set(CXX_STANDARD "c++17")
add_definitions("-std=c++17")

include(conanbuildinfo.cmake)
conan_basic_setup()

include_directories(src)
include_directories(../)

add_library(world src/VirtualWorld.cpp)
add_library(game_window src/GameWindow.cpp)
add_library(interleaved_passive_event src/InterleavedPassiveEvent.cpp)
add_library(player src/Player.cpp)
add_library(team src/Team.cpp)
target_link_libraries(player ${CONAN_LIBS} interleaved_passive_event world)

add_executable(shmup src/shmup.cpp)
target_link_libraries(shmup ${CONAN_LIBS} world player game_window team)
target_compile_options(shmup PRIVATE -O3)
