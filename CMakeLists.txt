# Defines the CMake commands/policies
cmake_minimum_required(VERSION 3.10.0)

# Set the project name
project(libhdlConvertor)

# Java is used to generate source files for parsers, it is required only for installation
find_package(Java COMPONENTS Runtime REQUIRED)
include(UseJava)

if(SKBUILD)
	set(HDLCONVERTOR_PYTHON ON)
endif()

if(HDLCONVERTOR_PYTHON)
	message(STATUS "Building python hdlConvertor module with libhdlConvertor linked in")
	find_package(PythonExtensions REQUIRED)
	find_package(PythonLibs REQUIRED)
	find_package(Cython REQUIRED)
else()
	message(STATUS "Building libhdlConvertor (C++ lib) only, to build python module use setup.py.")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
	# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
	#set(ANTLR4_WITH_STATIC_CRT OFF)
	#set(WITH_STATIC_CRT)
elseif(CMAKE_SYSTEM_NAME MATCHES "CYGWIN")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -W -Wno-attributes")
endif()

set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "ON")
option(CODE_COVERAGE "Enable coverage reporting" OFF)

add_subdirectory(src)

if(HDLCONVERTOR_PYTHON)
	add_subdirectory(hdlConvertor)
else()
	SET(CPACK_GENERATOR "DEB")
	SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Michal Orsak <michal.o.socials@gmail.com>")
	SET(CPACK_DEBIAN_PACKAGE_HOMEPAGE "https://github.com/Nic30/hdlConvertor")
	SET(CPACK_DEBIAN_PACKAGE_DEPENDS "uuid-dev, libantlr4-runtime-dev, antlr4")
	INCLUDE(CPack)
endif()


