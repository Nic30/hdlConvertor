checker my_check(logic clk, active);
bit active_d1 = 1'b0;
always_ff @(posedge clk) begin
active_d1 <= active;
end
covergroup cg_active @(posedge clk);
cp_active : coverpoint active
{
bins idle = { 1'b0 };
bins active = { 1'b1 };
}
cp_active_d1 : coverpoint active_d1
{
bins idle = { 1'b0 };
bins active = { 1'b1 };
}
option.per_instance = 1;
endgroup
cg_active cg_active_1 = new();
endchecker : my_check
