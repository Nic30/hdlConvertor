checker op_test (logic clk, vld_1, vld_2, logic [3:0] opcode);
  bit [3:0] opcode_d1;
  always_ff @(posedge clk) opcode_d1 <= opcode;
  covergroup cg_op;
    cp_op : coverpoint opcode_d1;
  endgroup: cg_op
  cg_op cg_op_1 = new();
  sequence op_accept;
    @(posedge clk) vld_1 ##1 (vld_2, cg_op_1.sample());
  endsequence
  cover property (op_accept);
endchecker
