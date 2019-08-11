module m (i2.master i);
endmodule
module s (i2.slave i);
endmodule
module top;
i2 i();
m u1(.i(i));
s u2(.i(i));
endmodule

module m (i2 i);
endmodule
module s (i2 i);
endmodule
module top;
i2 i();
m u1(.i(i.master));
s u2(.i(i.slave));
endmodule


