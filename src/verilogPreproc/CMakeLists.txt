
file(GLOB libparserverilogPreproc_SRC
  "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

GetAntlrParserFileNames("${CMAKE_CURRENT_SOURCE_DIR}" "verilogPreproc"
                        verilogPreprocParsers_GENERATED_SRC)

add_custom_command(
  OUTPUT
  ${verilogPreprocParsers_GENERATED_SRC}
  COMMAND
  "${Java_JAVA_EXECUTABLE}" -jar ${ANTLR_JAR_LOCATION} -Werror -Dlanguage=Cpp -listener -o
  	${CMAKE_CURRENT_SOURCE_DIR}/verilogPreprocParser
  	${PROJECT_SOURCE_DIR}/grammars/verilogPreproc.g4
  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
  DEPENDS ${PROJECT_SOURCE_DIR}/grammars/verilogPreproc.g4
)

add_custom_target(generateParsersVerilogPreproc
  DEPENDS
  ${verilogPreprocParsers_GENERATED_SRC}
)

add_library(parsersVerilogPreproc_static STATIC 
	${libparserverilogPreproc_SRC}
	${verilogPreprocParsers_GENERATED_SRC}
)
target_include_directories(parsersVerilogPreproc_static
  INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/verilogPreprocParser
)
add_dependencies(parsersVerilogPreproc_static generateParsersVerilogPreproc)

set_target_properties(parsersVerilogPreproc_static
	PROPERTIES VERSION "1.0.0"
	OUTPUT_NAME verilogPreproc
	POSITION_INDEPENDENT_CODE ON
)
