// http://www.asic-world.com/code/hdl_models/parity_using_function2.v
//-----------------------------------------------------
// Design Name : parity_using_function2
// File Name   : parity_using_function2.v
// Function    : Parity using function
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module parity_using_function2 (
    input [7:0] data_in,
    output parity_out
);
    wire parity_out;
    always @(data_in)
        parity_out = parity(data_in);
endmodule
