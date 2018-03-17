cmake_minimum_required(VERSION 3.7)

#root project
project (gherkin_calculator)


SET(CMAKE_VERBOSE_MAKEFILE OFF)
SET(CMAKE_CXX_STANDARD 17)

# add include directories for all the subprojects
include_directories("${PROJECT_ROOT_DIR}/GUnit/include")
include_directories("${PROJECT_ROOT_DIR}/GUnit/libs/gherkin-cpp/include")
include_directories("${PROJECT_ROOT_DIR}/GUnit/libs/json/src")

link_directories("${PROJECT_ROOT_DIR}/GUnit/libs/gherkin-cpp")


set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/steps)
set(PROJECT_FEATURES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/features)

set(CALCULATOR_ADD_STEPS_SOURCES
        ${PROJECT_SOURCE_DIR}/CalculatorSteps.cpp)

add_executable(calculator_add_steps ${CALCULATOR_ADD_STEPS_SOURCES})
target_link_libraries(calculator_add_steps gtest_main gmock_main gherkin-cpp calculator)
add_custom_command(TARGET calculator_add_steps COMMAND SCENARIO=${PROJECT_FEATURES_DIR}/addition.feature ${CMAKE_BINARY_DIR}/calculator_add_steps)
add_test(test_calculator_add_steps calculator_add_steps)
configure_file(${PROJECT_FEATURES_DIR}/addition.feature ${CMAKE_BINARY_DIR}/addition.feature COPYONLY)