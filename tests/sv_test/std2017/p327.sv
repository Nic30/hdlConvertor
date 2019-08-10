module tryfact;
  // define the function
  function automatic integer factorial (input [31:0] operand);
    if (operand >= 2)
      factorial = factorial (operand - 1) * operand;
    else
      factorial = 1;
  endfunction: factorial

  // test the function
  integer result;
  
  initial begin
    for (int n = 0; n <= 7; n++) begin
      result = factorial(n);
      $display("%0d factorial=%0d", n, result);
    end
  end
endmodule: tryfact
