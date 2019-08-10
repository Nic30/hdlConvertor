checker check(logic a, b, c, clk, rst);
logic x, y, z, v, t;
assign x = a;
// current value of a
always_ff @(posedge clk or negedge rst) // current values of clk and rst
begin
	a1: assert (b);
if (rst)
z <= b;
else z <= !c;
end
always_comb begin
a2: assert (b);
if (a)
v = b;
else v = !b;
end
always_latch begin
a3: assert (b);
if (clk)
t <= b;
end
// ...
endchecker : check
