##############################################################################################
# build of the main library
##############################################################################################

include(${CMAKE_CURRENT_SOURCE_DIR}/CMake_antlr4.txt)

include_directories(
	${PYTHON_INCLUDE_DIRS}
	"${CMAKE_CURRENT_SOURCE_DIR}/../include/")

add_subdirectory(svConvertor)
add_subdirectory(verilogConvertor)
add_subdirectory(verilogPreproc)
add_subdirectory(vhdlConvertor)

file(GLOB hdlConvertor_cpp_SRC
	"${CMAKE_CURRENT_SOURCE_DIR}/hdlObjects/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/baseHdlParser/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(hdlConvertor_cpp_static STATIC ${hdlConvertor_cpp_SRC})
target_include_directories(parsersVhdl_static
	INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}/../include/"
	${PYTHON_INCLUDE_DIRS}
)

set_target_properties(hdlConvertor_cpp_static
	PROPERTIES VERSION "1.0.0"
	OUTPUT_NAME hdlConvertor_cpp
	POSITION_INDEPENDENT_CODE ON
)

set(hdlConvertor_LIBS
	parsersSV_static
	parsersVerilog_static
	parsersVerilogPreproc_static
	parsersVhdl_static
	hdlConvertor_cpp
	${ANTLR4CPP_LIBRARIES}
)

