module  mux_using_if(
   din_0      , // Mux first input
   din_1      , // Mux Second input
   sel        , // Select input
   mux_out      // Mux output
   );

 `protect
//-----------Input Ports---------------
input din_0, din_1, sel ;
//-----------Output Ports---------------
output mux_out;
//------------Internal Variables--------
reg  mux_out;
//-------------Code Starts Here---------
always @ (sel or din_0 or din_1)
begin : MUX
  if (sel == 1'b0) begin
      mux_out = din_0;
  end else begin
      mux_out = din_1 ;
  end
end
`endprotect

endmodule

