interface ebus_i;
integer I;
// reference to I not allowed through modport mp
typedef enum {Y,N} choice;
choice Q;
localparam True = 1;
modport mp(input Q);
endinterface
module Top;
ebus_i ebus ();
sub s1 (ebus.mp);
endmodule
module sub(interface.mp i);
typedef i.choice yes_no;
yes_no P;
assign P = i.Q;
initial
Top.ebus.Q = i.True;
initial
Top.ebus.I = 0;
endmodule

