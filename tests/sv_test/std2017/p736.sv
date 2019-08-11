module tb3;
// declarations & code
// legal mixture of instance with positional parameters and
// another instance with named parameters
vdff #(10, 15)
mod_a (.out(out_a), .in(in_a), .clk(clk));
vdff
mod_b (.out(out_b), .in(in_b), .clk(clk));
vdff #(.delay(12)) mod_c (.out(out_c), .in(in_c), .clk(clk));
endmodule
