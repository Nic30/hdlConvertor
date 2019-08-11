module A;
  logic a, clk;
  clocking cb_with_input @(posedge clk);
    input a;
    property p1;
      a;
    endproperty
  endclocking

  clocking cb_without_input @(posedge clk);
    property p1;
      a;
    endproperty
  endclocking

  property p1;
    @(posedge clk) a;
  endproperty
  
  property p2;
    @(posedge clk) cb_with_input.a;
  endproperty

  a1: assert property (p1);
  a2: assert property (cb_with_input.p1);
  a3: assert property (p2);
  a4: assert property (cb_without_input.p1);

endmodule
