module test;
parameter p = 0, q = 0;
wire a, b, c;
//---------------------------------------------------------
// Code to either generate a u1.g1 instance or no instance.
// The u1.g1 instance of one of the following gates:
// (and, or, xor, xnor) is generated if
// {p,q} == {1,0}, {1,2}, {2,0}, {2,1}, {2,2}, {2, default}
//---------------------------------------------------------
if (p == 1)
if (q == 0)
begin : u1
and g1(a, b, c);
end
else if (q == 2)
begin : u1
or g1(a, b, c);
end
// If p==1 and q==0, then instantiate
// AND with hierarchical name test.u1.g1
// If p==1 and q==2, then instantiate
// OR with hierarchical name test.u1.g1
// "else" added to end "if (q == 2)" statement
else ;
// If p==1 and q!=0 or 2, then no instantiation
else if (p == 2)
case (q)
0, 1, 2:
begin : u1
// If p==2 and q==0,1, or 2, then instantiate
xor g1(a, b, c); // XOR with hierarchical name test.u1.g1
end
default:
begin : u1
// If p==2 and q!=0,1, or 2, then instantiate
xnor g1(a, b, c); // XNOR with hierarchical name test.u1.g1
end
endcase
endmodule


module multiplier(a,b,product);
parameter a_width = 8, b_width = 8;
localparam product_width = a_width+b_width;
// cannot be modified directly with the defparam
// statement or the module instance statement #
input [a_width-1:0] a;
input [b_width-1:0] b;
output [product_width-1:0] product;
generate
if((a_width < 8) || (b_width < 8)) begin: mult
CLA_multiplier #(a_width,b_width) u1(a, b, product);
// instantiate a CLA multiplier
end
else begin: mult
WALLACE_multiplier #(a_width,b_width) u1(a, b, product);
// instantiate a Wallace-tree multiplier
end
endgenerate
// The hierarchical instance name is mult.u1
endmodule


