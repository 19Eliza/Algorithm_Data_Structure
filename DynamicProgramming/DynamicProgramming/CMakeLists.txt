cmake_minimum_required(VERSION 3.22)
project(DynamicProgramming)


set(CMAKE_BUILD_TYPE Debug)

file(GLOB PROJECT_SRC "*.cpp" "*.h")

add_executable(${PROJECT_NAME} ${PROJECT_SRC})