primitive dff1 (q, clk,d);
input clk, d;
output q; reg q;
initial q = 1'b1;
table
// clk d q r
r 0 : ? : 0;
r 1 : ? : 1;
f ? : ? : -;
? * : ? : -;
endtable
endprimitive

module dff (q, qb, clk, d);
input clk, d;
output q, qb;
dff1
g1 (qi, clk, d);
buf #3 g2 (q, qi);
not #5 g3 (qb, qi);
endmodule
