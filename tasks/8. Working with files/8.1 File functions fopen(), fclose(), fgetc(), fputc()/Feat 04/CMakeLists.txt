cmake_minimum_required(VERSION 3.28)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type")
endif()

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug;Release;RelWithDebInfo;MinSizeRel")

# setup compilers
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# setup C CXX standards
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# setup output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

project(good-kind-c_cpp_with_sergey-balakirev LANGUAGES C CXX)

cmake_path(SET REPO_ROOT NORMALIZE ${CMAKE_CURRENT_SOURCE_DIR}/../../../../)

# gtest setup
set(GTest_DIR "${REPO_ROOT}/gtest/install/lib/cmake/GTest")
find_package(GTest REQUIRED)

# archieve `task_logic`
add_library(task_logic STATIC main_task.c)
target_include_directories(task_logic PUBLIC .)
target_compile_options(task_logic PUBLIC -Wall -Wextra -g)

# executable `main`
add_executable(main ./main.c)
target_link_libraries(main PRIVATE task_logic)
target_compile_options(main PRIVATE -Wall -Wextra -g)

# include tests
add_subdirectory("tests")
