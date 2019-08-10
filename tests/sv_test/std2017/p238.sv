module evaluates (out);
output out;
logic a, b, c;
initial begin
a = 0;
b = 1;
c = 0;
end
always c = #5 ~c;
always @(posedge c) begin
a <= b; // evaluates, schedules,
b <= a; // and executes in two steps
end
endmodule
