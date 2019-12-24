cmake_minimum_required(VERSION 2.8)

project(satu_ge_proj)

set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_CXX_STANDARD 14)

################################

# Options. Turn on with 'cmake -Dmyvarname=ON'.
option(BUILD_TESTS "Build all tests." ON) # Makes boolean 'test' available.

if (BUILD_TESTS)
  add_subdirectory(./tests)
endif()