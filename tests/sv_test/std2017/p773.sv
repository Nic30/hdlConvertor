module dev1(A_Bus.DUT b);
endmodule // Some device: Part of the design
module dev2(A_Bus.DUT b);
endmodule // Some device: Part of the design
program T (A_Bus.STB b1, A_Bus.STB b2 ); // Testbench: 2 synchronous ports
endprogram
module top;
logic clk;
A_Bus b1( clk );
A_Bus b2( clk );
dev1 d1( b1 );
dev2 d2( b2 );
T tb( b1, b2 );
endmodule



program T (A_Bus.STB b1, A_Bus.STB b2 ); // Testbench: 2 synchronous ports
typedef virtual A_Bus.STB SYNCTB;
task request( SYNCTB s );
s.sb.req <= 1;
endtask
task wait_grant( SYNCTB s );
wait( s.sb.gnt == 1 );
endtask
task drive(SYNCTB s, logic [7:0] adr, data );
if( s.sb.gnt == 0 ) begin
request(s);
// acquire bus if needed
wait_grant(s);
end

s.sb.addr = adr;
s.sb.data = data;
repeat(2) @s.sb;
s.sb.req = 0;
endtask
//release bus
assert property (b1.sb.p1);
// assert property from within program
initial begin
drive( b1, $random, $random );
drive( b2, $random, $random );
end
endprogram

