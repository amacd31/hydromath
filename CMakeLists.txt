cmake_minimum_required(VERSION 2.8)

project (hydromath)
set(PROJECT_TEST_NAME test_hydromath)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

add_subdirectory(src)
IF (BUILD_TESTING)
    add_subdirectory(tests)

    if(CMAKE_COMPILER_IS_GNUCXX)
        include(CodeCoverage)
        setup_target_for_coverage(${PROJECT_NAME}_coverage ${PROJECT_TEST_NAME} coverage)
    endif()
ENDIF(BUILD_TESTING)
