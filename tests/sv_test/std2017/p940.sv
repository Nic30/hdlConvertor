export "DPI-C" f_plus = function \f+ ; // "f+" exported as "f_plus"             
export "DPI-C" function f; // "f" exported under its own name                   
import "DPI-C" init_1 = function void \init[1] (); // "init_1" is a linkage name
import "DPI-C" \begin = function void \init[2] (); // "begin" is a linkage name 
 
