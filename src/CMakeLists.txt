##############################################################################################
# build of the main library
##############################################################################################

include(${CMAKE_CURRENT_SOURCE_DIR}/CMake_antlr4.txt)

include_directories(
	"${CMAKE_CURRENT_SOURCE_DIR}/../include/")

add_subdirectory(svConvertor)
add_subdirectory(verilogPreproc)
add_subdirectory(vhdlConvertor)

file(GLOB hdlConvertor_core_SRC
	"${CMAKE_CURRENT_SOURCE_DIR}/hdlAst/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/baseHdlParser/*.cpp"
)

list(APPEND hdlConvertor_core_SRC
	"${CMAKE_CURRENT_SOURCE_DIR}/notImplementedLogger.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/syntaxErrorLogger.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/conversion_exception.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/universal_fs.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/encodingConversions.cpp"
)
set(hdlConvertor_cpp_SRC
	"${CMAKE_CURRENT_SOURCE_DIR}/hdlConvertor.cpp"
)
add_library(hdlConvertor_core_static STATIC ${hdlConvertor_core_SRC})
target_include_directories(hdlConvertor_core_static
	INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}/../include/"
)
set_target_properties(hdlConvertor_core_static
	PROPERTIES VERSION "1.0.0"
	OUTPUT_NAME hdlConvertor_core
	POSITION_INDEPENDENT_CODE ON
)
set_coverage_if_enabled(hdlConvertor_core_static ON)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	set(CPP_STD_FILESYSTEM_LIB_NAME c++experimental)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set(CPP_STD_FILESYSTEM_LIB_NAME stdc++fs)
endif()


set(HDL_CONVERTOR_INTERNAL_LIBS 
	svConvertor_static
	verilogPreproc_static
	vhdlConvertor_static
	hdlConvertor_core_static
)

if(HDLCONVERTOR_PYTHON)
	# [note] hdlConvertor_core_static and hdlConvertor_cpp_static has to be separated
	#        otherwise it is not possible to link this library
	add_library(hdlConvertor_cpp_static STATIC ${hdlConvertor_cpp_SRC})
	set_coverage_if_enabled(hdlConvertor_cpp_static ON)

	target_link_libraries(hdlConvertor_cpp_static PUBLIC
		${HDL_CONVERTOR_INTERNAL_LIBS}
		${ANTLR4CPP_LIBRARIES}
		${CPP_STD_FILESYSTEM_LIB_NAME}
	)

	set_target_properties(hdlConvertor_cpp_static
		PROPERTIES VERSION "1.0.0"
		OUTPUT_NAME "hdlConvertor_cpp"
		POSITION_INDEPENDENT_CODE ON
	)
else()
	# add dummy file to make cmake happy
	add_library(hdlConvertor_cpp_shared SHARED ${hdlConvertor_cpp_SRC})
	set_target_properties(hdlConvertor_cpp_shared
		PROPERTIES VERSION "1.0.0"
		OUTPUT_NAME "hdlConvertor"
		# POSITION_INDEPENDENT_CODE ON
	)
	target_link_libraries(hdlConvertor_cpp_shared
		PRIVATE
	    "-Wl,--whole-archive"
		${HDL_CONVERTOR_INTERNAL_LIBS}
	    "-Wl,--no-whole-archive"
	)
	target_link_libraries(hdlConvertor_cpp_shared
		INTERFACE
		${ANTLR4CPP_LIBRARIES}
		${CPP_STD_FILESYSTEM_LIB_NAME}
	)
	set_coverage_if_enabled(hdlConvertor_cpp_shared ON)
	if(CODE_COVERAGE)
		target_link_libraries(hdlConvertor_cpp_shared PRIVATE gcov)
	endif()
	install(TARGETS hdlConvertor_cpp_shared
		EXPORT hdlConvertorConfig
		LIBRARY DESTINATION lib
  		# ARCHIVE DESTINATION lib
  		# FILES DESTINATION include ${CMAKE_INSTALL_INCLUDEDIR}
  		# PUBLIC_HEADER DESTINATION include
  	)
  	install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../include/"
  	        DESTINATION include ${CMAKE_INSTALL_INCLUDEDIR})
  	# This makes the project importable from the install directory
	# Put config file in per-project dir (name MUST match), can also
	# just go into 'cmake'.
	install(EXPORT hdlConvertorConfig DESTINATION share/hdlConvertor/cmake)
	
	# This makes the project importable from the build directory
	export(TARGETS hdlConvertor_cpp_shared FILE hdlConvertorConfig.cmake)
	set(MAIN_HDLCONVERTOR_LIB hdlConvertor_cpp_shared)
	if(CODE_COVERAGE)
		if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
		  # Add required flags (GCC & LLVM/Clang)
		  target_compile_options(${MAIN_HDLCONVERTOR_LIB} PUBLIC
		    -O0        # no optimization
		    -g         # generate debug info
		    --coverage # sets all required flags
		  )
		  target_link_libraries(${MAIN_HDLCONVERTOR_LIB} gcov)
		  if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
		    target_link_options(${MAIN_HDLCONVERTOR_LIB} INTERFACE --coverage)
		  else()
		    target_link_libraries(${MAIN_HDLCONVERTOR_LIB} INTERFACE --coverage)
		  endif()
		else()
		  message(ERROR "Code coverage supported only for gcc/clang compiler (current ${CMAKE_CXX_COMPILER_ID})")
		endif()
	endif()
endif()

