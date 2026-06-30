cmake_minimum_required(VERSION 3.20)
project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)

add_executable(SpaceInvaders main.cpp
        Classes/Player.cpp
        Classes/Player.h
        Classes/Engine.cpp
        Classes/Engine.h
        Classes/Bullet.cpp
        Classes/Bullet.h
)

target_link_libraries(SpaceInvaders PRIVATE raylib)