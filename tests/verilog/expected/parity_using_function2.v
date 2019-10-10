// http://www.asic-world.com/code/hdl_models/parity_using_function2.v
//-----------------------------------------------------
// Design Name : parity_using_function2
// File Name   : parity_using_function2.v
// Function    : Parity using function
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module parity_using_function2 (
    input wire[7:0] data_in,
    // 8 bit data in
    output wire parity_out
);
    function wire parity (
        input wire[31:0] data
    );
        integer i;
        begin
            parity = 0;
            for (i = 0; (i < 32); i = (i + 1))
                parity = (parity ^ data[i]);
        end
    endfunction
    always @(data_in)
        parity_out = parity(data_in);
endmodule
