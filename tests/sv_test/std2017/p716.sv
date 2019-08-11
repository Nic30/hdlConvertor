module child(output o, input i[5]);
//...
endmodule : child
module parent(output o[8][4],
input i[8][4][5] );
child c[8][4](o,i);
//...
endmodule : parent

module MxN_pipeline #(M=3,N=4)
(input [M-1:0] in, output [M-1:0] out, input clk);
typedef logic T [M-1:0][1:N];
T Ins, Outs;
DFF dff[M-1:0][1:N](Outs, Ins, clk);
for (genvar I = M-1; I >= 0; I--) begin
for (genvar J = 1; J <= N; J++) begin
case (J)
1: begin
assign out[I] = Outs[I][1];
assign Ins[I][J] = Outs[I][2];
end
default: assign Ins[I][J] = Outs[I][J+1];
N: assign Ins[I][N] = in[I];
endcase
end
end
endmodule : MxN_pipeline
