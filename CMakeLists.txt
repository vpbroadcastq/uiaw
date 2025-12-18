cmake_minimum_required(VERSION 3.20)
project(UiaWrap VERSION 0.1 LANGUAGES CXX)

SET(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
SET(CMAKE_EXPORT_COMPILE_COMMANDS, ON)

add_subdirectory(uiaw)
add_subdirectory(experiments)




