package p;
typedef enum { FALSE, TRUE } bool_t;
endpackage
package q;
typedef enum { ORIGINAL, FALSE } teeth_t;
endpackage
module top1 ;
import p::*;
import q::teeth_t;
teeth_t myteeth;
initial begin
myteeth = q:: FALSE; // OK:
myteeth = FALSE;
// ERROR: Direct reference to FALSE refers to the
end
// FALSE enumeration literal imported from p
endmodule
module top2 ;
import p::*;
import q::teeth_t, q::ORIGINAL, q::FALSE;
teeth_t myteeth;
initial begin
myteeth = FALSE;
end
endmodule
