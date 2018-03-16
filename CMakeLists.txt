cmake_minimum_required(VERSION 3.7)

#root project
project (gherkin_calculator)

SET(CMAKE_VERBOSE_MAKEFILE OFF)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Change the output folder to avoid pollute
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

# executables and libraries go in the same path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

#incluimos el directorio donde deberian quedar todas las librerias en la busqueda del compilador al linkar.
link_directories(${LIBRARY_OUTPUT_PATH})

# set include directory for common headers
SET(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/calculator)

# add include directories for all the subprojects
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")


enable_testing(true)

#add the subprojects folders
add_subdirectory(calculator)
add_subdirectory(specification)
