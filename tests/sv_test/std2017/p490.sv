// Context inference in a checker
checker check_in_context (logic test_sig,
                          event clock = $inferred_clock,
                          logic reset = $inferred_disable);
  //property p(logic sig);
  //endproperty
  a1: assert property (@clock disable iff (reset) p(test_sig));
  c1: cover property (@clock !reset throughout !test_sig ##1 test_sig);
endchecker : check_in_context

module m(logic rst);
  wire clk;
  logic a, en;
  wire b = a && en;
  // No context inference
  check_in_context my_check1(.test_sig(b), .clock(clk), .reset(rst));
  always @(posedge clk) begin
    a <= 8'h5;
    if (en) begin
      check_in_context my_check2(a);
    end
    en <= 1'b1;
  end
endmodule : m

