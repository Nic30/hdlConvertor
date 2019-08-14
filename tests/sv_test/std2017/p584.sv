module top;

covergroup p_cg with function sample(bit a, int x);
  coverpoint x;
  cross x, a;
endgroup : p_cg

p_cg cg1 = new;

property p1;
  int x;
  @(posedge clk)(a, x = b) ##1 (c, cg1.sample(a, x));
endproperty : p1

c1: cover property (p1);

function automatic void F(int j);
  bit d;
  cg1.sample( d, j );
endfunction

endmodule
