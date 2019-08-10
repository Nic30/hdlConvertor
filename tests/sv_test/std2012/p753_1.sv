module gray2bin1 (bin, gray);
    parameter SIZE = 8;
    // this module is parameterizable
    output [SIZE-1:0] bin;
    input [SIZE-1:0] gray;
    genvar i;
    generate
        for (i=0; i<SIZE; i=i+1) begin:bitnum
            assign bin[i] = ^gray[SIZE-1:i];
            // i refers to the implicitly defined localparam whose
            // value in each instance of the generate block is
            // the value of the genvar when it was elaborated.
        end
    endgenerate
endmodule