//-----------------------------------------------------
// http://www.asic-world.com/code/hdl_models/pri_encoder_using_if.v
// Design Name : pri_encoder_using_if
// File Name   : pri_encoder_using_if.v
// Function    : Pri Encoder using If
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module pri_encoder_using_if (
    output reg[3:0] binary_out,
    // 4 bit binary output
    input wire[15:0] encoder_in,
    // 16-bit input
    input wire enable
);
    always @(enable, encoder_in) begin
        binary_out = 0;
        if (enable)
            if ((encoder_in == {{{(14){1'bx}}, 1'b1}, {(1){1'b0}}}))
                binary_out = 1;
            else if ((encoder_in == {{{(13){1'bx}}, 1'b1}, {(2){1'b0}}}))
                binary_out = 2;
            else if ((encoder_in == {{{(12){1'bx}}, 1'b1}, {(3){1'b0}}}))
                binary_out = 3;
            else if ((encoder_in == {{{(11){1'bx}}, 1'b1}, {(4){1'b0}}}))
                binary_out = 4;
            else if ((encoder_in == {{{(10){1'bx}}, 1'b1}, {(5){1'b0}}}))
                binary_out = 5;
            else if ((encoder_in == {{{(9){1'bx}}, 1'b1}, {(6){1'b0}}}))
                binary_out = 6;
            else if ((encoder_in == {{{(8){1'bx}}, 1'b1}, {(7){1'b0}}}))
                binary_out = 7;
            else if ((encoder_in == {{{(7){1'bx}}, 1'b1}, {(8){1'b0}}}))
                binary_out = 8;
            else if ((encoder_in == {{{(6){1'bx}}, 1'b1}, {(9){1'b0}}}))
                binary_out = 9;
            else if ((encoder_in == {{{(5){1'bx}}, 1'b1}, {(10){1'b0}}}))
                binary_out = 10;
            else if ((encoder_in == {{{(4){1'bx}}, 1'b1}, {(11){1'b0}}}))
                binary_out = 11;
            else if ((encoder_in == {{{(3){1'bx}}, 1'b1}, {(12){1'b0}}}))
                binary_out = 12;
            else if ((encoder_in == {{{(2){1'bx}}, 1'b1}, {(13){1'b0}}}))
                binary_out = 13;
            else if ((encoder_in == {{{(1){1'bx}}, 1'b1}, {(14){1'b0}}}))
                binary_out = 14;
            else if ((encoder_in == {1'b1, {(15){1'b0}}}))
                binary_out = 15;
    end

endmodule
