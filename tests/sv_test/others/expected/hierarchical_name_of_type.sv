module ibex_alu #(
    parameter ibex_pkg::rv32b_e RV32B = ibex_pkg::RV32BNone
) (
    input ibex_pkg::alu_op_e operator_i,
    input logic[31:0] operand_a_i,
    input logic[31:0] operand_b_i
);
endmodule
