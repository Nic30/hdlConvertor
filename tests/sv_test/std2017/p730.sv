task t;
logic s;
begin : b
logic r;
t.b.r = 0;// These three lines access the same variable r
b.r = 0;
r = 0;
t.s = 0;// These two lines access the same variable s
s = 0;
end
endtask
