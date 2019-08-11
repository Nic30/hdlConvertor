interface i1 (input a, output b, inout c);
wire d;
endinterface

interface simple_bus (input logic clk); // Define the interface
logic req, gnt;
logic [7:0] addr, data;
logic [1:0] mode;
logic start, rdy;
endinterface: simple_bus
module memMod(simple_bus a); // Uses just the interface
logic avail;
always @(posedge a.clk) // the clk signal from the interface
a.gnt <= a.req & avail; // a.req is in the 'simple_bus' interface
endmodule
module cpuMod(simple_bus b);
endmodule

module top;
logic clk = 0;
simple_bus sb_intf1(clk); // Instantiate the interface
simple_bus sb_intf2(clk); // Instantiate the interface
memMod mem1(.a(sb_intf1)); // Reference simple_bus 1 to memory 1
cpuMod cpu1(.b(sb_intf1));
memMod mem2(.a(sb_intf2)); // Reference simple_bus 2 to memory 2
cpuMod cpu2(.b(sb_intf2));
endmodule


interface i2;
wire a, b, c, d;
modport master (input a, b, output c, d);
modport slave (output a, b, input c, d);
endinterface


