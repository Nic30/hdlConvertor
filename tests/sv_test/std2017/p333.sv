module m;
logic a, w;
task t1 (output o = a) ; // default binds to m.a
endtask :t1
task t3 (inout io = w) ; // default binds to m.w
endtask :t1
endmodule :m
module n;
logic a;
initial begin
m.t1(); //
m.t3(); //
end
endmodule :n


function int fun( int j = 1, string s = "no" );
endfunction
