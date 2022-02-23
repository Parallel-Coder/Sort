project(Sort)

cmake_minimum_required(VERSION 3.16)

file(GLOB INSERTSORT ${CMAKE_CURRENT_SOURCE_DIR}/InsertSort.hpp
                                    ${CMAKE_CURRENT_SOURCE_DIR}/Sort.hpp)

file(GLOB SHELLSORT ${CMAKE_CURRENT_SOURCE_DIR}/ShellSort.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Sort.hpp)

add_executable(InsertSortTest InsertTest.cc ${INSERTSORT})
add_executable(ShellTest ShellTest.cc ${SHELLSORT})