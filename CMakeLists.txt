cmake_minimum_required(VERSION 3.10)
project(my_project)

set(CMAKE_CXX_STANDARD 17)

# Header files
file(GLOB_RECURSE HEADER_FILES "*.h")


file(GLOB_RECURSE SOURCE_FILES "*.cpp")

# Exclude CMakeCXXCompilerId.cpp and other unwanted files
list(FILTER SOURCE_FILES EXCLUDE REGEX "CMakeCXXCompilerId.cpp")

# Exclude test.cpp
list(FILTER SOURCE_FILES EXCLUDE REGEX "test.cpp")

add_executable(my_executable ${SOURCE_FILES})