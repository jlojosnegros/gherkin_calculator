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
# == Controller library ==
set(CONTROLLER_LIB_SOURCES
        ${PROJECT_SOURCE_DIR}/ChainableController.cpp
        )
set(CONTROLLER_LIB_HEADERS
        ${PROJECT_INCLUDE_DIR}/GeneralMoveController.hpp
        ${PROJECT_INCLUDE_DIR}/ChainableController.hpp
        ${PROJECT_SOURCE_DIR}/ScopedState.hpp
        ${PROJECT_INCLUDE_DIR}/InformationHub.hpp
        ${PROJECT_INCLUDE_DIR}/ChainFactory.hpp
        ${PROJECT_INCLUDE_DIR}/ControllerFactory.hpp
        ${PROJECT_SOURCE_DIR}/ControllerFactory_impl.hpp
        ${PROJECT_INCLUDE_DIR}/ViewInterface.hpp
        ${PROJECT_SOURCE_DIR}/ViewInterface_impl.hpp
        ${PROJECT_INCLUDE_DIR}/ActionHandlerController.hpp
        ${PROJECT_SOURCE_DIR}/ActionHandlerController_impl.hpp
        ${PROJECT_INCLUDE_DIR}/ShowStatusController.hpp
        )

add_library(controller ${CONTROLLER_LIB_SOURCES} ${CONTROLLER_LIB_HEADERS})
add_dependencies(controller BetterEnums)
target_link_libraries(controller common)
