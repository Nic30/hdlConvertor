interface simple_bus #(AWIDTH = 8, DWIDTH = 8)
(input logic clk); // Define the interface
logic req, gnt;
logic [AWIDTH-1:0] addr;
logic [DWIDTH-1:0] data;
logic [1:0] mode;
logic start, rdy;
modport slave( input req, addr, mode, start, clk,
output gnt, rdy,
ref data,
import task slaveRead,
task slaveWrite);
// import into module that uses the modport
modport master(input gnt, rdy, clk,
output req, addr, mode, start,
ref data,
import task masterRead(input logic [AWIDTH-1:0] raddr),
task masterWrite(input logic [AWIDTH-1:0] waddr));
// import requires the full task prototype
task masterRead(input logic [AWIDTH-1:0] raddr); // masterRead method
endtask
task slaveRead; // slaveRead method
endtask
task masterWrite(input logic [AWIDTH-1:0] waddr);
endtask
task slaveWrite;
endtask
endinterface: simple_bus
module memMod(interface a); // Uses just the interface keyword
logic avail;
always @(posedge a.clk) // the clk signal from the interface
a.gnt <= a.req & avail; //the gnt and req signals in the interface
always @(a.start)
if (a.mode[0] == 1'b0)
a.slaveRead;
else
a.slaveWrite;
endmodule
module cpuMod(interface b);
enum {read, write} instr;
logic [7:0] raddr;
always @(posedge b.clk)
if (instr == read)
b.masterRead(raddr); // call the Interface method
// ...
else
b.masterWrite(raddr);
endmodule
module top;
logic clk = 0;
simple_bus sb_intf(clk); // Instantiate default interface
simple_bus #(.DWIDTH(16)) wide_intf(clk); // Interface with 16-bit data
initial repeat(10) #10 clk++;
memMod mem(sb_intf.slave); // only has access to the slaveRead task
cpuMod cpu(sb_intf.master); // only has access to the masterRead task
memMod memW(wide_intf.slave); // 16-bit wide memory
cpuMod cpuW(wide_intf.master); // 16-bit wide cpu
endmodule
