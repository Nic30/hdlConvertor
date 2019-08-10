module m;
logic clk, a, b;
logic p, q, r;
// let with formal arguments and default value on y
let eq(x, y = b) = x == y;
// without parameters, binds to a, b above
let tmp = a && b;
a1: assert property (@(posedge clk) eq(p,q));
always_comb begin
a2: assert (eq(r)); // use default for y
a3: assert (tmp);
end
endmodule : m


module m;
bit clk, a, b;
logic p, q, r;
// let eq(x, y = b) = x == y;
// let tmp = a && b;
a1: assert property (@(posedge clk) (m.p == m.q));
always_comb begin
a2: assert ((m.r == m.b)); // use default for y
a3: assert ((m.a && m.b));
end
endmodule : m


module top;
logic x = 1'b1;
logic a, b;
let y = x;
always_comb begin
// y binds to preceding definition of x
// in the declarative context of let
bit x = 1'b0;
b = a | y;
end
endmodule : top

module top;
bit x = 1'b1;
bit a;
// let y = x;
always_comb begin
// y binds to preceding definition of x
// in the declarative context of let
bit x = 1'b0;
b = a | (top.x);
end
endmodule : top
