// Examples of `define text macros
module test;
    reg[7:0] a;
    reg[7:0] b;
    initial begin
        $display(5);
        $display("Hello world!");
        $display((2 + 2));
        $display((2 + 2));
        a = 1;
        $display("No feature");
    end

endmodule
