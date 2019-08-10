sequence abc;
@(posedge clk) a ##1 b ##1 c;
endsequence
sequence de;
@(negedge clk) d ##[2:5] e;
endsequence
program check;
initial begin
wait( abc.triggered || de.triggered );
if( abc.triggered )
$display( "abc succeeded" );
if( de.triggered )
$display( "de succeeded" );
end
endprogram
