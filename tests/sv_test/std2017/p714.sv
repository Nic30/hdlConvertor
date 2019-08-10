module alu_accum4 (
output [15:0] dataout,
input [7:0] ain, bin,
input [2:0] opcode,
input clk);
wire [7:0] alu_out;
alu
alu
(.*, .zero());
accum accum (.*, .dataout(dataout[7:0]), .datain(alu_out));
xtend xtend (.*, .dout(dataout[15:8]), .din(alu_out[7]));
endmodule

module alu_accum5 (
output [15:0] dataout,
input [7:0] ain, bin,
input [2:0] opcode,
input clk, rst_n);
wire [7:0] alu_out;
// mixture of named port connections and
// implicit .name port connections
alu alu (.ain(ain), .bin(bin), .alu_out, .zero(), .opcode);
// positional port connections
accum accum (dataout[7:0], alu_out, clk, rst_n);
// mixture of named port connections and implicit .* port connections
xtend xtend (.dout(dataout[15:8]), .*, .din(alu_out[7]));
endmodule
