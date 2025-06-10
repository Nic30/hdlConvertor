
# install all python sources
py_sources = run_command(py3, '../utils/rec_glob.py', '.', '*.py', check:true)\
    .stdout().strip().split('\n')

# mark sources of a single module for an installation
py3.install_sources(
    py_sources,
    pure: false, # Will be installed next to binaries
    subdir: 'hdlConvertor',  # Folder relative to site-packages to install to
)

_hdlConvertor_cpp_sources = [
	'toPy_expr.cpp',
	'toPy_statements.cpp',
	'toPy_type.cpp',
	'toPy.cpp',
	'toPy.h',
]

py3.extension_module(
    '_hdlConvertor',
    _hdlConvertor_cpp_sources + ['_hdlConvertor.pyx'], # , 'python_ver_independent_str.pyx', 'verilogPreproc.pyx'
    include_directories: [mainIncludeDir_inc],
    dependencies : [py3_dep, antlr4_cpp_dep, hdlConvertor_cpp_dep],
    install: true,
    cpp_args: EXTRA_CXX_FLAGS,
    override_options : ['cython_language=cpp'],
    subdir: 'hdlConvertor/',
)

#file(GLOB hdlConvertor_py_SRC
#  "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
#)
#include_directories(
#	"${CMAKE_CURRENT_SOURCE_DIR}"
#	"${CMAKE_CURRENT_SOURCE_DIR}/../include/"
#)


	
