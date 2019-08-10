module test(a,b,c,d,e,f,g,h);
input [7:0] a;
input [7:0] b;
input signed [7:0] c;
input signed [7:0] d;
output [7:0] e;
output [7:0] f;
output signed [7:0] g;
output signed [7:0] h; //
wire signed [7:0] b; //
wire [7:0] c;
logic signed [7:0] f;//
logic [7:0] g;
endmodule


module complex_ports( {c,d}, .e(f) );
endmodule

module split_ports (a[7:4], a[3:0]);
endmodule

module same_port (.a(i), .b(i));
endmodule


