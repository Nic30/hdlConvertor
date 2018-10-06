
##############################################################################################

include_directories(
  ${HDLCONVERTOR_SOURCE_DIR}/src
)

set(generateParsers_GENERATED_SRC
	${PROJECT_SOURCE_DIR}/src/vpp/symbolBaseListener.cpp
	${PROJECT_SOURCE_DIR}/src/vpp/symbolLexer.cpp
	${PROJECT_SOURCE_DIR}/src/vpp/symbolListener.cpp
	${PROJECT_SOURCE_DIR}/src/vpp/symbolParser.cpp
	${PROJECT_SOURCE_DIR}/src/vpp/vppBaseListener.cpp
	${PROJECT_SOURCE_DIR}/src/vpp/vppLexer.cpp
	${PROJECT_SOURCE_DIR}/src/vpp/vppListener.cpp
	${PROJECT_SOURCE_DIR}/src/vpp/vppParser.cpp
)

foreach( src_file ${generateParsers_GENERATED_SRC} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          GENERATED TRUE
          )
endforeach( src_file ${generateParsers_GENERATED_SRC} )

add_custom_command(
  OUTPUT
  ${PROJECT_SOURCE_DIR}/src/vpp/symbolBaseListener.cpp
  ${PROJECT_SOURCE_DIR}/src/vpp/symbolLexer.cpp
  ${PROJECT_SOURCE_DIR}/src/vpp/symbolListener.cpp
  ${PROJECT_SOURCE_DIR}/src/vpp/symbolParser.cpp
  ${PROJECT_SOURCE_DIR}/src/vpp/vppBaseListener.cpp
  ${PROJECT_SOURCE_DIR}/src/vpp/vppLexer.cpp
  ${PROJECT_SOURCE_DIR}/src/vpp/vppListener.cpp
  ${PROJECT_SOURCE_DIR}/src/vpp/vppParser.cpp
  COMMAND
  ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/src/vpp
  COMMAND
  "${Java_JAVA_EXECUTABLE}" -jar ${ANTLR_JAR_LOCATION} -Werror -Dlanguage=Cpp -listener -o ${PROJECT_SOURCE_DIR}/src/vpp ${PROJECT_SOURCE_DIR}/grammars/vpp.g4
  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
  DEPENDS ${PROJECT_SOURCE_DIR}/grammars/vpp.g4
  COMMAND
  "${Java_JAVA_EXECUTABLE}" -jar ${ANTLR_JAR_LOCATION} -Werror -Dlanguage=Cpp -listener -o ${PROJECT_SOURCE_DIR}/src/vpp ${PROJECT_SOURCE_DIR}/grammars/symbol.g4
  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
  DEPENDS ${PROJECT_SOURCE_DIR}/grammars/symbol.g4
)

add_custom_target(generateParsers
  DEPENDS
  ${PROJECT_SOURCE_DIR}/src/vpp/symbolBaseListener.cpp
  ${PROJECT_SOURCE_DIR}/src/vpp/symbolLexer.cpp
  ${PROJECT_SOURCE_DIR}/src/vpp/symbolListener.cpp
  ${PROJECT_SOURCE_DIR}/src/vpp/symbolParser.cpp
  ${PROJECT_SOURCE_DIR}/src/vpp/vppBaseListener.cpp
  ${PROJECT_SOURCE_DIR}/src/vpp/vppLexer.cpp
  ${PROJECT_SOURCE_DIR}/src/vpp/vppListener.cpp
)

file(GLOB libhdlconvertor_SRC
  "${HDLCONVERTOR_SOURCE_DIR}/src/hdlObjects/*.cpp"
  "${HDLCONVERTOR_SOURCE_DIR}/src/baseHdlParser/*.cpp"
  "${HDLCONVERTOR_SOURCE_DIR}/src/hdlConvertor/*.cpp"
  "${HDLCONVERTOR_SOURCE_DIR}/src/vPreprocessor/*.cpp"
  "${HDLCONVERTOR_SOURCE_DIR}/src/*.cpp"
)

add_cython_target(hdlConvertor CXX)
add_library(hdlConvertor MODULE ${hdlConvertor} ${libhdlconvertor_SRC} ${generateParsers_GENERATED_SRC} )
add_dependencies(hdlConvertor generateParsers)
python_extension_module(hdlConvertor)

target_link_libraries(hdlConvertor antlr4_static parsersSV_static parsersVerilog_static parsersVhdl_static)
#target_link_libraries(hdlConvertor antlr4_shared parsersVerilog_shared )
set_target_properties(hdlConvertor
	PROPERTIES VERSION "1.0.0"
	OUTPUT_NAME hdlConvertor
	LIBRARY_OUTPUT_DIRECTORY "${HDLCONVERTOR_SOURCE_DIR}/hdlConvertor"
	RUNTIME_OUTPUT_DIRECTORY "${HDLCONVERTOR_SOURCE_DIR}/hdlConvertor"
)

install(FILES $<TARGET_FILE:hdlConvertor>
	DESTINATION .)

add_subdirectory(svConverter)
add_subdirectory(verilogConvertor)
add_subdirectory(vhdlConvertor)
