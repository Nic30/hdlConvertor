module examples_without_default (input logic a, b, c, clk);
property q1;
$rose(a) |-> ##[1:5] b;
endproperty
property q5;
@(negedge clk) b[*3] |=> !b;
endproperty
property q6;
q1 and q5;
endproperty
a5: assert property (q6);
// illegal: no leading clocking event
a6: assert property ($fell(c) |=> q6);
// illegal: no leading clocking event
sequence s2;
$rose(a) ##[1:5] b;
endsequence
c1: cover property (s2);
// illegal: no leading clocking event
c2: cover property (@(negedge clk) s2);
// legal: explicit leading clocking event, @(negedge clk)
sequence s3;
@(negedge clk) s2;
endsequence
c3: cover property (s3);
// legal: leading clocking event, @(negedge clk),
// determined from declaration of s3
c4: cover property (s3 ##1 b);
// illegal: no default, inferred, or explicit leading
// clocking event and maximal property is not an instance
endmodule
