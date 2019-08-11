interface SBus;
logic req, grant;
logic [7:0] addr, data;
endinterface
// A Simple bus interface
class SBusTransactor;
virtual SBus bus;
// SBus transactor class
// virtual interface of type SBus
function new( virtual SBus s );
bus = s;
endfunction
// initialize the virtual interface
task request();
bus.req <= 1'b1;
endtask
// request the bus
task wait_for_bus();
@(posedge bus.grant);
endtask
endclass // wait for the bus to be granted
module devA( SBus s );  endmodule
module devB( SBus s );  endmodule // devices that use SBus
module top;
SBus s[1:4] (); // instantiate 4 interfaces
devA a1(s[1]);
devB b1(s[2]);
devA a2(s[3]);
devB b2(s[4]);
initial begin
SBusTransactor t[1:4];
t[1] = new( s[1] );
t[2] = new( s[2] );
t[3] = new( s[3] );
t[4] = new( s[4] );
// test t[1:4]
end
endmodule
