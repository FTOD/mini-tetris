cmake_minimum_required(VERSION 3.20)
project(mini_tetris)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES Tetris.cpp Tetris.hpp)

add_library(tetris STATIC ${SOURCES})