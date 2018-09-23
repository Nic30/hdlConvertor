# Defines the CMake commands/policies
cmake_minimum_required( VERSION 2.8.5 )

# Set the project name
project( HDLCONVERTOR )

# Java is not necessary if building without demos.
find_package(Java COMPONENTS Runtime REQUIRED)

if (NOT ANTLR_JAR_LOCATION)
  message(FATAL_ERROR "Missing antlr4.jar location. You can specify it's path using: -DANTLR_JAR_LOCATION=<path>")
else()
  get_filename_component(ANTLR_NAME ${ANTLR_JAR_LOCATION} NAME_WE)
  if(NOT EXISTS "${ANTLR_JAR_LOCATION}")
    message(FATAL_ERROR "Unable to find ${ANTLR_NAME} in ${ANTLR_JAR_LOCATION}")
  else()
    message(STATUS "Found ${ANTLR_NAME}: ${ANTLR_JAR_LOCATION}")
  endif()
endif()













# Make the scripts available in the 'cmake' directory available for the
# 'include()' command, 'find_package()' command.
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/cmake )

# Include the CMake script UseCython.cmake.  This defines add_cython_module().
# Instruction for use can be found at the top of cmake/UseCython.cmake.
include( UseCython )

# With CMake, a clean separation can be made between the source tree and the
# build tree.  When all source is compiled, as with pure C/C++, the source is
# no-longer needed in the build tree.  However, with pure *.py source, the
# source is processed directly.  To handle this, we reproduce the availability
# of the source files in the build tree.
add_custom_target( ReplicatePythonSourceTree ALL ${CMAKE_COMMAND} -P
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ReplicatePythonSourceTree.cmake
  ${CMAKE_CURRENT_BINARY_DIR}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )

include_directories( ${HDLCONVERTOR_SOURCE_DIR}/antlr4/runtime/src )

add_subdirectory( antlr4 )
add_subdirectory( src )
