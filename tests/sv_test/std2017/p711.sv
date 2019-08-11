module alu_accum1 (
output [15:0] dataout,
input [7:0] ain, bin,
input [2:0] opcode,
input clk, rst_n, rst);
wire [7:0] alu_out;
alu alu (alu_out, , ain, bin, opcode); // zero output is unconnected
accum accum (dataout[7:0], alu_out, clk, rst_n);
xtend xtend (dataout[15:8], alu_out[7], clk);
endmodule


module alu_accum2 (
output [15:0] dataout,
input [7:0] ain, bin,
input [2:0] opcode,
input clk, rst_n, rst);
wire [7:0] alu_out;
alu
alu
(.alu_out(alu_out), .zero(),
.ain(ain), .bin(bin), .opcode(opcode));
// zero output is unconnected
accum accum (.dataout(dataout[7:0]), .datain(alu_out),
.clk(clk));
// rst_n is not in the port list and so gets default value 1'b1
xtend xtend (.dout(dataout[15:8]), .din(alu_out[7]),
.clk(clk), .rst() );
// rst has a default value, but has an empty port connection,
// therefore it is left unconnected
endmodule

