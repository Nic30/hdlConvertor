set(generateParsersVhdl_GENERATED_SRC
  ${PROJECT_SOURCE_DIR}/src/VhdlParser/vhdlBaseVisitor.cpp
  ${PROJECT_SOURCE_DIR}/src/VhdlParser/vhdlLexer.cpp
  ${PROJECT_SOURCE_DIR}/src/VhdlParser/vhdlParser.cpp
  ${PROJECT_SOURCE_DIR}/src/VhdlParser/vhdlVisitor.cpp
)
foreach( src_file ${generateParsersVhdl_GENERATED_SRC} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          GENERATED TRUE
          )
endforeach( src_file ${generateParsersVhdl_GENERATED_SRC} )

file(GLOB libparserVhdl_SRC
  "${HDLCONVERTOR_SOURCE_DIR}/src/vhdlConvertor/*.cpp"
)

add_custom_command(
  OUTPUT
  ${PROJECT_SOURCE_DIR}/src/VhdlParser/vhdlBaseVisitor.cpp
  ${PROJECT_SOURCE_DIR}/src/VhdlParser/vhdlLexer.cpp
  ${PROJECT_SOURCE_DIR}/src/VhdlParser/vhdlParser.cpp
  ${PROJECT_SOURCE_DIR}/src/VhdlParser/vhdlVisitor.cpp
  COMMAND
  ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/src/VhdlParser
  COMMAND
  "${Java_JAVA_EXECUTABLE}" -jar ${ANTLR_JAR_LOCATION} -Werror -Dlanguage=Cpp -visitor -no-listener -package vhdl -o ${PROJECT_SOURCE_DIR}/src/VhdlParser ${PROJECT_SOURCE_DIR}/grammars/vhdl.g4
  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
  DEPENDS ${PROJECT_SOURCE_DIR}/grammars/vhdl.g4
  COMMENT "build VHDLParser"
)

add_custom_target(generateParsersVhdl
  DEPENDS
  ${PROJECT_SOURCE_DIR}/src/VhdlParser/vhdlBaseVisitor.cpp
  ${PROJECT_SOURCE_DIR}/src/VhdlParser/vhdlLexer.cpp
  ${PROJECT_SOURCE_DIR}/src/VhdlParser/vhdlParser.cpp
  ${PROJECT_SOURCE_DIR}/src/VhdlParser/vhdlVisitor.cpp
)

include_directories(
  ${PROJECT_SOURCE_DIR}/src/VhdlParser
  ${PROJECT_SOURCE_DIR}/src/vhdlConvertor
)

set(parseVhdl_SRC
  ${libparserVhdl_SRC}
  ${generateParsersVhdl_GENERATED_SRC}
)

add_library(parsersVhdl_static STATIC ${parseVhdl_SRC})
add_dependencies(parsersVhdl_static generateParsersVhdl)
#target_link_libraries(parsersVhdl_static antlr4_shared)
set_target_properties(parsersVhdl_static
	PROPERTIES VERSION "1.0.0"
	OUTPUT_NAME parseVhdl
	POSITION_INDEPENDENT_CODE ON
)

