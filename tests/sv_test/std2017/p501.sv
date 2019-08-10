checker check(bit clk1); // clk1 assigned in the Active region
rand bit v, w;
assign clk2 = clk1;
m1: assume property (@clk1 !(v && w));
m2: assume property (@clk2 v || w);
a1: assert property (@clk1 v != w);
// ...
endchecker : check
