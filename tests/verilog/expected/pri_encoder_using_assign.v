//-----------------------------------------------------
// http://www.asic-world.com/code/hdl_models/pri_encoder_using_assign.v
// Design Name : pri_encoder_using_assign
// File Name   : pri_encoder_using_assign.v
// Function    : Pri Encoder using assign
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module pri_encoder_using_assign (
    output wire[3:0] binary_out,
    // 4 bit binary output
    input wire[15:0] encoder_in,
    // 16-bit input
    input wire enable
);
    assign binary_out = (!enable) ? (0) : (((((((((((((((((encoder_in == 16'bxxxxxxxxxxxxxxx1)) ? (0) : ((encoder_in == 16'bxxxxxxxxxxxxxx10))) ? (1) : ((encoder_in == 16'bxxxxxxxxxxxxx100))) ? (2) : ((encoder_in == 16'bxxxxxxxxxxxx1000))) ? (3) : ((encoder_in == 16'bxxxxxxxxxxx10000))) ? (4) : ((encoder_in == 16'bxxxxxxxxxx100000))) ? (5) : ((encoder_in == 16'bxxxxxxxxx1000000))) ? (6) : ((encoder_in == 16'bxxxxxxxx10000000))) ? (7) : ((encoder_in == 16'bxxxxxxx100000000))) ? (8) : ((encoder_in == 16'bxxxxxx1000000000))) ? (9) : ((encoder_in == 16'bxxxxx10000000000))) ? (10) : ((encoder_in == 16'bxxxx100000000000))) ? (11) : ((encoder_in == 16'bxxx1000000000000))) ? (12) : ((encoder_in == 16'bxx10000000000000))) ? (13) : ((encoder_in == 16'bx100000000000000))) ? (14) : (15));
endmodule
