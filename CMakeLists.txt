cmake_minimum_required(VERSION 3.5)
project(shmup)

set(CXX_STANDARD "c++17")
add_definitions("-std=c++17")

include(conanbuildinfo.cmake)
conan_basic_setup()

include_directories(src)
include_directories(../)

add_library(bullet src/Bullet.cpp)
add_library(collision src/Collision.cpp)
add_library(game_window src/GameWindow.cpp)
add_library(interleaved_passive_event src/InterleavedPassiveEvent.cpp)
add_library(object src/Object.cpp)
add_library(player src/Player.cpp)
add_library(ship src/Ship.cpp)
add_library(shape_factory src/ShapeFactory.cpp)
add_library(team src/Team.cpp)
add_library(world src/VirtualWorld.cpp)

target_link_libraries(bullet ${CONAN_LIBS})
target_link_libraries(collision ${CONAN_LIBS} object)
target_link_libraries(object ${CONAN_LIBS} team collision)
target_link_libraries(player ${CONAN_LIBS} bullet interleaved_passive_event object shape_factory ship world)
target_link_libraries(ship object)

add_executable(shmup src/shmup.cpp)
target_link_libraries(shmup ${CONAN_LIBS} world player game_window team)

target_compile_options(shmup PRIVATE -O3)
