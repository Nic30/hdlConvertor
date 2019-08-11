module mod_sva_checks;
  logic a, b, c, d;
  logic clk_a, clk_d, clk_e1, clk_e2;
  logic clk_c, clk_p;
  clocking cb_prog @(posedge clk_p); endclocking
  clocking cb_checker @(posedge clk_c); endclocking
  default clocking cb @(posedge clk_d); endclocking
  sequence e4;
    $rose(b) ##1 c;
  endsequence
  // e4 infers posedge clk_a as per clock flow rules
  a1: assert property (@(posedge clk_a) a |=> e4.triggered);

  sequence e5;
    // e4 will infer posedge clk_e1 as per clock flow rules
    // wherever e5 is instantiated (with/without a method)
    @(posedge clk_e1) a ##[1:3] e4.triggered ##1 c;
  endsequence
  // e4, used in e5, infers posedge clk_e1 from e5
  a2: assert property (@(posedge clk_a) a |=> e5.matched);
  sequence e6(f);
   @(posedge clk_e2) f;
  endsequence
  // e4 infers posedge clk_e2 as per clock flow rules
  a3: assert property (@(posedge clk_a) a |=> e6(e4.triggered));
  sequence e7;
    e4 ##1 e6(d);
  endsequence
  // Leading clock of e7 is posedge clk_a as per clock flow rules
  a4: assert property (@(posedge clk_a) a |=> e7.triggered);
  
  always @(posedge clk_a) begin
    // e4 infers default clocking cb and not posedge clk_a as there is
    // more than one event control in this procedure (16.14.6)
    @(e4);
    d = a;
  end

  program prog_e4;
    default clocking cb_prog;
    initial begin
      // e4 infers default clocking cb_prog
      wait (e4.triggered);
      $display("e4 passed");
    end
  endprogram : prog_e4

  checker check(input in1, input sequence s_f);
    default clocking cb_checker;
    always @(s_f)
      $display("sequence triggered");
    a4: assert property (a |=> in1);
  endchecker : check
  
  // e4 infers checker's default clocking cb_checker
  check c1(e4.triggered, e4);
  // e4 connected to port of a module instance infers default clocking cb
  mod_adder ai1(e4.triggered);

endmodule : mod_sva_checks

