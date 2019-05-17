##############################################################################################
# antlr4 settings
##############################################################################################
# there are two types of distribution the all in one antlr4-complete.jar or group of antrl4 jars 
find_jar(_ANTLR_JAR_LOCATION_antlr4_complete "antlr4-complete" 
	PATHS "/usr/share/java/antlr4-complete.jar"
		  "antlr4-complete.jar")
if(_ANTLR_JAR_LOCATION_antlr4_complete) 
	MESSAGE(STATUS "using antlr4-complete.jar found in ${_ANTLR_JAR_LOCATION_antlr4_complete}")
	set(ANTLR_CLASSPATH "${_ANTLR_JAR_LOCATION_antlr4_complete}")
else()
	set(ANTLR_CLASSPATH "")
	set(ANTLR_JARS "stringtemplate4;antlr4;antlr4-runtime;antlr3-runtime;treelayout")
	FOREACH(antlr_jar ${ANTLR_JARS})
	  find_jar(_ANTLR_JAR_LOCATION_${antlr_jar} "${antlr_jar}" 
	  		PATHS "/usr/share/java/${antlr_jar}.jar")
	  set(_ANTLR_JAR_LOCATION ${_ANTLR_JAR_LOCATION_${antlr_jar}})
	  MESSAGE(STATUS "using ${antlr_jar} found in ${_ANTLR_JAR_LOCATION}")
	  if (NOT _ANTLR_JAR_LOCATION)
	    MESSAGE(FATAL_ERROR "Can not find ${antlr_jar}")	 
	  endif()
	  if(ANTLR_CLASSPATH)
	  	set(ANTLR_CLASSPATH "${ANTLR_CLASSPATH}:${_ANTLR_JAR_LOCATION}")
	  else()
	  	set(ANTLR_CLASSPATH "${_ANTLR_JAR_LOCATION}")
	  endif()
	ENDFOREACH()
endif()

# search for antlr4 include dir and library
if(ANTLR4CPP_ROOT)
	MESSAGE(STATUS "Antlr4 cpp runtime root set to: ${ANTLR4CPP_ROOT}")
endif()
find_path(ANTLR4CPP_INCLUDE_DIRS antlr4-runtime.h 
	HINTS "${ANTLR4CPP_ROOT}/usr/include/antlr4-runtime/"
	      "${ANTLR4CPP_ROOT}/include/antlr4-runtime/"
    PATH_SUFFIXES antlr4-runtime)
if(NOT ANTLR4CPP_INCLUDE_DIRS)
	MESSAGE(FATAL_ERROR "Can not find ANTLR4CPP_INCLUDE_DIRS")
else()
	MESSAGE(STATUS "ANTLR4CPP_INCLUDE_DIRS=${ANTLR4CPP_INCLUDE_DIRS}")
endif()
include_directories(${ANTLR4CPP_INCLUDE_DIRS})

find_library(ANTLR4CPP_LIBRARIES libantlr4-runtime.so antlr4-runtime-static.lib
    HINTS "${ANTLR4CPP_ROOT}/usr/lib"
          "${ANTLR4CPP_ROOT}/lib")
if(NOT ANTLR4CPP_LIBRARIES)
	MESSAGE(FATAL_ERROR "Can not find ANTLR4CPP_LIBRARIES")
else()
	MESSAGE(STATUS "ANTLR4CPP_LIBRARIES=${ANTLR4CPP_LIBRARIES}")
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	add_compile_definitions(ANTLR4CPP_STATIC)
endif()

##############################################################################################
# antlr4 utils
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
	  "${Java_JAVA_EXECUTABLE}" -cp "${ANTLR_CLASSPATH}" "org.antlr.v4.Tool" 
	  -Dlanguage=Cpp ${parser_gen_ops} -package ${name}_antlr -encoding utf-8 
	  -o ${CMAKE_CURRENT_SOURCE_DIR}/${name}Parser 
	  ${PROJECT_SOURCE_DIR}/grammars/${name}.g4
	  COMMAND
	  ${CMAKE_COMMAND} -E touch "${CMAKE_CURRENT_BINARY_DIR}/${sources}"
	  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
	  DEPENDS ${PROJECT_SOURCE_DIR}/grammars/${name}.g4
	  COMMENT "generating sources for ${name}Parser"
	)
	add_custom_target(generateParsers${name}
	  DEPENDS
	  ${sources}
	)
endmacro()

macro(AddParserToBuildWithLexer name sources)
    add_custom_command(
      OUTPUT
      "${sources}"
      COMMAND
	  ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_SOURCE_DIR}/${name}Parser
      COMMAND
        "${Java_JAVA_EXECUTABLE}" -cp "${ANTLR_CLASSPATH}" "org.antlr.v4.Tool" 
        -Dlanguage=Cpp -visitor -o ${CMAKE_CURRENT_SOURCE_DIR}/${name}Parser 
        ${PROJECT_SOURCE_DIR}/grammars/${name}Lexer.g4 
        ${PROJECT_SOURCE_DIR}/grammars/${name}Parser.g4
      WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
      DEPENDS ${PROJECT_SOURCE_DIR}/grammars/${name}Parser.g4 ${PROJECT_SOURCE_DIR}/grammars/${name}Lexer.g4
      COMMENT "generating sources for ${name}Parser"
    )
    add_custom_target(generateParsers${name}
      DEPENDS
      ${sources}
    )
endmacro()

##############################################################################################
# build of the main python module
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
	${ANTLR4CPP_LIBRARIES}
)

#set_target_properties(_hdlConvertor
#	PROPERTIES VERSION "1.0.0"
#	OUTPUT_NAME _hdlConvertor
#	LIBRARY_OUTPUT_DIRECTORY "${HDLCONVERTOR_SOURCE_DIR}/dist"
#	RUNTIME_OUTPUT_DIRECTORY "${HDLCONVERTOR_SOURCE_DIR}/dist"
#)

install(TARGETS _hdlConvertor LIBRARY DESTINATION src)

