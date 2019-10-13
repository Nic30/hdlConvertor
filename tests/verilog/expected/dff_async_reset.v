// http://www.asic-world.com/code/hdl_models/dff_async_reset.v
//-----------------------------------------------------
// Design Name : dff_async_reset
// File Name   : dff_async_reset.v
// Function    : D flip-flop async reset
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module dff_async_reset (
    //-----------Input Ports---------------
    input wire data,
    // Data Input
    input wire clk,
    // Clock Input
    input wire reset,
    // Reset input
    //-----------Output Ports---------------
    //------------Internal Variables--------
    output reg q
);
    //-------------Code Starts Here---------
    always @(posedge clk, negedge reset)
        if (~reset)
            q <= 1'b0;
        else
            q <= data;

endmodule
