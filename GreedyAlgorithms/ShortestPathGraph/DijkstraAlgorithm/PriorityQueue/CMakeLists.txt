set(HEAP_DIR /root/projects/Algorithm_Data_Structure/Heap/)

file(GLOB HEAP_SRC "${HEAP_DIR}/HeapClass.h" "${HEAP_DIR}/HeapClass.cpp")

add_library(PriorityQueueLib STATIC PriorityQueue.cpp PriorityQueue.h)

target_include_directories(PriorityQueueLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(PriorityQueueLib PUBLIC ${HEAP_DIR})