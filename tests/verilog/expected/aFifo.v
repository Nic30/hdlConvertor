// http://www.asic-world.com/code/hdl_models/aFifo.v
//==========================================
// Function : Asynchronous FIFO (w/ 2 asynchronous clocks).
// Coder    : Alex Claros F.
// Date     : 15/May/2005.
// Notes    : This implementation is based on the article
//           'Asynchronous FIFO in Virtex-II FPGAs'
//           writen by Peter Alfke. This TechXclusive
//           article can be downloaded from the
//           Xilinx website. It has some minor modifications.
//=========================================
module aFifo #(
    parameter  DATA_WIDTH = 8,
    parameter  ADDRESS_WIDTH = 4,
    parameter  FIFO_DEPTH = (1 << ADDRESS_WIDTH)
) (
    output reg [(DATA_WIDTH - 1):0] Data_out,
    output reg Empty_out,
    input ReadEn_in,
    input RClk,
    //Writing port.
    input [(DATA_WIDTH - 1):0] Data_in,
    output reg Full_out,
    input WriteEn_in,
    input WClk,
    input Clear_in
);
    /////Internal connections & variables//////
    reg [(DATA_WIDTH - 1):0]  Mem [(FIFO_DEPTH - 1):0];
    wire [(ADDRESS_WIDTH - 1):0]  pNextWordToWrite;
    wire [(ADDRESS_WIDTH - 1):0]  pNextWordToRead;
    wire EqualAddresses;
    wire NextWriteAddressEn;
    wire NextReadAddressEn;
    wire Set_Status;
    wire Rst_Status;
    reg Status;
    wire PresetFull;
    wire PresetEmpty;
    always @(posedge RClk)
        if ((ReadEn_in & !Empty_out))
            Data_out <= Mem[pNextWordToRead];

    always @(posedge WClk)
        if ((WriteEn_in & !Full_out))
            Mem[pNextWordToWrite] <= Data_in;

    //Fifo addresses support logic:
    //'Next Addresses' enable logic:
    NextWriteAddressEn = (WriteEn_in & ~Full_out);
    NextReadAddressEn = (ReadEn_in & ~Empty_out);
    GrayCounter GrayCounter_pWr (
        .GrayCount_out(pNextWordToWrite),
        .Enable_in(NextWriteAddressEn),
        .Clear_in(Clear_in),
        .Clk(WClk)
    );

    GrayCounter GrayCounter_pRd (
        .GrayCount_out(pNextWordToRead),
        .Enable_in(NextReadAddressEn),
        .Clear_in(Clear_in),
        .Clk(RClk)
    );

    //'EqualAddresses' logic:
    EqualAddresses = (pNextWordToWrite == pNextWordToRead);
    //'Quadrant selectors' logic:
    Set_Status = ((pNextWordToWrite[(ADDRESS_WIDTH - 2)] >> pNextWordToRead[(ADDRESS_WIDTH - 1)]) & (pNextWordToWrite[(ADDRESS_WIDTH - 1)] ^ pNextWordToRead[(ADDRESS_WIDTH - 2)]));
    Rst_Status = ((pNextWordToWrite[(ADDRESS_WIDTH - 2)] ^ pNextWordToRead[(ADDRESS_WIDTH - 1)]) & (pNextWordToWrite[(ADDRESS_WIDTH - 1)] >> pNextWordToRead[(ADDRESS_WIDTH - 2)]));
    always @(Set_Status, Rst_Status, Clear_in)
        // Latch w/ Asynchronous Clear & Preset.
        if ((Rst_Status | Clear_in))
            Status = 0;
        else if (Set_Status)
            Status = 1;

    //Going 'Full'.
    //'Full_out' logic for the writing port:
    PresetFull = (Status & EqualAddresses);
    always @(posedge WClk, posedge PresetFull)
        // Flip-Flop w/ Asynchronous Preset.
        if (PresetFull)
            Full_out <= 1;
        else
            Full_out <= 0;

    //'Empty_out' logic for the reading port:
    PresetEmpty = (~Status & EqualAddresses);
    always @(posedge RClk, posedge PresetEmpty)
        // Flip-Flop w/ Asynchronous Preset.
        if (PresetEmpty)
            Empty_out <= 1;
        else
            Empty_out <= 0;

endmodule