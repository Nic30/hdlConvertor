module mh16([5:0] x, wire y);
// inout wire logic [5:0] x
// inout wire logic y
endmodule
module mh17(input var integer x, wire y); // input var integer x
// input wire logic y
endmodule
module mh18(output var x, input y);
// output var logic x
// input wire logic y
endmodule
module mh19(output signed [5:0] x, integer y);
// output wire logic signed [5:0] x
// output var integer y
endmodule
module mh20(ref [5:0] x, y); // ref var logic [5:0] x
// ref var logic [5:0] y
endmodule
module mh21(ref x [5:0], y); // ref var logic x [5:0]
// ref var logic y
endmodule

module mh22 (input wire integer p_a, .p_b(s_b), p_c);
logic [5:0] s_b;
endmodule
