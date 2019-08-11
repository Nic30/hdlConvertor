interface A_Bus( input logic clk );
wire req, gnt;
wire [7:0] addr, data;
clocking sb @(posedge clk);
input gnt;
output req, addr;
inout data;
property p1; req ##[1:3] gnt; endproperty
endclocking
modport DUT ( input clk, req, addr,
output gnt,
inout data ); // Device under test modport
modport STB ( clocking sb ); // synchronous testbench modport
modport TB ( input gnt,
output req, addr,
inout data );
endinterface


module dev1(A_Bus.DUT b);
endmodule // Some device: Part of the design
module dev2(A_Bus.DUT b);
endmodule // Some device: Part of the design
module top;
logic clk;
A_Bus b1( clk );
A_Bus b2( clk );
dev1 d1( b1 );
dev2 d2( b2 );
T tb( b1, b2 );
endmodule
program T (A_Bus.STB b1, A_Bus.STB b2 ); // testbench: 2 synchronous ports
assert property (b1.sb.p1);
// assert property from within program
initial begin
b1.sb.req <= 1;
wait( b1.sb.gnt == 1 );
b1.sb.req <= 0;
b2.sb.req <= 1;
wait( b2.sb.gnt == 1 );
b2.sb.req <= 0;
end
endprogram
