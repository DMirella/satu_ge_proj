cmake_minimum_required(VERSION 2.8)

########################################
# Define include directories
########################################
set(COMMON_INCLUDES ./tools/)
include_directories(${COMMON_INCLUDES})

########################################
# Source files
########################################
file(GLOB SRC_FILES ./tools/*.cc)