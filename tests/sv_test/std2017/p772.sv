module top;
logic clk;
SyncBus b1( clk );
SyncBus b2( clk );
initial begin
VI v[2] = '{ b1, b2 };
repeat( 20 )
do_it( v[ $urandom_range( 0, 1 ) ] );
end
endmodule


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

