struct packed signed {
int a;
shortint b;
byte c;
bit [7:0] d;
} pack1; // signed, 2-state
struct packed unsigned {
time a;
integer b;
logic [31:0] c;
} pack2; // unsigned, 4-state

typedef struct packed { // default unsigned
bit [3:0] GFC;
bit [7:0] VPI;
bit [11:0] VCI;
bit CLP;
bit [3:0] PT ;
bit [7:0] HEC;
bit [47:0] [7:0] Payload;
bit [2:0] filler;
} s_atmcell;
