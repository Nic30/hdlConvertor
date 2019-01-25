

`define	sqr( x ) (x * x) // comment

`define	sum( a /* comment */ , b /* comment */ ) /* comment */ \
  (a + b)

`define sumsqr(
    a // comment
  ,
    b // comment
  ) \
  `sum ( \
    `sqr(a) \
   , \
    `sqr(b) \
   )


module macro(input clock, reset);

  wire [31:0] up_data;
  wire [31:0] down_data;
 
  assign down_data = `sumsqr(
            up_data /* input data */
           ,
            (4 + 8) /* 12 */
           );



endmodule
