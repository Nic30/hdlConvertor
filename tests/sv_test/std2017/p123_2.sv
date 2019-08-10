interface width_checker #(parameter min_cks = 1, parameter max_cks = 1)
(input logic clk, reset_n, expr);
generate
if ($isunbounded(max_cks)) begin
property width;
@(posedge clk)
(reset_n && $rose(expr)) |-> (expr [* min_cks]);
endproperty
a2: assert property (width);
end
else begin
property assert_width_p;
@(posedge clk)
(reset_n && $rose(expr)) |-> (expr[* min_cks:max_cks])
##1 (!expr);
endproperty
a2: assert property (width);
end
endgenerate
endinterface
