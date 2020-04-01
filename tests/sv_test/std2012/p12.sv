 
module mux2to1 ( 
    input wire a,
    output logic y
    
    );
endmodule


/*
module mux2to1 (input wire a, b, sel, 
                output logic y);
    
    always_comb begin
        if (sel) y = a;
        else
                 y = b;
    end
    
endmodule: mux2to1
*/
