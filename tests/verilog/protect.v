module top
  (
   input CLK, 
   input RST,
   input enable,
   input [31:0] value,
   output [7:0] led
  );
  reg [31:0] count;
  reg [7:0] state;
  assign led = count[23:16];

`protect

  wire[2:0] out;
  genvar i;

  generate
    for(i=0;i<3;i=i+1)
      begin:test1
        assign  out[i]=i;
      end
  endgenerate

`endprotect

  always @(posedge CLK) begin
    if(RST) begin
      count <= 0;
      state <= 0;
    end else begin
      if(state == 0) begin
        if(enable) state <= 1;
      end else if(state == 1) begin
        state <= 2;
      end else if(state == 2) begin
        count <= count + value;
        state <= 0;
      end
    end
  end
endmodule