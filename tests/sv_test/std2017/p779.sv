package p;
int x;
endpackage
module top;
import p::*;
if (1) begin : b
initial x = 1;
int x;
initial x = 1;
end
int x;
endmodule

package p;
int x;
endpackage
package p2;
int x;
endpackage
module top;
import p::*;
if (1) begin : b
initial x = 1;
import p2::*;
end
endmodule

package p;
function int f();
return 1;
endfunction
endpackage
module top;
int x;
if (1) begin : b
initial x = f();
import p::*;
end

function int f();
return 1;
endfunction
endmodule


