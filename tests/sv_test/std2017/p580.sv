covergroup g1 (int w, string instComment) @(posedge clk) ;
// track coverage information for each instance of g1 in addition
// to the cumulative coverage information for covergroup type g1
option.per_instance = 1;
// comment for each instance of this covergroup
option.comment = instComment;
a : coverpoint a_var
{
// Create 128 automatic bins for coverpoint “a” of each instance of g1
option.auto_bin_max = 128;
}
b : coverpoint b_var
{
// This coverpoint contributes w times as much to the coverage of an
// instance of g1 as coverpoints "a" and "c1"
option.weight = w;
}
c1 : cross a_var, b_var ;
endgroup
