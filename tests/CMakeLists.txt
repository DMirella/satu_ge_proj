add_subdirectory(./googletest)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/source)

#TODO: Remove this...
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/source/*.cc)

set(GTEST_LIBS gtest gtest_main)
set(TEST_LIST
    test_tools
)

foreach(TEST_NAME ${TEST_LIST})
    message("add executable: ${TEST_NAME}")
    set(EXEC_NAME ${TEST_NAME})

    add_executable(
    	${EXEC_NAME}
        ${TEST_NAME}.cc
        ${SOURCES}
    )
    set_property(TARGET ${EXEC_NAME} PROPERTY CXX_STANDARD 14)
    set_property(TARGET ${EXEC_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

    target_link_libraries(${EXEC_NAME} ${GTEST_LIBS})
    add_test(
        ${EXEC_NAME}
        ${EXEC_NAME}
    )
endforeach(TEST_NAME)