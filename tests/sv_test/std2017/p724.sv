module top();
logic clk, x, y, z;
m m_i(clk, x, y, z);
endmodule
module m(input logic clk, a, b, c);
assert #0 (a^b);
// no label, assertion cannot be referred to
A1: assert #0 (a^b); // assertion can be accessed in control tasks
initial begin : B1
assert (a);
A1: assert (a)
begin
bit d;
d = a ^ b;
end
else
begin : B2
bit d;
d = a ^ b;
end
end

logic e;
always_ff @(posedge clk) begin // unnamed block, no scope created
e <= a && c;
C1: cover property(e)
// C1 and A2 can be referred to
begin
// hierarchical name top.m_i.C1.A2
A2: assert (m_i.B1.A1.B2.d);
end
end

always_ff @(posedge clk) begin // unnamed block, scope created
// declaration of f causes begin-end to create scope
static logic f;
f <= a && c;
C2: cover property(f)
// C2 and A3 cannot be referred to
begin
A3: assert (m_i.B1.A1.B2.d);
end
end
always_ff @(posedge clk) begin : B2 // named block and scope created
static logic f;
f <= a && c;
C3: cover property(f)
// C3 and A4 can be referred to
begin
// hierarchical name top.m_i.B2.C3.A4
A4: assert (m_i.B1.A1.B2.d);
end
end
assert property(@(posedge clk) a |-> b) else // unnamed assertion
begin: B3
static bit d;
// d can be referred to, e.g., top.m_i.B3.d
A5: assert(d);
// hierarchical name top.m_i.B3.A5
end
// Any other labelled object with name B3 at the module
// level shall be an error
endmodule
