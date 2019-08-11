typedef real T;
class C;
typedef int T;
extern function T f();
extern function real f2();
endclass
function C::T C::f();
return 1;
endfunction
// the return must use the class scope resolution
// operator, since the type is defined within the
// class
function real C::f2();
return 1.0;
endfunction
