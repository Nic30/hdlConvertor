typedef struct {
  byte length;
  shortint address;
  byte payload[];
  byte chksum;
} Packet;

function Packet genPkt();
  Packet p;
  void'( randomize( p.address, p.length, p.payload ) 
    with { p.length > 1 && p.payload.size == p.length; } );
  p.chksum = p.payload.xor();
  return p;
endfunction
