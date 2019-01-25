#pragma once

#include <antlr4-runtime.h>
#include <string>
#include <vector>

/**
 *  class that represent the macro name and  the list of argument
 */
class macroPrototype {
  public:
    std::string macroName;
    std::vector<std::string> args;
    macroPrototype(std::string macroName, std::vector<std::string> args):
      macroName(macroName),
      args(args) {
      }
};

