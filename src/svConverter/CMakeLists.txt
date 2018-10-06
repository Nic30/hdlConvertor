set(generateParsersSV_GENERATED_SRC
  ${PROJECT_SOURCE_DIR}/src/SVParser/sv2012BaseVisitor.cpp
  ${PROJECT_SOURCE_DIR}/src/SVParser/sv2012Lexer.cpp
  ${PROJECT_SOURCE_DIR}/src/SVParser/sv2012Parser.cpp
  ${PROJECT_SOURCE_DIR}/src/SVParser/sv2012Visitor.cpp
)
foreach( src_file ${generateParsersSV_GENERATED_SRC} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          GENERATED TRUE
          )
endforeach( src_file ${generateParsersSV_GENERATED_SRC} )

file(GLOB libparserSV_SRC
  "${HDLCONVERTOR_SOURCE_DIR}/src/svConverter/*.cpp"
)

add_custom_command(
  OUTPUT
  ${PROJECT_SOURCE_DIR}/src/SVParser/sv2012BaseVisitor.cpp
  ${PROJECT_SOURCE_DIR}/src/SVParser/sv2012Lexer.cpp
  ${PROJECT_SOURCE_DIR}/src/SVParser/sv2012Parser.cpp
  ${PROJECT_SOURCE_DIR}/src/SVParser/sv2012Visitor.cpp
  COMMAND
  ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/src/SVParser
  COMMAND
  "${Java_JAVA_EXECUTABLE}" -jar ${ANTLR_JAR_LOCATION} -Werror -Dlanguage=Cpp -visitor -no-listener -package sv -o ${PROJECT_SOURCE_DIR}/src/SVParser ${PROJECT_SOURCE_DIR}/grammars/sv2012.g4
  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
  DEPENDS ${PROJECT_SOURCE_DIR}/grammars/sv2012.g4
  COMMENT "build SVParser"
)

add_custom_target(generateParsersSV
  DEPENDS
  ${PROJECT_SOURCE_DIR}/src/SVParser/sv2012BaseVisitor.cpp
  ${PROJECT_SOURCE_DIR}/src/SVParser/sv2012Lexer.cpp
  ${PROJECT_SOURCE_DIR}/src/SVParser/sv2012Parser.cpp
  ${PROJECT_SOURCE_DIR}/src/SVParser/sv2012Visitor.cpp
)

include_directories(
  ${PROJECT_SOURCE_DIR}/src/SVParser
  ${PROJECT_SOURCE_DIR}/src/svConverter
)
set(parseSV_SRC
  ${libparserSV_SRC}
  ${generateParsersSV_GENERATED_SRC}
)
add_library(parsersSV_static STATIC ${parseSV_SRC})
add_dependencies(parsersSV_static generateParsersSV)
#target_link_libraries(parsersSV_static antlr4_shared)
set_target_properties(parsersSV_static
	PROPERTIES VERSION "1.0.0"
	OUTPUT_NAME parsesv
	POSITION_INDEPENDENT_CODE ON
)
