module alu_accum3 (
output [15:0] dataout,
input [7:0] ain, bin,
input [2:0] opcode,
input clk, rst_n);
wire [7:0] alu_out;
alu
alu
(.alu_out, .zero(), .ain, .bin, .opcode);
accum accum (.dataout(dataout[7:0]), .datain(alu_out), .clk, .rst_n());
xtend xtend (.dout(dataout[15:8]), .din(alu_out[7]), .clk, .rst);
// Error: rst does not exist in the instantiation module
endmodule
