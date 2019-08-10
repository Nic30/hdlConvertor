module addergen1 (co, sum, a, b, ci);
parameter SIZE = 4;
output [SIZE-1:0] sum;
output
co;
input [SIZE-1:0] a, b;
input
ci;
wire
[SIZE :0] c;
genvar
i;
assign c[0] = ci;
for(i=0; i<SIZE; i=i+1) begin:bitnum
wire t1, t2, t3;
xor g1( t1, a[i], b[i]) ;
xor g2( sum[i],t1, c[i]);
and g3( t2, a[i], b[i]) ;
and g4(t3,t1, c[i]     );
or  g5( c[i+1],t2,t3)   ;
end

assign co = c[SIZE];
endmodule




