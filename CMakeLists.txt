cmake_minimum_required(VERSION 3.27)
project(C_project C)

set(CMAKE_C_STANDARD 11)

add_executable(C_project
        main.c
        Dataframe.h
        Dataframe.c
        column.h
        column.c
)
