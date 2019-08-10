interface simple_bus (input logic clk); // Define the interface
logic req, gnt;
logic [7:0] addr, data;
logic [1:0] mode;
logic start, rdy;
modport slave (input req, addr, mode, start, clk,
output gnt, rdy,
ref data,
import slaveRead,
slaveWrite);
// import into module that uses the modport
modport master(input gnt, rdy, clk,
output req, addr, mode, start,
ref data,
import masterRead,
masterWrite);
task masterRead(input logic [7:0] raddr); // masterRead method
// ...
endtask
task slaveRead; // slaveRead method
// ...
endtask
task masterWrite(input logic [7:0] waddr);
//...
endtask
task slaveWrite;
//...
endtask
endinterface: simple_bus

module memMod(interface a); // Uses just the interface
logic avail;
always @(posedge a.clk) // the clk signal from the interface
a.gnt <= a.req & avail; // the gnt and req signals in the interface
always @(a.start)
if (a.mode[0] == 1'b0)
a.slaveRead;
else
a.slaveWrite;
endmodule
module cpuMod(interface b);
enum {read, write} instr;
logic [7:0] raddr = $random();
always @(posedge b.clk)
if (instr == read)
b.masterRead(raddr); // call the Interface method
// ...
else
b.masterWrite(raddr);
endmodule
module omniMod( interface b);
//...
endmodule: omniMod
module top;
logic clk = 0;
simple_bus sb_intf(clk); // Instantiate the interface
memMod mem(sb_intf.slave); // only has access to the slave tasks
cpuMod cpu(sb_intf.master); // only has access to the master tasks
omniMod omni(sb_intf); // has access to all master and slave tasks
endmodule
