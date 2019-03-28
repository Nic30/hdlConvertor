GetAntlrParserFileNames("${CMAKE_CURRENT_SOURCE_DIR}" "vhdl" vhdlParsers_GENERATED_SRC)

file(GLOB libparserVhdl_SRC
  "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

AddParserToBuild("vhdl" vhdlParsers_GENERATED_SRC ${PARSER_GEN_ONLY_LISTENER})


set(parseVhdl_SRC
  ${libparserVhdl_SRC}
  ${vhdlParsers_GENERATED_SRC}
)

add_library(parsersVhdl_static STATIC ${parseVhdl_SRC})
target_include_directories(parsersVhdl_static 
	INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}
)
add_dependencies(parsersVhdl_static generateParsersvhdl)
#target_link_libraries(parsersVhdl_static antlr4_shared)
set_target_properties(parsersVhdl_static
	PROPERTIES VERSION "1.0.0"
	OUTPUT_NAME parseVhdl
	POSITION_INDEPENDENT_CODE ON
)

