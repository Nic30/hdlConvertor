covergroup g1 (int w, string instComment) @(posedge clk) ;
  // track coverage information for each instance of g1 in addition
  // to the cumulative coverage information for covergroup type g1
  option.per_instance = 1;
  type_option.comment = "Coverage model for features x and y";
  type_option.strobe = 1;
  // sample at the end of the time slot
  // compute type coverage as the merge of all instances
  type_option.merge_instances = 1;
  // comment for each instance of this covergroup
  option.comment = instComment;
  a : coverpoint a_var
   {
    // Use weight 2 to compute the coverage of each instance
    option.weight = 2;
    // Use weight 3 to compute the cumulative (type) coverage for g1
    type_option.weight = 3;
    // NOTE: type_option.weight = w would cause syntax error.
   }
  b : coverpoint b_var
   {
   // Use weight w to compute the coverage of each instance
   option.weight = w;
   // Use weight 5 to compute the cumulative (type) coverage of g1
   type_option.weight = 5;
   }
endgroup	
