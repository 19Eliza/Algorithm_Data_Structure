cmake_minimum_required(VERSION 3.22)
project(queue)
file(GLOB PROJECT_SRC "*.h" "*.cpp")
add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SRC})