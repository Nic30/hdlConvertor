
#include "../verilogPreproc/macro_replace_sv.h"

macro_replace_sv::macro_replace_sv(std::string macro_name, std::string replace, std::vector<std::string> arg, std::map<std::string,std::string> default_maps): macro_replace(macro_name,replace,arg) {
	_default_map = default_maps;
}

std::string macro_replace_sv::replace() {
  std::vector<std::string> null_vector;
  return replace(null_vector);
}

std::string macro_replace_sv::replace(std::vector<std::string> arg) {
    /*
    printf("---------------\n");
    for (auto a:arg) {
      printf("  =%s*\n",a.c_str());
    }
    
    for (auto a:_default_map) {
      printf("%s : %s\n",a.first.c_str(),a.second.c_str());
    }
    printf("---------------\n");

    */
    std::string returnString;

    if (arg.size() < data.args.size()) {
       for(unsigned long int i = arg.size(); i < data.args.size(); i++ ) {
         auto missing_arg = _default_map.find(data.args[i]);
	 if (missing_arg != _default_map.end()) {
	   arg.push_back(missing_arg->second);
	 }
         else {
	   goto exit_label;
	 }
       }
    }
    exit_label: 

    if (!data.tmplate.empty()) {
      returnString = data.tmplate;

      //printf("before replacement: %s\n",returnString.c_str());

      if (arg.size() != data.args.size()) {
        std::string message =  "Missmatch in number of argument macro declaration "
	       +data.tmplate_name +" (" + 
          std::to_string(data.args.size()) + 
          ") and macro usage ("+std::to_string(arg.size())+')';
        throw parseException(message);
      }

      // the number of provided argument is fewer than the number defined by the prototype.
      // So we complete the list with default value.
      if (arg.size() < data.args.size()) {
         unsigned int i;
	 if (arg.size()>0) {
	  i = arg.size();
	 }
	 else {
	  i =0;
	 }

	 for (; i < data.args.size(); i++) {
           if (_default_map.find(data.args[i]) == _default_map.end() ) {
	    //throw
	   }
	   arg.push_back(_default_map[data.args[i]]);
	 }
      } else if (arg.size() > data.args.size()) {
        //throw
      }

      _substituate.clear();
      look4stringLiteral(returnString);

      std::vector<std::string>::iterator macro= data.args.begin();
      std::vector<std::string>::iterator instance = arg.begin();
      for ( ; macro != data.args.end(); macro++, instance++) {
	std::string rpld_argument = *instance;
	// if no argument was provided we use the default argument
	if (rpld_argument == "" && _default_map.find(*macro)!= _default_map.end()){
	  rpld_argument = _default_map[*macro];
	}
	//printf("%s@%s@%s\n",returnString.c_str(),(*macro).c_str(),rpld_argument.c_str() );
        replaceAll(returnString,*macro,rpld_argument);
      }
      //printf("after replacement: %s\n",returnString.c_str());
    }
    else {
      //Macro can be empty
      //Example `define MODE1
      returnString = "";
    }
    return returnString;

}
