function int[$] GenQueue(int low, int high);
  int[$] q;
  randsequence()
    TOP : BOUND(low) LIST BOUND(high) ;
    LIST : LIST ITEM := 8 { q = { q, ITEM }; }
           | ITEM := 2 { q = { q, ITEM }; }
	   ;
    int ITEM : { return $urandom_range( low, high ); } ;
    BOUND(int b) : { q = { q, b }; } ;

  endsequence

  GenQueue = q;
endfunction


class DSL;
endclass

module top;

initial begin
// class that creates valid DSL packets
randsequence (STREAM)
   STREAM : GAP DATA := 80
            | DATA := 20 ;
   DATA : PACKET(0) := 94 { transmit( PACKET ); }
        | PACKET(1) := 6 { transmit( PACKET ); } ;

   DSL PACKET (bit bad) : { DSL d = new;
                             if( bad ) d.crc ^= 23;
                             return d;
                          };
   GAP: { ## {$urandom_range( 1, 20 )}; };
endsequence

end

endmodule
