cmake_minimum_required(VERSION 2.8)

project(satu_ge_proj)

set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_CXX_STANDARD 14)

# If you want your own include/ directory, set this, and then you can do
# include_directories(${COMMON_INCLUDES}) in other CMakeLists.txt files.
# set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

#----------------------------------------------------------------------------
# Define project sources and includes
#----------------------------------------------------------------------------
include_directories(${PROJECT_SOURCE_DIR}/source)
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/source/*.cc)
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/*.cc)
# list(REMOVE_ITEM SRC_FILES ${PROJECT_SOURCE_DIR}/src/main.cpp)


################################
# Normal Libraries & Executables
################################
set(PROJ_SRC_LIB_NAME satu_ge_proj_lib)
add_library(${PROJ_SRC_LIB_NAME} ${SRC_FILES})
# add_executable(project1 ${PROJECT_SOURCE_DIR}/src/main.cpp)
# Key idea: SEPARATE OUT your main() function into its own file so it can be its
# own executable. Separating out main() means you can add this library to be
# used elsewhere (e.g linking to the test executable).

# target_link_libraries(project1 project1_lib)

################################
# Testing
################################

# Options. Turn on with 'cmake -Dmyvarname=ON'.
option(BUILD_TESTS "Build all tests." ON) # Makes boolean 'test' available.

if (BUILD_TESTS)
  add_subdirectory(./googletest)
  add_subdirectory(./tests)
endif()