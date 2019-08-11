module top;
  logic a, b;
  let x = a || b;
  sequence s;
    x ##1 b;
  endsequence : s
endmodule : top

module top;
  logic a, b;
  // let x = a || b;
  sequence s;
    (top.a || top.b) ##1 b;
  endsequence : s
endmodule : top

module m();
  wire a, b;
  wire [2:0] c;
  wire [2:0] d;
  wire e;

  for (genvar i = 0; i < 3; i++) begin : L0
    if (i !=1) begin : L1
      let my_let(x) = !x || b && c[i];
      assign d[2 - i] = my_let(a); // OK
    end : L1
  end : L0
endmodule : m


module m(input clock);
  logic [15:0] a, b;
  logic c, d;
  typedef bit [15:0] bits;
  let ones_match(bits x, y) = x == y;
  let same(logic x, y) = x === y;
  always_comb
    a1: assert(ones_match(a, b));
  
  property toggles(bit x, y);
    same(x, y) |=> !same(x, y);
  endproperty
  a2: assert property (@(posedge clock) toggles(c, d));
endmodule : m

