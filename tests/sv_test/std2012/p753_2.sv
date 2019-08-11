module addergen1 (co, sum, a, b, ci);
    parameter SIZE = 4;
    output [SIZE-1:0] sum;
    output co;
    input [SIZE-1:0] a, b;
    input ci;

    wire [SIZE :0] c;
    wire [SIZE-1:0] t [1:3];
    genvar i;
    
    assign c[0] = ci;

    //Hierarchical gate instance names are:
    //xor gates: bitnum[0].g1 bitnum[1].g1 bitnum[2].g1 bitnum[3].g1
    //bitnum[0].g2 bitnum[1].g2 bitnum[2].g2 bitnum[3].g2
    //and gates: bitnum[0].g3 bitnum[1].g3 bitnum[2].g3 bitnum[3].g3
    //bitnum[0].g4 bitnum[1].g4 bitnum[2].g4 bitnum[3].g4
    //or gates: bitnum[0].g5 bitnum[1].g5 bitnum[2].g5 bitnum[3].g5
    //Generated instances are connected with
    //multidimensional nets t[1][3:0] t[2][3:0] t[3][3:0]
    //(12 nets total)

    for(i=0; i<SIZE; i=i+1) begin:bitnum
        xor g1 ( t[1][i],a[i],b[i]);
        xor g2 ( sum[i], t[1][i],c[i]);
        and g3 ( t[2][i],a[i],b[i]);
        and g4 ( t[3][i], t[1][i],c[i]);
        or g5 (c[i+1], t[2][i], t[3][i]);
    end

    assign co = c[SIZE];
endmodule