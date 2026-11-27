# --- MAIN --- #

cmake_minimum_required(VERSION 3.25)

project(tiny-crypt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(tiny-crypt main.cpp)

# --- SFML --- #

include(FetchContent)
FetchContent_Declare(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 3.1.0)
FetchContent_MakeAvailable(SFML)

target_link_libraries(tiny-crypt PRIVATE SFML::Graphics)
