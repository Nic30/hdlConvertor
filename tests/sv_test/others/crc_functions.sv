//https://stackoverflow.com/questions/17647819/looking-for-a-crc-implementation-in-systemverilog

module top;

function byte calc_crc(byte unsigned cmd[]);
    bit [7:0] crc, d, c;
    int i;
    crc = 0;

    for (i=0; i<cmd.size(); i++) begin
            d = cmd[i];
            c = crc;
            crc[0] = d[7] ^ d[6] ^ d[0] ^ c[0] ^ c[6] ^ c[7];
            crc[1] = d[6] ^ d[1] ^ d[0] ^ c[0] ^ c[1] ^ c[6];
            crc[2] = d[6] ^ d[2] ^ d[1] ^ d[0] ^ c[0] ^ c[1] ^ c[2] ^ c[6];
            crc[3] = d[7] ^ d[3] ^ d[2] ^ d[1] ^ c[1] ^ c[2] ^ c[3] ^ c[7];
            crc[4] = d[4] ^ d[3] ^ d[2] ^ c[2] ^ c[3] ^ c[4];
            crc[5] = d[5] ^ d[4] ^ d[3] ^ c[3] ^ c[4] ^ c[5];
            crc[6] = d[6] ^ d[5] ^ d[4] ^ c[4] ^ c[5] ^ c[6];
            crc[7] = d[7] ^ d[6] ^ d[5] ^ c[5] ^ c[6] ^ c[7];
    //$display("crc result: %h",crc);
    end
    return crc;
endfunction

localparam CRC32POL = 32'hEDB88320; /* Ethernet CRC-32 Polynom, reverse Bits */

function automatic bit[31:0] genCRC32(input bit [7:0] databyte_stream[]);
    int unsigned i, j;
    bit [31:0] crc32_val = 32'hffffffff; // shiftregister,startvalue 
    bit [7:0]  data;

    //The result of the loop generate 32-Bit-mirrowed CRC
    for (i = 0; i < databyte_stream.size; i++)  // Byte-Stream
    begin
        data = databyte_stream[i];
        for (j=0; j < 8; j++) // Bitwise from LSB to MSB
        begin
            if ((crc32_val[0]) != (data[0])) begin
                crc32_val = (crc32_val >> 1) ^ CRC32POL;
            end else begin
                crc32_val >>= 1;
            end
            data >>= 1;
        end
    end
    crc32_val ^= 32'hffffffff; //invert results
    return crc32_val;
endfunction : genCRC32

endmodule