covergroup cg (ref logic [0:3] x, ref logic [0:7] y, ref logic [0:2] a);
xy: coverpoint {x,y};
coverpoint y;
XYA: cross xy, a
{
// the cross types are as if defined here as follows:
// typedef struct {logic [11:0] xy;logic [0:2] a;} CrossValType;
// typedef CrossValType CrossQueueType[$];
};
endgroup

covergroup cg;
coverpoint a { bins x[] = {[0:10]}; }
coverpoint b { bins y[] = {[0:20]}; }
aXb : cross a, b
{
bins one = '{ '{1,2}, '{3,4}, '{5,6} };
}
endgroup



module mod_m;
logic [31:0] a, b;
covergroup cg(int cg_lim);
coverpoint a;
coverpoint b;
aXb : cross a, b
{
function CrossQueueType myFunc1(int f_lim);
for (int i = 0; i < f_lim; ++i)
myFunc1.push_back('{i,i});
endfunction
bins one = myFunc1(cg_lim);
bins two = myFunc2(cg_lim);
function CrossQueueType myFunc2(logic [31:0] f_lim);
for (logic [31:0] i = 0; i < f_lim; ++i)
myFunc2.push_back('{2*i,2*i});
endfunction
}
endgroup
cg cg_inst = new(3);
endmodule



covergroup yy;
cross a, b
{
ignore_bins ignore = binsof(a) intersect { 5, [1:3] };
}
endgroup


