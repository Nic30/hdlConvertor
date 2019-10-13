interface PBus #(parameter WIDTH=8);
// A parameterized bus interface
logic req, grant;
logic [WIDTH-1:0] addr, data;
modport phy(input addr, ref data);
endinterface
module top;
PBus #(16) p16();
PBus #(32) p32();
virtual PBus v8;
// legal declaration, but no legal assignments
virtual PBus #(35) v35; // legal declaration, but no legal assignments
virtual PBus #(16) v16;
virtual PBus #(16).phy v16_phy;
virtual PBus #(32) v32;
virtual PBus #(32).phy v32_phy;
initial begin
v16 = p16; // legal – parameter values match
v32 = p32; // legal – parameter values match
//v16 = p32; // illegal – parameter values don't match
//v16 = v32; // illegal – parameter values don't match
v16_phy = v16; // legal assignment from no selected modport to
              // selected modport
//v16 = v16_phy; // illegal assignment from selected modport to
                 // no selected modport
v32_phy = p32; // legal assignment from no selected modport to
               //selected modport
//v32 = p32.phy; // illegal assignment from selected modport to
                 // no selected modport
end
endmodule


interface SyncBus( input logic clk );
wire a, b, c;
clocking sb @(posedge clk);
input a;
output b;
inout c;

endclocking
endinterface
typedef virtual SyncBus VI; // A virtual interface type
task do_it( VI v );
	if( v.sb.a == 1 )
		v.sb.b <= 0;
	else
		v.sb.c <= ##1 1;
endtask
