cmake_minimum_required(VERSION 3.22)
project(DijkstraAlgorithm)

set(GRAPH_DIR /root/projects/Algorithm_Data_Structure/Graph/)
set(HEAP_DIR /root/projects/Algorithm_Data_Structure/Heap/)

add_subdirectory(PriorityQueue)

file(GLOB PROJECT_SRC "*.h" "*.cpp")
file(GLOB GRAPH_SRC "${GRAPH_DIR}/GraphClass.h" "${GRAPH_DIR}/GraphClass.cpp")
file(GLOB HEAP_SRC "${HEAP_DIR}/HeapClass.h" "${HEAP_DIR}/HeapClass.cpp")

add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SRC} ${GRAPH_SRC} ${HEAP_SRC})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${GRAPH_DIR})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${HEAP_DIR})

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE PriorityQueueLib)