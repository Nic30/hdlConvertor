module driver (in, out, en);
input [3:0] in;
output [3:0] out;
input
en;
bufif0 ar[3:0] (out, in, en); // array of three-state buffers
endmodule

module driver_equiv (in, out, en);
input [3:0] in;
output [3:0] out;
input en;
bufif0 ar3 (out[3],in[3],en); 
bufif0 ar2 (out[2],in[2],en);
bufif0 ar1 (out[1],in[1],en);
bufif0 ar0 (out[0],in[0],en);

endmodule
