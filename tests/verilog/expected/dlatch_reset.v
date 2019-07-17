// http://www.asic-world.com/code/hdl_models/dlatch_reset.v
//-----------------------------------------------------
// Design Name : dlatch_reset
// File Name   : dlatch_reset.v
// Function    : DLATCH async reset
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module dlatch_reset (
    //-----------Input Ports---------------
    input data,
    input en,
    input reset,
    //-----------Output Ports---------------
    output q
);
    //------------Internal Variables--------
    reg q;
    always @(en, reset, data)
        if (~reset)
            q <= 1'b0;
        else if (en)
            q <= data;

endmodule
