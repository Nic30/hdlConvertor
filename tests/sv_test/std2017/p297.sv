module m(input clock);
  logic a;
  // let p1(x) = $past(x);
  // let p2(x) = $past(x,,,@(posedge clock));
  // let s(x) = $sampled(x);
  always_comb begin
    a1: assert(($past(a))); // Illegal: no clock can be inferred
    a2: assert(($past(a,,,@(posedge clock))));
    a3: assert(($sampled (a)));
  end
  a4: assert property(@(posedge clock)($past(a)));
  // @(posedge clock)
  // is inferred
endmodule : m
