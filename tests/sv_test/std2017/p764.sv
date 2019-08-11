interface simple_bus (input logic clk); // Define the interface
logic req, gnt;
logic [7:0] addr, data;
logic [1:0] mode;
logic start, rdy;
modport slave( input req, addr, mode, start, clk,
output gnt, rdy,
ref data,
export Read,
Write);
// export from module that uses the modport
modport master(input gnt, rdy, clk,
output req, addr, mode, start,
ref data,
import task Read(input logic [7:0] raddr),
task Write(input logic [7:0] waddr));
// import requires the full task prototype
endinterface: simple_bus
module memMod(interface a); // Uses just the interface keyword
logic avail;
task a.Read; // Read method
avail = 0;
avail = 1;
endtask
task a.Write;
avail = 0;
avail = 1;
endtask
endmodule
module cpuMod(interface b);
enum {read, write} instr;
logic [7:0] raddr;
always @(posedge b.clk)
if (instr == read)
b.Read(raddr); // call the slave method via the interface
else
b.Write(raddr);
endmodule
module top;
logic clk = 0;
simple_bus sb_intf(clk); // Instantiate the interface
memMod mem(sb_intf.slave); // exports the Read and Write tasks
cpuMod cpu(sb_intf.master); // imports the Read and Write tasks
endmodule
