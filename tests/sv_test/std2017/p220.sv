sequence abc;
@(posedge clk) a ##1 b ##1 c;
endsequence
program test;
initial begin
@ abc $display( "Saw a-b-c" );
end
endprogram
