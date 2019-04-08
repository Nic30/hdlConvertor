# Defines the CMake commands/policies
cmake_minimum_required( VERSION 3.10.0 )

# Set the project name
project( HDLCONVERTOR )

# Java is not necessary if building without demos.
find_package(Java COMPONENTS Runtime REQUIRED)
find_package(PythonExtensions REQUIRED)
find_package(PythonLibs REQUIRED)
find_package(Cython REQUIRED)


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

include_directories( ${HDLCONVERTOR_SOURCE_DIR}/antlr4/runtime/src )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(MSVC_VERSION)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Za")
endif()
 
add_subdirectory( antlr4 )
add_subdirectory( src )
