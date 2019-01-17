GetAntlrParserFileNames("${CMAKE_CURRENT_SOURCE_DIR}" "sv2012" generateParsersSV_GENERATED_SRC)

file(GLOB libparserSV_SRC
  "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

AddParserToBuild("sv2012" generateParsersSV_GENERATED_SRC ${PARSER_GEN_ONLY_LISTENER})

set(parseSV_SRC
  ${libparserSV_SRC}
  ${generateParsersSV_GENERATED_SRC}
)

add_library(parsersSV_static STATIC ${parseSV_SRC})
target_include_directories(parsersSV_static INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
add_dependencies(parsersSV_static generateParserssv2012)
#target_link_libraries(parsersSV_static antlr4_shared)
set_target_properties(parsersSV_static
	PROPERTIES VERSION "1.0.0"
	OUTPUT_NAME parsesv
	POSITION_INDEPENDENT_CODE ON
)
