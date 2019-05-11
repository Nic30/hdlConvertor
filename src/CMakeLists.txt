
##############################################################################################
# utils
##############################################################################################

function(GetAntlrParserFileNamesSpecDir root name result dir_prefix)
	set(result_tmp
		${root}/${dir_prefix}Parser/${name}Lexer.cpp
		${root}/${dir_prefix}Parser/${name}Parser.cpp
	)

	foreach( src_file ${result_tmp} )
	      set_source_files_properties(
	          ${src_file}
	          PROPERTIES
	          GENERATED TRUE
	      )
	endforeach()
	set(${result} "${result_tmp}" PARENT_SCOPE)
endfunction()

macro(GetAntlrParserFileNames root name result)
	GetAntlrParserFileNamesSpecDir(${root} ${name} ${result} ${name})
endmacro()


set(PARSER_GEN_ONLY_VISITOR "-visitor" "-no-listener")
set(PARSER_GEN_ONLY_LISTENER "-listener" "-no-visitor")

macro(AddParserToBuild name sources parser_gen_ops)
	add_custom_command(
	  OUTPUT
	  "${sources}"
	  COMMAND
	  ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_SOURCE_DIR}/${name}Parser
	  COMMAND
	  "${Java_JAVA_EXECUTABLE}" -jar ${ANTLR_JAR_LOCATION} -Werror -Dlanguage=Cpp ${parser_gen_ops} -package "${name}_antlr" -encoding utf-8 -o ${CMAKE_CURRENT_SOURCE_DIR}/${name}Parser ${PROJECT_SOURCE_DIR}/grammars/${name}.g4
	  COMMAND
	  ${CMAKE_COMMAND} -E touch "${CMAKE_CURRENT_BINARY_DIR}/${sources}"
	  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
	  DEPENDS ${PROJECT_SOURCE_DIR}/grammars/${name}.g4
	  COMMENT "build ${name}Parser"
	)
	add_custom_target(generateParsers${name}
	  DEPENDS
	  ${sources}
	)
endmacro()
##############################################################################################
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(
  ${HDLCONVERTOR_SOURCE_DIR}/src
)

add_subdirectory(svConverter)
add_subdirectory(verilogConvertor)
add_subdirectory(verilogPreproc)
add_subdirectory(vhdlConvertor)


file(GLOB libhdlConvertor_SRC
  "${HDLCONVERTOR_SOURCE_DIR}/src/hdlObjects/*.cpp"
  "${HDLCONVERTOR_SOURCE_DIR}/src/baseHdlParser/*.cpp"
  "${HDLCONVERTOR_SOURCE_DIR}/src/hdlConvertor/*.cpp"
  "${HDLCONVERTOR_SOURCE_DIR}/src/*.cpp"
)

add_cython_target(_hdlConvertor CXX)
add_library(_hdlConvertor MODULE ${_hdlConvertor}
								${libhdlConvertor_SRC})
python_extension_module(_hdlConvertor)

target_link_libraries(_hdlConvertor 
	parsersSV_static
	parsersVerilog_static
	parsersVerilogPreproc_static
	parsersVhdl_static
	antlr4_static
)

#set_target_properties(_hdlConvertor
#	PROPERTIES VERSION "1.0.0"
#	OUTPUT_NAME _hdlConvertor
#	LIBRARY_OUTPUT_DIRECTORY "${HDLCONVERTOR_SOURCE_DIR}/dist"
#	RUNTIME_OUTPUT_DIRECTORY "${HDLCONVERTOR_SOURCE_DIR}/dist"
#)

install(TARGETS _hdlConvertor LIBRARY DESTINATION src)

