module stim;
bit [15:0] addr;
bit [31:0] data;
function bit gen_stim();
bit success, rd_wr;
success = randomize( addr, data, rd_wr );
return rd_wr ;
endfunction
// call std::randomize
//...
endmodule


class stimc;
rand bit [15:0] addr;
rand bit [31:0] data;
rand bit rd_wr;
endclass
function bit gen_stim( stimc p );
bit [15:0] addr;
bit [31:0] data;
bit success;
success = p.randomize();
addr = p.addr;
data = p.data;
return p.rd_wr;
endfunction
