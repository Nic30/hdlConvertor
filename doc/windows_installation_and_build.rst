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
You can check the build output from clicking on the badge in the readme.
But the problem is that free plan does not have enough RAM to build this project.)

- In the following example, Visual Studio 16 2019 (-G "Visual Studio 16 2019") is used as the GENERATOR variable in CMake
while x64 (-A x64) is used as the ARCHITECTURE variable. These can both also be seen from the .appveyor.yml file.

- Note that you can define variable in windows cmd line using ``set PYTHON=c:\Python3_9`` etc.

- ``%PYTHON%\\python.exe`` refers to the terminal command for Python 3 or the complete path to Python 3's executable


Once you are in the root directory, run:

.. code-block::

    %PYTHON%\\python.exe -m pip install git+https://github.com/Nic30/hdlConvertorAst.git build
    %PYTHON%\\python.exe -m pip install -r requirements.txt

Finally, to build and install the library:

.. code-block::

    %PYTHON%\\python.exe -m pip3 install .
    

Note that if you run the python in hdlConvertor root directory just after installation the python will import the hdlConvertor directory instead
installed and module. Thus you will recieve some import errors about missing library which is build from c++.
In order to prevent that you can delete or rename hdlConvertor direcotory or you can run python in a different folder.

.. code-block::

    rmdir /s /q hdlConvertor
