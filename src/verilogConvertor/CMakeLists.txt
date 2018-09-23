set(generateParsersVerilog_GENERATED_SRC
  ${PROJECT_SOURCE_DIR}/src/VerilogParser/Verilog2001BaseVisitor.cpp
  ${PROJECT_SOURCE_DIR}/src/VerilogParser/Verilog2001Lexer.cpp
  ${PROJECT_SOURCE_DIR}/src/VerilogParser/Verilog2001Parser.cpp
  ${PROJECT_SOURCE_DIR}/src/VerilogParser/Verilog2001Visitor.cpp
)
foreach( src_file ${generateParsersVerilog_GENERATED_SRC} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          GENERATED TRUE
          )
endforeach( src_file ${generateParsersVerilog_GENERATED_SRC} )


file(GLOB libparserVerilog_SRC
  "${HDLCONVERTOR_SOURCE_DIR}/src/verilogConvertor/*.cpp"
)

add_custom_command(
  OUTPUT
  ${PROJECT_SOURCE_DIR}/src/VerilogParser/Verilog2001BaseVisitor.cpp
  ${PROJECT_SOURCE_DIR}/src/VerilogParser/Verilog2001Lexer.cpp
  ${PROJECT_SOURCE_DIR}/src/VerilogParser/Verilog2001Parser.cpp
  ${PROJECT_SOURCE_DIR}/src/VerilogParser/Verilog2001Visitor.cpp
  COMMAND
  ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/src/VerilogParser
  COMMAND
  "${Java_JAVA_EXECUTABLE}" -jar ${ANTLR_JAR_LOCATION} -Werror -Dlanguage=Cpp -visitor -no-listener -package verilog -o ${PROJECT_SOURCE_DIR}/src/VerilogParser ${PROJECT_SOURCE_DIR}/grammars/Verilog2001.g4
  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
  DEPENDS ${PROJECT_SOURCE_DIR}/grammars/Verilog2001.g4
  COMMENT "build VerilogParser"
)

add_custom_target(generateParsersVerilog
  DEPENDS
  ${PROJECT_SOURCE_DIR}/src/VerilogParser/Verilog2001BaseVisitor.cpp
  ${PROJECT_SOURCE_DIR}/src/VerilogParser/Verilog2001Lexer.cpp
  ${PROJECT_SOURCE_DIR}/src/VerilogParser/Verilog2001Parser.cpp
  ${PROJECT_SOURCE_DIR}/src/VerilogParser/Verilog2001Visitor.cpp
)

include_directories(
  ${PROJECT_SOURCE_DIR}/src/VerilogParser
  ${PROJECT_SOURCE_DIR}/src/verilogConvertor
)

set(parseVerilog_SRC
  ${libparserVerilog_SRC}
  ${generateParsersVerilog_GENERATED_SRC}
)
add_library(parsersVerilog_shared SHARED ${parseVerilog_SRC})
add_dependencies(parsersVerilog_shared generateParsersVerilog)
set_target_properties(parsersVerilog_shared
	PROPERTIES VERSION "1.0.0"
	OUTPUT_NAME parseVerilog
        LIBRARY_OUTPUT_DIRECTORY "${HDLCONVERTOR_SOURCE_DIR}/dist"
	RUNTIME_OUTPUT_DIRECTORY "${HDLCONVERTOR_SOURCE_DIR}/dist"
)
