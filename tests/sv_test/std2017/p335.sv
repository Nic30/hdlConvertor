module top ();
  logic [7:0] encoder_in;
  logic [2:0] encoder_out;
  logic [1:0] decoder_in;
  logic [3:0] decoder_out;

  // Encoder and Decoder Input Assignments
  assign encoder_in = 8'b0100_0000;
  assign decoder_in = 2'b11;

  // Encoder and Decoder Function calls
  assign encoder_out = C#(8)::ENCODER_f(encoder_in);
  assign decoder_out = C#(4)::DECODER_f(decoder_in);
  initial begin
    #50;
    $display("Encoder input = %b Encoder output = %b\n",encoder_in, encoder_out );
    $display("Decoder input = %b Decoder output = %b\n",decoder_in, decoder_out );
  end
endmodule
