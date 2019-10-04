// http://www.asic-world.com/code/hdl_models/rom_using_file.v
//-----------------------------------------------------
// Design Name : rom_using_file
// File Name   : rom_using_file.v
// Function    : ROM using readmemh
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module rom_using_file (
    input wire[7:0] address,
    output wire[7:0] data,
    input wire read_en,
    input wire ce
);
    reg[7:0] mem [0:255];
    assign data = ((ce && read_en)) ? (mem[address]) : (8'b0);
    initial
        $readmemb("memory.list", mem);
endmodule
