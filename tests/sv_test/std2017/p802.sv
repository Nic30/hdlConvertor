module busdriver (busin, bushigh, buslow, enh, enl);
input [15:0] busin;
output [ 7:0] bushigh, buslow;
input enh, enl;
driver busar3 (busin[15:12], bushigh[7:4], enh);
driver busar2 (busin[11:8], bushigh[3:0], enh) ;
driver busar1 (busin[7:4], buslow[7:4], enl)   ;
driver busar0 (busin[3:0], buslow[3:0], enl)   ;

endmodule


module busdriver_equiv (busin, bushigh, buslow, enh, enl);
input [15:0] busin;
output [ 7:0] bushigh, buslow;
input enh, enl;
driver busar[3:0]
(.out({bushigh, buslow}), .in(busin),
.en({enh, enh, enl, enl}));
endmodule


module dffn (q, d, clk);
parameter bits = 1;
input [bits-1:0] d;
output [bits-1:0] q;
input
clk ;
DFF dff[bits-1:0] (q, d, clk); // create a row of D flip-flops
endmodule

module MxN_pipeline(in, out, clk);
parameter M = 3,N = 4;// M=width,N=depth
input [M-1:0] in ;
output [M-1:0] out;
input clk;
wire [M*(N-1):1] t;
// #(M) redefines the bits parameter for dffn
// create p[1:N] columns of dffn rows (pipeline)
dffn #(M) p[1:N] ({out, t}, {t, in}, clk);
endmodule

