cmake_minimum_required(VERSION 3.22)

project(Heap)

add_library(HeapLib STATIC HeapClass.cpp)

add_executable(HeapMain main.cpp)

target_link_libraries(HeapMain HeapLib)












# cmake_minimum_required(VERSION 3.22)
# project(Heap)
# file(GLOB PROJECT_SRC "*.h" "*.cpp")
# add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SRC})