cmake_minimum_required(VERSION 3.10)
project(my_project)

set(CMAKE_CXX_STANDARD 17)

# Header files
file(GLOB_RECURSE HEADER_FILES "*.h")

# Source files (all but test.cpp)
file(GLOB_RECURSE SOURCE_FILES "*.cpp")
list(FILTER SOURCE_FILES EXCLUDE REGEX ".*Can remove/.*")
list(FILTER SOURCE_FILES EXCLUDE REGEX "CMakeCXXCompilerId.cpp")
list(FILTER SOURCE_FILES EXCLUDE REGEX ".*Tests/test.cpp")  # Exclude test.cpp

# Create a library for the main project
add_library(my_project_lib ${SOURCE_FILES})
set(SERVER_MAIN_FILE "src/main.cpp")
add_executable(server_exe ${SERVER_MAIN_FILE})
target_link_libraries(server_exe PRIVATE my_project_lib)
# Main server executable

# Include Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Test executable (only compiles test.cpp, links my_project_lib)
set(TEST_MAIN_FILE "src/Tests/test.cpp")
add_executable(tests_exe ${TEST_MAIN_FILE})
target_link_libraries(tests_exe PRIVATE my_project_lib gtest_main)

# Enable testing
enable_testing()
add_test(NAME RunAllTests COMMAND tests_exe)