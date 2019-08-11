package p;
function void f();
$display("p::f");
endfunction
endpackage
module top;
import p::*;
if (1) begin : b
// generate block
initial f();
// reference to “f”
function void f();
$display("top.b.f");
endfunction
end
endmodule
