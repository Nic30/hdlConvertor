module my_mod();
bit mclk, v1, v2;
checker c1(bit fclk, bit a, bit b);
default clocking @ (posedge fclk); endclocking
checker c2(bit bclk, bit x, bit y);
default clocking @ (posedge bclk); endclocking
rand bit m, n;
u1: assume property (f1(x,m));
u2: assume property (f2(y,n));
endchecker
rand bit q, r;
c2 B1(fclk, q+r, r);
always_ff @ (posedge fclk)
r <= a || q; // assignment makes r inactive
u3: assume property (f3(a, q));
u4: assume property (f4(b, r));
endchecker

c1 F1(mclk, v1, const'(v2));
endmodule
