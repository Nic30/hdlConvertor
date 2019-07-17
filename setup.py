from skbuild import setup

setup(
    cmake_args= [
        #'-DCMAKE_BUILD_TYPE=Debug'
    ],
    name='hdlConvertor',
    version='1.2',
    description='VHDL and System Verilog parser written in c++',
    url='https://github.com/Nic30/hdlConvertor',
    author='Michal Orsak',
    author_email='michal.o.socials@gmail.com',
    keywords=['hdl', 'vhdl', 'verilog', 'system verilog',
              'parser', 'preprocessor', 'antlr4'],
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'Intended Audience :: Science/Research',
        'Operating System :: OS Independent',
        'Topic :: Software Development :: Build Tools',
        'Programming Language :: C++',
        'Programming Language :: Python :: 2.7'
        'Programming Language :: Python :: 3',
    ],
    packages=['hdlConvertor', 'hdlConvertor/hdlAst'],
)
