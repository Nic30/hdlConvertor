parameter logic [7:0] My_DataIn =
8'hFF;
module bus_conn (
output logic [7:0] dataout,
input
[7:0] datain = My_DataIn);
assign dataout = datain;
endmodule
module bus_connect1 (
output logic [31:0] dataout,
input
[ 7:0] datain);
parameter logic [7:0] My_DataIn =
8'h00;
bus_conn bconn0 (dataout[31:24], 8'h0F);
// Constant literal overrides default in bus_conn definition
bus_conn bconn1 (dataout[23:16]);
// Omitted port for datain, default parameter value 8'hFF in
// bus_conn used
bus_conn bconn2 (dataout[15:8], My_DataIn);
// The parameter value 8'h00 from the instantiating scope is used
bus_conn bconn3 (dataout[7:0]);
endmodule


module generic_fifo(clk, in, read, write, reset, out, full, empty );

parameter MSB=3,LSB=0, DEPTH=4; // these parameters can be redefined

input [MSB:LSB] in;

input clk, read, write, reset;

output [MSB:LSB] out;
output full, empty;
wire [MSB:LSB] in;
wire logic [MSB:LSB] out;
logic full, empty;

endmodule

module generic_fifo
#(parameter MSB=3, LSB=0, DEPTH=4) // these parameters can be redefined
(input wire [MSB:LSB] in,
input wire clk, read,write reset,
output logic [MSB:LSB] out,
output logic full, empty);
endmodule
