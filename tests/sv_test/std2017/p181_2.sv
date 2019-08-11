class Packet;
integer value;
function integer delay();
delay = value * value;
endfunction
endclass
// base class
class LinkedPacket extends Packet;
// derived class
integer value;
function integer delay();
delay = super.delay()+ value * super.value;
endfunction
endclass
