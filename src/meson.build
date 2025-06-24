
##############################################################################################
# build of main library
##############################################################################################
hdlConvertor_core_src = [
	'notImplementedLogger.cpp',
	'syntaxErrorLogger.cpp',
	'conversion_exception.cpp',
	'universal_fs.cpp',
	'encodingConversions.cpp',
]
hdlConvertor_core_src += run_command(py3, '../utils/rec_glob.py', './hdlAst', '*.cpp', check:true)\
	.stdout().strip().split('\n')
hdlConvertor_core_src += run_command(py3, '../utils/rec_glob.py', './baseHdlParser', '*.cpp', check:true)\
	.stdout().strip().split('\n')

hdlConvertor_core_static_lib = static_library('hdlConvertor_core_static',
    hdlConvertor_core_src,
    cpp_args: EXTRA_CXX_FLAGS,
    dependencies: [antlr4_cpp_dep, all_parser_deps],
    include_directories: [mainIncludeDir_inc],
    #link_with: [libtracker_common],
)
# my_inc = include_directories(...)
# my_lib = static_library(...)
# my_dep = declare_dependency(link_with : my_lib, include_directories : my_inc)

hdlConvertor_cpp_src = [
	'hdlConvertor.cpp'
]
if get_option('python_package')
	# [note] hdlConvertor_core_static and hdlConvertor_cpp_static has to be separated
	#        otherwise it is not possible to link this library
	hdlConvertor_cpp_static = static_library('hdlConvertor_cpp_static',
    	hdlConvertor_cpp_src,
	    cpp_args: EXTRA_CXX_FLAGS,
	    dependencies: [antlr4_cpp_dep, all_parser_deps],
	    include_directories: [mainIncludeDir_inc],
	    link_with: [hdlConvertor_core_static_lib, all_parser_libs],
	)
	hdlConvertor_cpp_dep = declare_dependency(link_with : hdlConvertor_cpp_static)
else
	# add dummy file to make cmake happy
	hdlConvertor_cpp_shared = shared_library('hdlConvertor_cpp_shared',
		hdlConvertor_cpp_src,
	 	cpp_args: EXTRA_CXX_FLAGS,
	    dependencies: [antlr4_cpp_dep, ] + all_parser_deps,
	    include_directories: [mainIncludeDir_inc],
	    link_with: [hdlConvertor_core_static_lib, all_parser_libs],
	)
	hdlConvertor_cpp_dep = declare_dependency(link_with : hdlConvertor_cpp_shared)
endif

