Windows Installation Guide for hdlConverter
--------------------------------------------
*In order to install hdlConverter, either Visual Studio or another C++ compiler is required as well as CMake. *

- Additionally, due to the use of MSBuild in these examples, you'll want to have Visual Studio added to your path. An
example of how this can be done for Visual Studio 2019 is by adding
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\MSBuild\Current\Bin" to your PATH in environment
variables.

You can reference the .appveyor.yml file located at https://github.com/Nic30/hdlConvertor.git for installation
instructions as well as this document.
(AppveyorCI is a continuous integration service and it checks the build with each commit.
You can check the build output from clicking on the badge in the readme.)

- In the following example, Visual Studio 16 2019 (-G "Visual Studio 16 2019") is used as the GENERATOR variable in CMake
while x64 (-A x64) is used as the ARCHITECTURE variable. These can both also be seen from the .appveyor.yml file.

- Note that you can define variable in windows cmd line using ``set PYTHON=c:\Python3_9`` etc.

- ``%PYTHON%\\python.exe`` refers to the terminal command for Python 3 or the complete path to Python 3's executable

To begin, you'll need to download https://www.antlr.org/download/antlr-4.9-complete.jar and rename it to
'antlr4-complete.jar'. After you've downloaded the jar file, clone the hdlConverter repository using
``git clone https://github.com/Nic30/hdlConvertor.git``. Next, navigate to the root directory of the hdlConverter
repository that you've just cloned and run the following commands:

.. code-block::

    pip3 install git+https://github.com/Nic30/hdlConvertorAst.git
    git clone https://github.com/antlr/antlr4
    cd antlr4/runtime/Cpp
    git checkout 4.9
    mkdir build
    cd build
    cmake -G"Visual Studio 16 2019" -A x64 -DWITH_STATIC_CRT=Off -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="C:\Program Files\LIBANTLR4" ..
    msbuild LIBANTLR4.sln /p:configuration=Release /p:platform=x64
    cmake -P cmake_install.cmake

Lastly, for installation, return to the root directory of the hdlConverter repo. This should be accessible via:

.. code-block::

    cd ../../../../


Once you return to the root directory, run:

.. code-block::

    %PYTHON%\\python.exe -m pip install jupyter git+https://github.com/Nic30/hdlConvertorAst.git
    %PYTHON%\\python.exe -m pip install -r requirements.txt

Finally, to build and install the library:

.. code-block::

    %PYTHON%\\python.exe setup.py install -- -DJava_JAR_PATHS="C:\\The_Directory_Containing_The_JAR_File" -DANTLR4CPP_ROOT="C:\\Program Files\\LIBANTLR4" -G"Visual Studio 16 2019" -A x64

Note that if you run the python in hdlConvertor root directory just after installation the python will import the hdlConvertor directory instead
installed and module. Thus you will recieve some import errors about missing library which is build from c++.
In order to prevent that you can delete or rename hdlConvertor direcotory or you can run python in a different folder.

.. code-block::

    rmdir /s /q hdlConvertor
