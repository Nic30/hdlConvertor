// Test Scenario to validate correct translation
// Refer: https://github.com/Nic30/hdlConvertor/issues/173
module dummy (
    output wire c,
    input wire a,
    input wire b
);
    and a1 (
        c,
        a,
        b
    );

endmodule
module d2 (
    output wire y,
    input wire a
);
    assign y = ~a;
endmodule
module example (
    input wire a,
    input wire b,
    input wire c,
    output wire d
);
    wire tmp;
    wire tmp2;
    and a1 (
        tmp,
        a,
        b
    );

    dummy du (
        tmp2,
        b,
        c
    );

    or o1 (
        d,
        tmp,
        tmp2
    );

endmodule
