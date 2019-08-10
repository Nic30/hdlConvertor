interface simple_bus (input logic clk); // Define the interface
  logic req, gnt;
  logic [7:0] addr, data;
  logic [1:0] mode;
  logic start, rdy;
  task masterRead(input logic [7:0] raddr); // masterRead method
  endtask: masterRead
  task slaveRead; // slaveRead method
  endtask: slaveRead
endinterface: simple_bus

module memMod(interface a); // Uses any interface
  logic avail;
  always @(posedge a.clk) // the clk signal from the interface
    a.gnt <= a.req & avail; // the gnt and req signals in the interface
  always @(a.start)
    a.slaveRead;
endmodule

module cpuMod(interface b);
  enum {read, write} instr;
  logic [7:0] raddr;
  always @(posedge b.clk)
    if (instr == read)
      b.masterRead(raddr); // call the Interface method
endmodule

module top;
  logic clk = 0;
  simple_bus sb_intf(clk); // Instantiate the interface
  memMod mem(sb_intf);
  cpuMod cpu(sb_intf);
endmodule

