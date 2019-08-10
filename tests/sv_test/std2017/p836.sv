module flip;
reg clock, data;
parameter p1 = 10;
parameter p2 = 33;
parameter p3 = 12;
d_edge_ff #p3 d_inst (q, clock, data);
initial begin
data = 1;
clock = 1;
#(20 * p1) $finish;
end
always #p1 clock = ~clock;
always #p2 data = ~data;
endmodule
