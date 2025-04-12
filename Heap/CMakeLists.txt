cmake_minimum_required(VERSION 3.22)

project(Heap)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(HeapLib STATIC HeapClass.cpp)

add_executable(HeapMain main.cpp)

target_link_libraries(HeapMain HeapLib)












# cmake_minimum_required(VERSION 3.22)
# project(Heap)
# file(GLOB PROJECT_SRC "*.h" "*.cpp")
# add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SRC})