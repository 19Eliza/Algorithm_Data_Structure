cmake_minimum_required(VERSION 3.22)

project(PriorityQueue)

file(GLOB PROJECT_SRC "*.h" "*.cpp")
file(GLOB HEAP_SRC "../Heap/HeapClass.h" "../Heap/HeapClass.cpp")

add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SRC} ${HEAP_SRC})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ../Heap)
