# Tutorial for developing of C++ python extension with Cython and Scikit-build

# Building a Debug Version of C++ python extension as a the pip package

1. Create a Python Virtual Env.:

   ```sh
   python -m venv hdlConvertorVenv
   ```

2. Activate the virtual env and install `scikit-build` and `CPython` using [requirements.txt](https://github.com/Nic30/hdlConvertor/blob/master/requirements.txt) from the base repo path:
   ```sh
   . ./hdlConvertorVenv/bin/activate
   cd hdlConvertor
   pip install -r requirements.txt
   ```

3. Setup Debug Configuration for `sciki-build`:
   ```sh
   export SKBUILD_CONFIGURE_OPTIONS="-DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON"
   ```
   For ANTLR4 custom build installation configuration:
   ```sh
   # Add Configuration from above if building in Debug Mode
   export SKBUILD_CONFIGURE_OPTIONS="-DANTLR4CPP_ROOT=<Path to antlr4-cpp-runtime build/installation> ..."
   export ANTLR_COMPLETE_PATH=<Absolute path to the directory where antlr4-complete.jar exists>
   # e.g.:
   # export SKBUILD_CONFIGURE_OPTIONS="-DANTLR4CPP_ROOT=/opt/antlr4/antlr4-cpp-runtime"
   # export ANTLR_COMPLETE_PATH="/opt/antlr4"

   ## The above path should have the 'antlr4-complete.jar' available at that directory.
   # Also if the ANTLR4 Cpp Runtime is custom build one might need to add the library path to 'LD_LIBRARY_PATH'
   ## e.g.:
   ## export LD_LIBRARY_PATH=/opt/antlr4/antlr4-cpp-runtime/lib:$LD_LIBRARY_PATH
   ```
4. Use Python `pip` build and install the package in edit mode:
   ```sh
   # Use Python VirtualEnv for installation.
   python -m pip install -e .
   ```

5. Optional Step if you are also developing for `hdlConvertorAst` install the package locally as editable version of the package:
   ```sh
   # Use the same virtualenv for both of these packages
   git clone https://github.com/Nic30/hdlConvertorAst
   cd hdlConvertorAst
   pip install -e .
   ```
# Test execution

In order to run tests you need to have all dependencies installed or appended in python path so python can import it.
If you downloaded the hdlConvertorAst git to same directory where you have a hdlConvertor you can append it to python path like this:
```
hdlConvertor.git$ export PYTHONPATH=PYTHONPATH:$PWD/../hdlConvertorAst
```

The tests are python module on it's own that means it needs to be executed as python module:
```
hdlConvertor.git$ python3 -m tests.all
```
Note that `python3 tests/all.py` would ended up with an import error as python would not know that the tests are supposed to be a module.

Test-cases for external projects do support `SUCESSFULL_TEST_FILTER_FILE` this test-case configuration spots a file with passed test names
and if test-case is executed again the tests mentioned in this file are not executed. This is very useful if something is broken and you are fixing it
as this feature automatically runs only broken stuff in each run and you do need to wait for passing test over and over.

Tests for external projects are handled by generate_external_testcase_class, this method generates `unittest.TestCase` class
for files and configs specified.

Rest of the test is usually based on [HdlParseTC](https://github.com/Nic30/hdlConvertor/blob/master/tests/hdl_parse_tc.py#L74).
This class contains a methods which simplifies the parsing/conversion test scenario.


# Basic project setup in Eclipse (eclipse + CDT -> C/C++ project)
(Note that we will use python3-dbg, if you want to use python3/2 you have to recompile.
 Without -dbg you will mostly see only segfaults without explanation if there is some problem in c++ symbol definition after linking.)
* in eclise.ini increase memory available for eclise or c++ indexing will be very slow (1min+)
   `-Xms1024 -Xmx4096m` or more depending on how many plugins in eclipse you have installed.

(Note that there python3.7 is used you may have to change this version if required.)
* `sudo apt install python3-dev python3-dbg`
* create a C/C++ project from this repo (or add C++ nature to Python project)
* or C/C++ makefile project, it odes not matter, we will override build command anyway
* project properties ->
   * C/C++ General -> Paths and Symbols -> add Python and ANTLR include dir (for all lags)
  ```
  /usr/include/python3.8m
  /usr/include/antlr4-runtime

  ```
   * C/C++ build ->
       * Build command: `python3-dbg setup.py `
       * uncheck Generate makefile automatically
       * set build directory to project root
       * in Behavior tab change target Build (increamental) from "all" to "build -j8 --build-type Debug"
			(-j8 for build with 8 concurrent process)
   * in place debuggin (if you just run `python3 setup.py build` the library with c-extension is not accessible)
     you need to copy or link library to it's package folder
     ```
     cd hdlConvertor
     ln ../_skbuild/linux-*/setuptools/lib/hdlConvertor/_hdlConvertor.*.so . -s
	 ```
   * for cmake.version < 3.15 automatic delete of generated files not working for ninja use:
   	 (only if something is seriously broken)
     ```
     rm src/vhdlConvertor/vhdlParser/                             \
        src/verilogConvertor/sv2017Parser/                        \
        src/verilogPreproc/verilogPreprocParser/                  \
        src/svConvertor/sv2012Parser/                             \
        include/hdlConvertor/svConvertor/sv2012Parser/            \
        include/hdlConvertor/verilogPreproc/verilogPreprocParser/ \
        include/hdlConvertor/vhdlConvertor/vhdlParser/ -r
     ```
   * Now add a pydev nature to this project so we can use code navigation and autocomplete for python. Right-Click on project -> PyDev -> add project; Then add "." and "hdlConvertor" direcotories in to PYTHONPATH in project properties -> PyDev - PYTHONPATH 


# Debuging C++ part of module in Eclipse
* apt install python3-dbg # because normal python crashes on some errors without reporting (like undefined symbol in c library)
* new debug configuration -> C++ Application
	* C/C++ Aplication: `/usr/bin/python3-dbg`
	* Arguments: $NAME_OF_YOUR_SCRIPT etc
	* enviroment add: `PYTHONPATH` `$PYTHONPATH:${project_path:hdlConvertor}/_skbuild/linux-x86_64-3.8/setuptools/lib`
	* in CMakeLists.txt add  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
	  to enable debuging build and disable optimisations
	* now break points in c++ and all other debuging stuff should work as expected


# Utils
* c++filt - progam which translates ugly cpp compiled names back to readable form
  ```
  $ c++filt _ZN12hdlConvertor8ToString4dumpEPKNS_10hdlAst7iHdlObjEi
  hdlConvertor::ToString::dump(hdlConvertor::hdlAst::iHdlObj const*, int)
  ```
* to forece regeneration of generated files delete cmake file which
  tells cmake that the files were generated e.g. `rm _skbuild/linux-x86_64-3.7/cmake-build/src/vhdlConvertor/vhdlParsers_GENERATED_SRC`

* antlr4 gui - visualize a parse tree
   ```
   CLASSPATH=/usr/share/java/stringtemplate4.jar:/usr/share/java/antlr4.jar:/usr/share/java/antlr4-runtime.jar:/usr/share/java/antlr3-runtime.jar/:/usr/share/java/treelayout.jar
   mkdir gen && cd gen
   antlr4 ../vhdl.g4 && mv ../*.java ../*.tokens ../*.interp . \
      && javac -cp $CLASSPATH vhdl*.java                       \
      && java -cp $CLASSPATH:$PWD "org.antlr.v4.gui.TestRig" vhdl design_file -gui ../../tests/vhdl/mux.vhd -help -diagnostics -trace -tokens
   ```
   * note that for composite grammars (*Lexer.g4 + *Parser.g4) bout grammars should be agument of antlr4
     and the name of grammar for org.antlr.v4.gui.TestRig is name without Parser/lexer.

# Adding a new C++ HDL object class

* Define the class in a header file with extension `.h` in the directory `include/hdlConvertor/hdlAst`.
* Define the implementation in a source file with extension `.cpp` in the directory `src/hdlAst`.
* Create a corresponding Python class in one of the files (pick the best match) in `hdlConvertorAst/hdlAst`.
** Add the names of your Python object properties to the `__slots__` list.  Often this list will be the same as the list of your C++ object member variables.
* Add the import for your class in `hdlConvertorAst/hdlAst/__init__.py`.
* Add a pointer for your Python class in the Python C++ extension header file `hdlConvertor/toPy.h` in the `ToPy` class.  There's a big list just past the includes, you can't miss it.
* Add an import for your Python class in the Python C++ extension source file `hdlConvertor/toPy.cpp` in the `ToPy::ToPy()` constructor.  It's the first method definition in the file.
* Decrement the reference to your Python class in `hdlConvertor/toPy.cpp` in the `ToPy::~ToPy()` destructor.  Dereferences should be in the opposite order of imports.
* Add code to `toPy.cpp` to convert your C++ data structure into the corresponding Python type.  This probably requires a new overload of the `toPy` function declared in `toPy.h`.
** Use `toPy_property(py_inst, "py_property_name", cpp_obj)` to set the property `py_property_name` on the Python object `py_inst` to the value `cpp_obj` (which will also be converted to a Python object).  There are lots of examples of this.
* Add conversion logic to 'hdlConveertor/to/json.py'.
* Add conversion logic to other language converters.
