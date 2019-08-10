typedef int T;
// T and int are matching data types.
class C;
virtual function C some_method(int a); endfunction
endclass
class D extends C;
virtual function D some_method(T a); endfunction
endclass
class E #(type Y = logic) extends C;
virtual function D some_method(Y a); endfunction
endclass
