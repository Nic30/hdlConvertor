checker counter_model(logic flag);
  bit [2:0] counter = '0;
  always_ff @($global_clock)
    counter <= counter + 1'b1;

  assert property (@($global_clock) counter == 0 |-> flag);

endchecker : counter_model
