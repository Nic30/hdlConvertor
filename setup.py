import distutils
from distutils.sysconfig import customize_compiler
import os
from setuptools import Extension, setup
from setuptools.command.build_ext import build_ext


def path_is_parent(parent_path, child_path):
    # Smooth out relative path names, note: if you are concerned about
    # symbolic links, you should use os.path.realpath too
    parent_path = os.path.abspath(parent_path)
    child_path = os.path.abspath(child_path)

    # Compare the common path of the parent and child path with the common
    # path of just the parent path. Using the commonpath method on just the
    # parent path will regularise the path name in the same way as the
    # comparison that deals with both paths, removing any trailing path
    # separator
    return (os.path.commonpath([parent_path]) ==
            os.path.commonpath([parent_path, child_path]))


class buildWithoutStrictPrototypes(build_ext):
    """
    Sorce code of this library is written in c++ strict-prototypes does not make sence for c++ compilation
    """

    def build_extensions(self):
        customize_compiler(self.compiler)
        # remove strict prototypes (useless for C++)
        try:
            self.compiler.compiler_so.remove("-Wstrict-prototypes")
        except (AttributeError, ValueError):
            pass

        # choose extra_compile_args for specified compiler
        compiler = self.compiler.compiler_type
        for ext in self.extensions:
            extra_args = []
            for compilerPrefix, compilerArgs in ext.extra_compile_args.items():
                if compiler.startswith(compilerPrefix):
                    extra_args.extend(compilerArgs)

            ext.extra_compile_args = extra_args

        build_ext.build_extensions(self)


# monkey-patch for parallel compilation
def parallelCCompile(self, sources, output_dir=None, macros=None, include_dirs=None,
                     debug=0, extra_preargs=None, extra_postargs=None, depends=None):
    # those lines are copied from distutils.ccompiler.CCompiler directly
    macros, objects, extra_postargs, pp_opts, build = self._setup_compile(
        output_dir, macros, include_dirs, sources, depends, extra_postargs)
    cc_args = self._get_cc_args(pp_opts, debug, extra_preargs)
    # parallel code
    import multiprocessing.pool
    N = multiprocessing.cpu_count()  # number of parallel compilations

    def _single_compile(obj):
        try:
            src, ext = build[obj]
        except KeyError:
            return
        self._compile(obj, src, ext, cc_args, extra_postargs, pp_opts)
    # convert to list, imap is evaluated on-demand
    list(multiprocessing.pool.ThreadPool(N).imap(_single_compile, objects))
    return objects


distutils.ccompiler.CCompiler.compile = parallelCCompile


def listFiles(baseDir):
    for root, dirs, files in os.walk(baseDir):
        for file in files:
            yield os.path.join(root, file)


def collectSourceFiles(baseDir, excludeDirs=[]):
    for file in listFiles(baseDir):
        if (file.endswith(".c") or file.endswith(".cpp"))\
                and not file.endswith("main.c"):
            # skip all files in exclude dirs
            for d in excludeDirs:
                if path_is_parent(d, file):
                    continue
            yield file


BASE_DIR = os.path.dirname(os.path.realpath(__file__))
BASE = os.path.join(BASE_DIR, "src/")
ANTLR4_BASE = BASE + "antlr4-runtime-cpp/"
ALL_SOURCE = list(collectSourceFiles(BASE,
                                     excludeDirs=[ANTLR4_BASE]))


hdlConvertor = Extension('hdlConvertor',
                         include_dirs=[ANTLR4_BASE],
                         # extra_compile_args=['-std=c++11'],
                         extra_compile_args={
                             #'msvc': [],
                             'unix': ['-std=c++11'],
                         },
                         define_macros=[("ANTLR4CPP_EXPORTS", 1),
                                        ],
                         sources=ALL_SOURCE,
                         language="c++",
                         )


setup(
    name='hdlConvertor',
    version='1.1',
    description='Vhdl and verilog parser written in c++, this module is primary used for hw_toolkit library for hdl manipulation',
    url='https://github.com/Nic30/hdlConvertor',
    author='Michal Orsak',
    author_email='michal.o.socials@gmail.com',
    # libraries=[antlr4],
    cmdclass={'build_ext': buildWithoutStrictPrototypes},
    ext_modules=[hdlConvertor],
    keywords=['vhdl', 'verilog', 'system verilog', 'parser', 'hdl'],
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'Intended Audience :: Science/Research',
        'Operating System :: OS Independent',
        'Topic :: Software Development :: Build Tools',
        'Programming Language :: C++',
        'Programming Language :: Python :: 3',
    ],
)
