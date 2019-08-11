module examples_with_default (input logic a, b, clk, rst, rst1);
default disable iff rst;
property p1;
disable iff (rst1) a |=> b;
endproperty
// Disable condition is rst1 - explicitly specified within a1
a1 : assert property (@(posedge clk) disable iff (rst1) a |=> b);
// Disable condition is rst1 - explicitly specified within p1
a2 : assert property (@(posedge clk) p1);
// Disable condition is rst - no explicit specification, inferred from
// default disable iff declaration
a3 : assert property (@(posedge clk) a |=> b);
// Disable condition is 1'b0. This is the only way to
// cancel the effect of default disable.
a4 : assert property (@(posedge clk) disable iff (1'b0) a |=> b);
endmodule
module examples_without_default (input logic a, b, clk, rst);
property p2;
disable iff (rst) a |=> b;
endproperty
// Disable condition is rst - explicitly specified within a5
a5 : assert property (@(posedge clk) disable iff (rst) a |=> b);
// Disable condition is rst - explicitly specified within p2
a6 : assert property (@ (posedge clk) p2);
// No disable condition
a7 : assert property (@ (posedge clk) a |=> b);
endmodule
