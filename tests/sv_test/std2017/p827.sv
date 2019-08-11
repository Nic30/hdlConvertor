module capacitor;
logic data, gate;
// trireg declaration with a charge decay time of 50 time units
trireg (large) #(0,0,50) cap1;
nmos nmos1 (cap1, data, gate); // nmos that drives the trireg
initial begin
$monitor("%0d data=%v gate=%v cap1=%v", $time, data, gate, cap1);
data = 1;
// Toggle the driver of the control input to the nmos switch
gate = 1;
#10 gate = 0;
#30 gate = 1;
#10 gate = 0;
#100 $finish;
end
endmodule
