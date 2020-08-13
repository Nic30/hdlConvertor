
#include(${CMAKE_CURRENT_SOURCE_DIR}../src/CMake_antlr4.txt)


file(GLOB hdlConvertor_py_SRC
  "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
include_directories(
	"${CMAKE_CURRENT_SOURCE_DIR}"
	"${CMAKE_CURRENT_SOURCE_DIR}/../include/"
	"${ANTLR4CPP_INCLUDE_DIRS}"
	${PYTHON_INCLUDE_DIRS}
)

add_cython_target(_hdlConvertor CXX)
add_library(_hdlConvertor MODULE ${_hdlConvertor}
								 ${hdlConvertor_py_SRC})
python_extension_module(_hdlConvertor)

target_link_libraries(_hdlConvertor
	hdlConvertor_cpp_static
)
if(CODE_COVERAGE)
	target_link_libraries(_hdlConvertor
		gcov
	)
endif()

set_coverage_if_enabled(_hdlConvertor OFF)


#set_target_properties(_hdlConvertor
#	PROPERTIES VERSION "1.0.0"
#	OUTPUT_NAME _hdlConvertor
#	LIBRARY_OUTPUT_DIRECTORY "${HDLCONVERTOR_SOURCE_DIR}/dist"
#	RUNTIME_OUTPUT_DIRECTORY "${HDLCONVERTOR_SOURCE_DIR}/dist"
#)

install(TARGETS _hdlConvertor LIBRARY DESTINATION
	hdlConvertor)
	
