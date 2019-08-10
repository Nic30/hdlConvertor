module gray2bin1 (bin, gray);
parameter SIZE = 8;
// this module is parameterizable
output [SIZE-1:0] bin;
input [SIZE-1:0] gray;
genvar i;
generate
for (i=0; i<SIZE; i=i+1) begin:bitnum
assign bin[i] = ^gray[SIZE-1:i];
// i refers to the implicitly defined localparam whose
// value in each instance of the generate block is
// the value of the genvar when it was elaborated.
end
endgenerate
endmodule

module addergen1 (co, sum, a, b, ci);
parameter SIZE = 4;
output [SIZE-1:0] sum;
output
co;
input [SIZE-1:0] a, b;
input
ci;
wire
[SIZE :0] c;
wire
[SIZE-1:0] t [1:3];
genvar
i;
assign c[0] = ci;
for(i=0; i<SIZE; i=i+1) begin:bitnum
xor g1 ( t[1][i],
a[i],
b[i]);
xor g2 ( sum[i], t[1][i],
c[i]);
and g3 ( t[2][i],
a[i],
b[i]);
and g4 ( t[3][i], t[1][i],
c[i]);
or
g5 (
c[i+1], t[2][i], t[3][i]);
end
assign co = c[SIZE];
endmodule
