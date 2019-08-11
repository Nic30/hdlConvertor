module test;
logic set;
parameter p = 1.55;
initial begin
$monitor($time,,"set=", set);
#p set = 0;
#p set = 1;
end
endmodule


module test;
logic set;
parameter p = 1.55;
initial begin
$monitor($realtime,,"set=", set);
#p set = 0;
#p set = 1;
end
endmodule


module a_dat;
initial
$printtimescale(b_dat.c1);
endmodule

module b_dat;
c_dat c1 ();
endmodule

