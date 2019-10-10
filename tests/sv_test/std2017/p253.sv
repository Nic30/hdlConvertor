`define LIB_DFF lib1_dff

module overlap(inout wire [15:0] bus16, inout wire [11:0] low12, high12);
alias bus16[11:0] = low12;
alias bus16[15:4] = high12;
endmodule
module overlap(inout wire [15:0] bus16, inout wire [11:0] low12, high12);
alias bus16 = {high12, low12[3:0]};
alias high12[7:0] = low12[11:4];
endmodule

module my_dff(rst, clk, d, q, q_bar); // wrapper cell
input rst, clk, d;
output q, q_bar;
alias rst = Reset = reset = RST;
alias clk = Clk = clock = CLK;
alias d = Data = data = D;
alias q = Q;
alias Q_ = q_bar = Q_Bar = qbar;
`LIB_DFF my_dff (.*); // LIB_DFF is any of lib1_dff, lib2_dff or lib3_dff
endmodule
