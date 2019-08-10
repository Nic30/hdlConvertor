typedef enum { cover_none, cover_all } coverage_level;
checker assert_window2 (
logic test_expr,
// Expression to be true in the window
sequence start_event, // Window opens at the completion of the start_event
sequence end_event,
// Window closes at the completion of the end_event
event clock = $inferred_clock,
logic reset = $inferred_disable,
string error_msg = "violation",
coverage_level clevel = cover_all // This argument should be bound to an
// elaboration time constant expression
);
default clocking @clock; endclocking
default disable iff reset;
bit window = 0;
let start_flag = start_event.triggered;
let end_flag = end_event.triggered;
// Compute next value of window
function bit next_window (bit win);
if (reset || win && end_flag)
return 1'b0;
if (!win && start_flag)
return 1'b1;
return win;
endfunction
always_ff @clock
window <= next_window(window);
property p_window;
start_flag && !window |=> test_expr[+] ##0 end_flag;
endproperty
a_window: assert property (p_window) else $error(error_msg);
generate if (clevel != cover_none) begin : cover_b
cover_window_open: cover property (start_flag && !window)
$display("window_open covered");
cover_window: cover property (
start_flag && !window
##1 (!end_flag && window) [*]
##1 end_flag && window
) $display("window covered");
end : cover_b
endgenerate
endchecker : assert_window2
