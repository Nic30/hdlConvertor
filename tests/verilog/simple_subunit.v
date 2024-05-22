module submodule0(input a,
        output b
    );

    assign b = a;
endmodule

module SimpleSubunit(input a,
        output b
    );

    wire sig_submodule0_a;
    wire sig_submodule0_b;
    submodule0 submodule0_inst (.a(sig_submodule0_a),
        .b(sig_submodule0_b)
        );


    assign b = sig_submodule0_b;
    assign sig_submodule0_a = a;
endmodule
