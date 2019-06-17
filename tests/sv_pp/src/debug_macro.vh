`ifndef _debug_macro_vh_
`define _debug_macro_vh_

`define debug(msg) \
    $display(">> %s, %d: %s", `__FILE__, `__LINE__, msg)

`endif