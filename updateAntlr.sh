rm -rf antlr4
git clone https://github.com/antlr/antlr4.git
rm -rf src/antlr4-runtime-cpp
cp -r antlr4/runtime/Cpp/runtime/src/ src/antlr4-runtime-cpp
#rm -r antlr4
