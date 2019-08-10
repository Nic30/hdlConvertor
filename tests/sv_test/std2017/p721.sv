extern module m (a,b,c,d);
extern module a #(parameter size = 8, parameter type TP = logic [7:0])
(input [size:0] a, output TP b);
module m (.*);
input a,b,c;
output d;
endmodule
module a (.*);
endmodule


module m (a,b,c,d);
input a,b,c;
output d;
endmodule
module a #(parameter size = 8, parameter type TP = logic [7:0])
(input [size:0] a, output TP b);
endmodule
