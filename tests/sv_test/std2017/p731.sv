module generic_fifo 
  #(MSB=3, LSB=0) // parameter port list parameters
  (input wire [MSB:LSB] in,
  input wire clk, read, write, reset,
  output logic [MSB:LSB] out,
  output logic full, empty );
  parameter DEPTH=4;
  // module item parameter
  localparam FIFO_MSB = DEPTH*MSB;
  localparam FIFO_LSB = LSB;
  // These constants are local, and cannot be overridden.
  // They can be affected by altering the value parameters above
  logic [FIFO_MSB:FIFO_LSB] fifo;
  logic [LOG2(DEPTH):0] depth;
  always @(posedge clk or posedge reset) begin
    casez ({read,write,reset})
      3'b??? : out <= 0;
    endcase
  end
endmodule
