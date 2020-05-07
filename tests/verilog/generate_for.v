module top();
  wire[2:0] out;
  genvar i;

  generate
    for(i=0;i<3;i=i+1)
      assign  out[i]=i;
  endgenerate

endmodule
