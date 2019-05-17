
GetAntlrParserFileNames("${CMAKE_CURRENT_SOURCE_DIR}" "verilogPreproc" verilogPreprocParsers_GENERATED_SRC)

file(GLOB libparserverilogPreproc_SRC
  "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

AddParserToBuildWithLexer("verilogPreproc" verilogPreprocParsers_GENERATED_SRC)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
	#Suppress warnings on generated code.
	set_property(SOURCE ${verilogPreprocParsers_GENERATED_SRC} PROPERTY COMPILE_FLAGS -Wno-unused-parameter)
endif()

add_library(parsersVerilogPreproc_static STATIC 
	${libparserverilogPreproc_SRC}
	${verilogPreprocParsers_GENERATED_SRC}
)
target_include_directories(parsersVerilogPreproc_static
  INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/verilogPreprocParser
)
add_dependencies(parsersVerilogPreproc_static generateParsersverilogPreproc)

set_target_properties(parsersVerilogPreproc_static
	PROPERTIES VERSION "1.0.0"
	OUTPUT_NAME verilogPreproc
	POSITION_INDEPENDENT_CODE ON
)
