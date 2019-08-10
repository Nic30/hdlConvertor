class Big_Packet;
const int size; // instance constant
byte payload [];
function new();
size = $urandom % 4096; //one assignment in new -> ok
payload = new[ size ];
endfunction
endclass
