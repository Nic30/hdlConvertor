module memMod (interface a, input logic clk);
endmodule
module cpuMod (interface b, input logic clk);
endmodule
module top;
logic clk = 0;
simple_bus sb_intf();
memMod mem (.*, .a(sb_intf)); // partial implicit port connections
cpuMod cpu (.*, .b(sb_intf)); // partial implicit port connections
endmodule
