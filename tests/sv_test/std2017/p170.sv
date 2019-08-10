class Packet ;
//data or class properties
bit [3:0] command;
bit [40:0] address;
bit [4:0] master_id;
integer time_requested;
integer time_issued;
integer status;
typedef enum { ERR_OVERFLOW = 10, ERR_UNDERFLOW = 1123} PCKT_TYPE;
const integer buffer_size = 100;
const integer header_size;
// initialization
function new();
command = 4'd0;
address = 41'b0;
master_id = 5'bx;
header_size = 10;
endfunction
// methods
// public access entry points
task clean();
command = 0; address = 0; master_id = 5'bx;
endtask
task issue_request( int delay );
// send request to bus
endtask
function integer current_status();
current_status = status;
endfunction
endclass
