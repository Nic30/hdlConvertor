class vector #(int size = 1);
bit [size-1:0] a;
endclass

class stack #(type T = int);
local T items[];
task push( T a );  endtask
task pop( ref T a );  endtask
endclass

class vector #(int size = 1);
bit [size-1:0] a;
static int count = 0;
function void disp_count();
$display( "count: %d of size %d", count, size );
endfunction
endclass


