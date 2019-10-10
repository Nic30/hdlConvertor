

`define	sqr( x ) (x * x) // comment0

`define	sum( a /* comment1 */ , b /* comment2 */ ) /* comment3 */ \
  (a + b)

`define sumsqr(
    a // comment4
  ,
    b // comment5
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
            up_data /* comment6 */
           ,
            (4 + 8) /* 12 */
           );



endmodule
