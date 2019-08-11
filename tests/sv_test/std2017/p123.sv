interface quiet_time_checker #(parameter min_quiet = 0, parameter max_quiet = 0)
  (input logic clk, reset_n, logic [1:0]en);
generate
  if ( max_quiet == 0) begin
    property quiet_time;
      @(posedge clk) reset_n |-> ($countones(en) == 1);
    endproperty
    a1: assert property (quiet_time);
  end
  else begin
    property quiet_time;
      @(posedge clk)
      (reset_n && ($past(en) != 0) && en == 0) |->(en == 0)[*min_quiet:max_quiet] ##1 ($countones(en) == 1);
    endproperty
    a1: assert property (quiet_time);
  end
  if ( (min_quiet == 0) && $isunbounded(max_quiet) )
    $warning(warning_msg);
endgenerate

endinterface
