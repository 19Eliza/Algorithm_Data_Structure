cmake_minimum_required(VERSION 3.22)
project(SubsetSumProblem)

file(GLOB PROJECT_SRC "*.cpp" "*.h")

add_executable(${PROJECT_NAME} ${PROJECT_SRC})