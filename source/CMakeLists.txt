cmake_minimum_required(VERSION 2.8)

#----------------------------------------------------------------------------
# Define project sources and includes
#----------------------------------------------------------------------------
file(GLOB PROJ_SRC_FILES ${{PROJECT_}}/tools/*.cc)
# list(REMOVE_ITEM SRC_FILES ${PROJECT_SOURCE_DIR}/src/main.cc)

set(CMAKE_CXX_STANDARD 14)

################################
# Normal Libraries & Executables
################################
add_library(satu_ge_proj_lib ${PROJ_SRC_FILES})
# add_executable(satu_ge_proj ${PROJECT_SOURCE_DIR}/src/main.cpp)
# Key idea: SEPARATE OUT your main() function into its own file so it can be its
# own executable. Separating out main() means you can add this library to be
# used elsewhere (e.g linking to the test executable).

# target_link_libraries(satu_ge_proj satu_ge_proj_lib)