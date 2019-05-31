# Defines the CMake commands/policies
cmake_minimum_required(VERSION 3.10.0)

# Set the project name
project(HDLCONVERTOR)

# Java is used to generate source files for parsers, it is required only for installation
find_package(Java COMPONENTS Runtime REQUIRED)
include(UseJava)
find_package(PythonExtensions REQUIRED)
find_package(PythonLibs REQUIRED)
find_package(Cython REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT SKBUILD)
	message(STATUS "The project was ment to be used with scikit-build")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
	# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
	#set(ANTLR4_WITH_STATIC_CRT OFF)
	#set(WITH_STATIC_CRT)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -W -Wno-attributes")
endif()

add_subdirectory(src)
