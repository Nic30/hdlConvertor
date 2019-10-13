// http://www.asic-world.com/code/hdl_models/ram_sp_sr_sw.v
//-----------------------------------------------------
// Design Name : ram_sp_sr_sw
// File Name   : ram_sp_sr_sw.v
// Function    : Synchronous read write RAM
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module ram_sp_sr_sw #(
    parameter DATA_WIDTH = 8,
    parameter ADDR_WIDTH = 8,
    parameter RAM_DEPTH = (1 << ADDR_WIDTH)
) (
    //--------------Input Ports-----------------------
    input wire clk,
    // Clock Input
    input wire[(ADDR_WIDTH - 1):0] address,
    // Address Input
    //--------------Inout Ports-----------------------
    inout wire[(DATA_WIDTH - 1):0] data,
    // Data bi-directional
    input wire cs,
    // Chip Select
    input wire we,
    // Write Enable/Read Enable
    input wire oe
);
    //--------------Internal variables----------------
    reg[(DATA_WIDTH - 1):0] data_out;
    reg[(DATA_WIDTH - 1):0] mem[0:(RAM_DEPTH - 1)];
    reg oe_r;
    //--------------Code Starts Here------------------
    // Tri-State Buffer control
    // output : When we = 0, oe = 1, cs = 1
    assign data = (((cs && oe) && !we)) ? (data_out) : (8'bz);
    // Memory Write Block
    // Write Operation : When we = 1, cs = 1
    always @(posedge clk)
        if ((cs && we))
            mem[address] = data;

    // Memory Read Block
    // Read Operation : When we = 0, oe = 1, cs = 1
    always @(posedge clk)
        if (((cs && !we) && oe)) begin
            data_out = mem[address];
            oe_r = 1;
        end else
            oe_r = 0;

endmodule
