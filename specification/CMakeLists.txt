cmake_minimum_required(VERSION 3.7)

#root project
project (gherkin_calculator)


SET(CMAKE_VERBOSE_MAKEFILE OFF)
SET(CMAKE_CXX_STANDARD 17)

# add include directories for all the subprojects
include_directories("${PROJECT_ROOT_DIR}/3pp/GUnit/include")
include_directories("${PROJECT_ROOT_DIR}/3pp/GUnit/libs/gherkin-cpp/include")
include_directories("${PROJECT_ROOT_DIR}/3pp/GUnit/libs/json/src")

link_directories("${PROJECT_ROOT_DIR}/3pp/GUnit/libs/gherkin-cpp")

#Set variables with folder paths
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/steps)
set(PROJECT_FEATURES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/features)

#=== Steps targets per feature ===
#== Add feature ==
set(CALCULATOR_ADD_STEPS_SOURCES
        ${PROJECT_SOURCE_DIR}/CalculatorSteps.cpp)

add_executable(calculator_add_steps EXCLUDE_FROM_ALL ${CALCULATOR_ADD_STEPS_SOURCES})
add_dependencies(calculator_add_steps gherkin_cpp-static)
target_link_libraries(calculator_add_steps gtest_main gmock_main gherkin-cpp calculator)
add_custom_command(TARGET calculator_add_steps COMMAND SCENARIO=${PROJECT_FEATURES_DIR}/addition.feature ${CMAKE_BINARY_DIR}/calculator_add_steps)
add_test(test_calculator_add_steps calculator_add_steps)
#copy feature file to binary folder ... still unable to make cmake recompile if feature file changes...
configure_file(${PROJECT_FEATURES_DIR}/addition.feature ${CMAKE_BINARY_DIR}/addition.feature COPYONLY)


#== Sub feature ==
set(CALCULATOR_SUB_STEPS_SOURCES
        ${PROJECT_SOURCE_DIR}/CalculatorSteps.cpp)

add_executable(calculator_sub_steps EXCLUDE_FROM_ALL ${CALCULATOR_SUB_STEPS_SOURCES})
add_dependencies(calculator_sub_steps gherkin_cpp-static)
target_link_libraries(calculator_sub_steps gtest_main gmock_main gherkin-cpp calculator)
add_custom_command(TARGET calculator_sub_steps COMMAND SCENARIO=${PROJECT_FEATURES_DIR}/subtraction.feature ${CMAKE_BINARY_DIR}/calculator_sub_steps)
add_test(test_calculator_sub_steps calculator_sub_steps)
#copy feature file to binary folder ... still unable to make cmake recompile if feature file changes...
configure_file(${PROJECT_FEATURES_DIR}/subtraction.feature ${CMAKE_BINARY_DIR}/subtraction.feature COPYONLY)

#=== Custom target with all the steps targets
set(ALL_CALCULATOR_STEPS_TARGETS
        calculator_add_steps
        calculator_sub_steps
        )
add_custom_target(calculator_test ALL DEPENDS ${ALL_CALCULATOR_STEPS_TARGETS})