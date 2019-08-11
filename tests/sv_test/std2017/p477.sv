module examples_with_default (input logic a, b, c, clk);
property q1;
$rose(a) |-> ##[1:5] b;
endproperty
property q2;
@(posedge clk) q1;
endproperty
default clocking posedge_clk @(posedge clk);
property q3;
$fell(c) |=> q1;
// legal: q1 has no clocking event
endproperty
property q4;
$fell(c) |=> q2;
// legal: q2 has clocking event identical to that of
// the clocking block
endproperty
sequence s1;
@(posedge clk) b[*3];
// illegal: explicit clocking event in clocking block
endsequence
endclocking
property q5;
@(negedge clk) b[*3] |=> !b;
endproperty
always @(negedge clk)
begin
a1: assert property ($fell(c) |=> q1);
// legal: contextually inferred leading clocking event,
// @(negedge clk)
a2: assert property (posedge_clk.q4);
// legal: will be queued (pending) on negedge clk, then
// (if matured) checked at next posedge clk (see 16.14.6)
a4: assert property (q5);
// legal: contextually inferred leading clocking event,
// @(negedge clk)
end
property q6;
q1 and q5;

endproperty
a6: assert property ($fell(c) |=> q6);
// legal: default leading clocking event, @(posedge clk),
// is the unique semantic leading clock
sequence s2;
$rose(a) ##[1:5] b;
endsequence
c1: cover property (s2);
// legal: default leading clocking event, @(posedge clk)
c2: cover property (@(negedge clk) s2);
// legal: explicit leading clocking event, @(negedge clk)
endmodule
