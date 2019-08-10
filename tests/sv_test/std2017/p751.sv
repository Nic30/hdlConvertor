module memMod( input logic req,
	             logic clk,
		     logic start,
		     logic [1:0] mode,
		     logic [7:0] addr,
	       inout wire [7:0] data,
	       output bit gnt,
	              bit rdy);
  logic avail;
endmodule

module cpuMod(
input logic clk,
      logic gnt,
      logic rdy,
inout wire [7:0] data,
output logic req,
       logic start,
       logic [7:0] addr,
       logic [1:0] mode );
endmodule
module top;
logic req, gnt, start, rdy;
logic clk = 0;
logic [1:0] mode;
logic [7:0] addr;
wire [7:0] data;
memMod mem(req, clk, start, mode, addr, data, gnt, rdy);
cpuMod cpu(clk, gnt, rdy, data, req, start, addr, mode);
endmodule



interface simple_bus; // Define the interface
logic req, gnt;
logic [7:0] addr, data;
logic [1:0] mode;
logic start, rdy;
endinterface: simple_bus
module memMod(simple_bus a, // Access the simple_bus interface
input logic clk);
logic avail;
// When memMod is instantiated in module top, a.req is the req
// signal in the sb_intf instance of the 'simple_bus' interface
always @(posedge clk) a.gnt <= a.req & avail;
endmodule
module cpuMod(simple_bus b, input logic clk);
endmodule
module top;
logic clk = 0;
simple_bus sb_intf(); // Instantiate the interface
memMod mem(sb_intf, clk); // Connect the interface to the module instance
cpuMod cpu(.b(sb_intf), .clk(clk)); // Either by position or by name
endmodule


