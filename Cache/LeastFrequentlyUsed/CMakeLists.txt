cmake_minimum_required(VERSION 3.22)
file(GLOB PROJECT_SRC "*.cpp" "*.h")
add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SRC})