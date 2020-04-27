//-----------------------------------------------------
// http://www.asic-world.com/verilog/syntax2.html
// This is simple adder Program
// Design Name : adder_implicit
// File Name   : adder_implicit.v
// Function    : This program shows how implicit
//              port connection are done
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module adder_implicit (
    // Output Port Declarations
    output wire[3:0] result,
    // Output of the adder
    output wire carry,
    // Carry output of adder
    // Input Port Declarations       
    // Port Wires
    input wire[3:0] r1,
    // first input
    input wire[3:0] r2,
    // second input
    input wire ci
);
    // Internal variables
    wire c1;
    wire c2;
    wire c3;
    addbit u0 (
        r1[0],
        r2[0],
        ci,
        result[0],
        c1
    );

    addbit u1 (
        r1[1],
        r2[1],
        c1,
        result[1],
        c2
    );

    addbit u2 (
        r1[2],
        r2[2],
        c2,
        result[2],
        c3
    );

    addbit u3 (
        r1[3],
        r2[3],
        c3,
        result[3],
        carry
    );

endmodule
