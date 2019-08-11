module top;
logic phi1, phi2;
wire [8:1] cmd; // cannot be logic (two bidirectional drivers)
logic [15:0] data;
test main (phi1, data, write, phi2, cmd, enable);
cpu cpu1 (phi1, data, write);
mem mem1 (phi2, cmd, enable);
endmodule


interface bus_A (input clk);
logic [15:0] data;
logic write;
modport test (input data, output write);
modport dut (output data, input write);
endinterface
interface bus_B (input clk);
logic [8:1] cmd;
logic enable;
modport test (input enable);
modport dut (output enable);
endinterface
program test( bus_A.test a, bus_B.test b );
clocking cd1 @(posedge a.clk);
input data = a.data;
output write = a.write;
inout state = top.cpu1.state;
endclocking
clocking cd2 @(posedge b.clk);
input #2 output #4ps cmd = b.cmd;
input en = b.enable;
endclocking
initial begin
// program begins here
// user can access cd1.data, cd1.write, cd1.state,
// cd2.cmd, and cd2.en
end
endprogram
