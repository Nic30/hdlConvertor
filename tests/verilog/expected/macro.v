module macro (
    input wire clock,
    input wire reset
);
    wire[31:0] up_data;
    wire[31:0] down_data;
    assign down_data = ((up_data * up_data) + ((4 + 8) * (4 + 8)));
endmodule
