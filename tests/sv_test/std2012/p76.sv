interface intf_i;
  typedef int data_t;
endinterface

module sub(intf_i p);
  typedef p.data_t my_data_t;
  my_data_t data;
// type of 'data' will be int when connected to interface above
endmodule