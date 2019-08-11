checker reason_about_one_bit(bit [63:0] data1, bit [63:0] data2,
event clock);
rand const bit [5:0] idx;
a1: assert property (@clock data1[idx] == data2[idx]);
endchecker : reason_about_one_bit



checker reason_about_all_bit(bit [63:0] data1, bit [63:0] data2,
event clock);
a1: assert property (@clock data1 == data2);
endchecker : reason_about_all_bit

// If start_ev is asserted then the value of out_data at the next assertion
// of end_ev has to be equal to the current value of in_data at start_ev.
//
// It is assumed that in_data and out_data have the same size
checker data_legal(start_ev, end_ev, in_data, out_data);
rand const bit [$bits(in_data)-1:0] mem_data;
sequence transaction;
start_ev && (in_data == mem_data) ##1 end_ev[->1];
endsequence
a1: assert property (@clock transaction |-> out_data == mem_data);
endchecker : data_legal


// If start_ev is asserted then the value of in_data has to be
// equal to the value of out_data at the next assertion of end_ev
//
// It is assumed that in_data and out_data have the same size
checker data_legal_with_loc(start_ev, end_ev, in_data, out_data);
sequence transaction (loc_var);
(start_ev, loc_var = in_data) ##1 end_ev[->1];
endsequence
property data_legal;
bit [$bits(in_data)-1:0] mem_data;
transaction(mem_data) |-> out_data == mem_data;
endproperty
a1: assert property (@clock data_legal);
endchecker : data_legal_with_loc
