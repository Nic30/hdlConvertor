#include "../verilogPreproc/macro_replace.h"


macro_replace::macro_replace(std::string replace, std::vector<std::string> arg){
	data.tmplate = replace;
	data.args = arg;
}

macro_replace::~macro_replace() {
}

void macro_replace::replaceAll(std::string& str, const std::string& from, const std::string& to) {
  if(from.empty())
    return;
  size_t start_pos = 0;
  while((start_pos = str.find(from, start_pos)) != std::string::npos) {
    /* 	
        printf("-->%s\n",str.c_str());
        printf("-->%li %li\n",start_pos,from.length());
        printf("-->%s\n",to.c_str());
        */
    if( !(
          (('a' <= str[start_pos+from.length()]) && (str[start_pos+from.length()] <='z')) ||
          (('A' <= str[start_pos+from.length()]) && (str[start_pos+from.length()] <='Z')) ||
          (('0' <= str[start_pos+from.length()]) && (str[start_pos+from.length()] <='9')) ||
          ('_' == str[start_pos+from.length()]) || ('$' == str[start_pos+from.length()])
          )
      ) {
      /*
       * Test what is next character. If next character is part of [a-zA-Z0-9_$] then it is not what we have to replace.
       * 19.3.1 `define
       * The text specified for macro text shall not be split across the following lexical tokens:
       *   Comments
       *   Numbers
       *   Strings
       *   Identifiers
       *   Keywords
       *   Operators
       * */
      str.replace(start_pos, from.length(), to);
    }
    start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
  }
}

std::string macro_replace::replace(std::vector<std::string> arg) {

    std::string returnString;

    if (!data.tmplate.empty()) {
      returnString = data.tmplate;

      if (arg.size() != data.args.size()) {
        std::string message =  "Missmatch in number of argument macro declaration (" + 
          std::to_string(arg.size()) + 
          ") and macro usage ("+std::to_string(data.args.size())+')';
        throw parseException(message);
      }
      std::vector<std::string>::iterator macro= data.args.begin();
      std::vector<std::string>::iterator instance = arg.begin();
      for ( ; macro != data.args.end(); macro++, instance++) {
        replaceAll(returnString,*macro,*instance);
      }
    }
    else {
      //Macro can be empty
      //Example `define MODE1
      returnString = "";
    }
    return returnString;

}

std::string macro_replace::macro_replace::replace() {
  std::vector<std::string> null_vector;
  return replace(null_vector);
}
