module a;
integer i;
b a_b1();
endmodule
module b;
integer i;
c b_c1(),
b_c2();
initial
#10 b_c1.i = 2;
endmodule
// downward path references two copies of i:
// a.a_b1.b_c1.i, d.d_b1.b_c1.i
module c;
integer i;
initial begin
i = 1;
//
//
//
//
//
b.i = 1;
end
endmodule
module d;
integer i;
b d_b1();
initial begin
a.i = 1;
a.a_b1.i = 2;
a.a_b1.b_c1.i = 3;
a.a_b1.b_c2.i = 4;
end
endmodule


task t;
int x;
x = f(1); // valid reference to function f in $unit scope
endtask
function int f(int y);
return y+1;
endfunction

