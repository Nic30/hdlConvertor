class Packet;
Packet next;
function Packet get_next();// single line
get_next = next;
endfunction
// out-of-body (extern) declaration
extern protected virtual function int send(int value);
endclass
function int Packet::send(int value);
endfunction
