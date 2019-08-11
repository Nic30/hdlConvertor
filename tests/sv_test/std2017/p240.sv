module multiple2;
logic a;
initial a = 1;
initial a <= #4 0;
initial a <= #4 1;
// schedules 0 at time 4
// schedules 1 at time 4
// At time 4, a = ??
// The assigned value of the variable is indeterminate
endmodule


module multiple3;
logic a;
initial #8 a <= #8 1;
initial #12 a <= #4 0;
endmodule

module multiple4;
logic r1;
logic [2:0] i;
initial begin
// makes assignments to r1 without cancelling previous assignments
for (i = 0; i <= 5; i++)
r1 <= # (i*10) i[0];
end
endmodule

