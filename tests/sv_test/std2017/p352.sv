module m;
bit a = 1'b1;
default clocking cb @(posedge clk);
output a;
endclocking
initial begin
## 1;
cb.a <= 1'b0;
@(x); // x is triggered by reactive stimulus running in same time step
cb.a <= 1'b1;
end
endmodule
