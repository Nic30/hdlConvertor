module sync_array(a1,a2,a3,a4,a5,a6,a7,b1,b2,b3,clk);
input a1, a2, a3, a4, a5, a6, a7, clk;
output b1, b2, b3;
logic [1:7] mem[1:3]; // memory declaration
logic b1, b2, b3;
initial begin
// set up the personality
$readmemb("array.dat", mem);
// set up a synchronous logic array to be evaluated
// when a positive edge on the clock occurs
forever @(posedge clk)
$async$and$array(mem,{a1,a2,a3,a4,a5,a6,a7},{b1,b2,b3});
end
endmodule


module pla;
const int rows = 4;
const int cols = 3;
logic [1:cols] a, mem[1:rows];
logic [1:rows] b;
initial begin
// PLA system call
$async$and$plane(mem,a[1:3],b[1:4]);
mem[1] = 3'b10?;
mem[2] = 3'b??1;
mem[3] = 3'b0?0;
mem[4] = 3'b???;
// stimulus and display
#10 a = 3'b111;
#10 $displayb(a, " -> ", b);
#10 a = 3'b000;
#10 $displayb(a, " -> ", b);
#10 a = 3'bxxx;
#10 $displayb(a, " -> ", b);
#10 a = 3'b101;
#10 $displayb(a, " -> ", b);
end
endmodule











