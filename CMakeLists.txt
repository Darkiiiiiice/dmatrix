cmake_minimum_required(VERSION 3.0)
project(dmatrix C)

set(CMAKE_C_STANDARD 23)

set(CMAKE_C_FLAGS "-lncurses")


add_executable(dmatrix main.c)
