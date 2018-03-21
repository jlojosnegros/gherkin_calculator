cmake_minimum_required(VERSION 3.7)
project(gherkin_calculator)

# por si queremos cambiarlo para este proyecto en particular
SET(CMAKE_VERBOSE_MAKEFILE OFF)

# Decision: Public headers goes directly in the project root folder
SET(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR})

# Source files goes in the /src folder
SET(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)


# add project include folder to include path
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

#=== Targets ===
set(CALCULATOR_LIB_SOURCES
        ${PROJECT_SOURCE_DIR}/Calculator.cpp
        )
set(CALCULATOR_LIB_HEADERS
        ${PROJECT_INCLUDE_DIR}/Calculator.hpp
        ${PROJECT_INCLUDE_DIR}/DividedByZeroException.hpp
        )

add_library(calculator ${CALCULATOR_LIB_SOURCES} ${CALCULATOR_LIB_HEADERS})

# == main program using calculator ==
set(CALCULATOR_MAIN_SOURCES
        ${PROJECT_SOURCE_DIR}/main.cpp
        )
set(CALCULATOR_MAIN_HEADERS
        )

add_executable(main ${CALCULATOR_MAIN_SOURCES} ${CALCULATOR_MAIN_HEADERS})
target_link_libraries(main calculator)
