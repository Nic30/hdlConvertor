// source code
// $typename would return
typedef bit node;
// "bit"
node [2:0] X;
// "bit [2:0]"
int signed Y;
// "int"
package A;
enum {A,B,C=99} X;
// "enum{A=32'sd0,B=32'sd1,C=32'sd99}A::e$1"
typedef bit [9:1'b1] word; // "A::bit[9:1]"
endpackage : A
import A::*;
module top;
typedef struct {node A,B;} AB_t;
AB_t AB[10];
// "struct{bit A;bit B;}top.AB_t$[0:9]"

endmodule
