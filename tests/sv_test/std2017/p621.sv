module async_array(a1,a2,a3,a4,a5,a6,a7,b1,b2,b3);
input a1, a2, a3, a4, a5, a6, a7 ;
output b1, b2, b3;
logic [1:7] mem[1:3]; // memory declaration for array personality
logic b1, b2, b3;
initial begin
// set up the personality from the file array.dat
$readmemb("array.dat", mem);
// set up an asynchronous logic array with the input
// and output terms expressed as concatenations
$async$and$array(mem,{a1,a2,a3,a4,a5,a6,a7},{b1,b2,b3});
end
endmodule
