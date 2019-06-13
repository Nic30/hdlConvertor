##############################################################################################
# build of the main library
##############################################################################################

include(${CMAKE_CURRENT_SOURCE_DIR}/CMake_antlr4.txt)

include_directories(
	"${CMAKE_CURRENT_SOURCE_DIR}/../include/")

add_subdirectory(svConvertor)
add_subdirectory(verilogConvertor)
add_subdirectory(verilogPreproc)
add_subdirectory(vhdlConvertor)

file(GLOB hdlConvertor_core_SRC
	"${CMAKE_CURRENT_SOURCE_DIR}/hdlObjects/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/baseHdlParser/*.cpp"
)

list(APPEND hdlConvertor_core_SRC
	"${CMAKE_CURRENT_SOURCE_DIR}/notImplementedLogger.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/syntaxErrorLogger.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/conversion_exception.cpp"
)

set(hdlConvertor_cpp_SRC
	"${CMAKE_CURRENT_SOURCE_DIR}/convertor.cpp"
)

add_library(hdlConvertor_core_static STATIC  ${hdlConvertor_core_SRC})
target_include_directories(hdlConvertor_core_static
	INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}/../include/"
)
set_target_properties(hdlConvertor_core_static
	PROPERTIES VERSION "1.0.0"
	OUTPUT_NAME hdlConvertor_core
	POSITION_INDEPENDENT_CODE ON
)

# [note] hdlConvertor_core_static and hdlConvertor_cpp_static has to be separated
#        otherwise it is not possible to link this library
add_library(hdlConvertor_cpp_static STATIC  ${hdlConvertor_cpp_SRC})
target_link_libraries(hdlConvertor_cpp_static
	svConvertor_static
	verilogConvertor_static
	verilogPreproc_static
	vhdlConvertor_static
	hdlConvertor_core_static
	${ANTLR4CPP_LIBRARIES}
)
set_target_properties(hdlConvertor_cpp_static
	PROPERTIES VERSION "1.0.0"
	OUTPUT_NAME hdlConvertor_cpp
	POSITION_INDEPENDENT_CODE ON
)
