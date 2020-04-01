# Tutorial for developing of C++ python extension with Cython and Scikit-build

# Basic project setup in Eclipse (eclipse + CDT -> C/C++ project)
(Note that we will use python3-dbg, if you want to use python3/2 you have to recompile.
 Without -dbg you will mostly see only segfaults without explanation if there is some problem.)
* in eclise.ini increase memory available for eclise or c++ indexing will be very slow (1min+)
   `-Xms1024 -Xmx4096m` or more depending on how many plugins in eclipse you have installed.

(Note that there python3.7 is used you may have to change this version if required.)
* `sudo apt install python3-dev python3-dbg`
* create a C/C++ project from this repo (or add C++ nature to Python project)
* project properties ->
   * C/C++ General -> Paths and Symbols -> add Python and ANTLR include dir (for all lags)
  ```
  /usr/include/python3.7m
  /usr/include/antlr4-runtime

  ```
   * C/C++ build ->
       * Build command: `python3-dbg setup.py -j8` (-j8 for build with 8 concurrent process)
       * uncheck Generate makefile automatically
       * set build directory to project root
       * in Behavior tab change target Build (increamental) from "all" to "build"

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
        src/verilogConvertor/sv2017Parser/                   \
        src/verilogPreproc/verilogPreprocParser/                  \
        src/svConvertor/sv2012Parser/                             \
        include/hdlConvertor/svConvertor/sv2012Parser/            \
        include/hdlConvertor/verilogPreproc/verilogPreprocParser/ \
        include/hdlConvertor/vhdlConvertor/vhdlParser/ -r
     ```

# Debuging in Eclipse
* apt install python3-dbg # because normal python crashes on some errors without reporting (like undefined symbol in c library)
* new debug configuration -> C++ Application
	* C/C++ Aplication: `/usr/bin/python3-dbg`
	* Arguments: $NAME_OF_YOUR_SCRIPT etc
	* enviroment add: `PYTHONPATH` `$PYTHONPATH:${project_path:hdlConvertor}/_skbuild/linux-x86_64-3.7/setuptools/lib`
	* in CMakeLists.txt add  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
	  to enable debuging build and disable optimisations
	* now break points in c++ and all other debuging stuff should work as expected


# Utils
* c++filt - progam which translates ugly cpp compiled names back to readable form
  ```
  $ c++filt _ZN12hdlConvertor8ToString4dumpEPKNS_10hdlObjects7iHdlObjEi
  hdlConvertor::ToString::dump(hdlConvertor::hdlObjects::iHdlObj const*, int)
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
