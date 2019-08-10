module cntrl;
initial
$timeformat(-9, 5, " ns", 10);
endmodule

module a1_dat;
logic in1;
integer file;
buf #10000000 (o1,in1);
initial begin
file = $fopen("a1.dat");
#00000000 $fmonitor(file,"%m: %t in1=%d o1=%h", $realtime,in1,o1);
#10000000 in1 = 0;
#10000000 in1 = 1;
end
endmodule

module a2_dat;
logic in2;
integer file2;
buf #10000 (o2,in2);
initial begin
file2=$fopen("a2.dat");
#00000 $fmonitor(file2,"%m: %t in2=%d o2=%h",$realtime,in2,o2);
#10000 in2 = 0;
#10000 in2 = 1;
end
endmodule
