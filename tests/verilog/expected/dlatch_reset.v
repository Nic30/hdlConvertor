// http://www.asic-world.com/code/hdl_models/dlatch_reset.v
//-----------------------------------------------------
// Design Name : dlatch_reset
// File Name   : dlatch_reset.v
// Function    : DLATCH async reset
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module dlatch_reset (
    //-----------Input Ports---------------
    input wire data,
    input wire en,
    input wire reset,
    //-----------Output Ports---------------
    //------------Internal Variables--------
    output reg q
);
    //-------------Code Starts Here---------
    always @(en, reset, data)
        if (~reset)
            q <= 1'b0;
        else if (en)
            q <= data;

endmodule
