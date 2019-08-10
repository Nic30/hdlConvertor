// user-defined data type T
typedef struct {
  real field1;
  bit field2;
} T;

// user-defined resolution function Tsum
function automatic T Tsum (input T driver[]);
  Tsum.field1 = 0.0;
  foreach (driver[i])
    Tsum.field1 += driver[i].field1;
endfunction

nettype T wT;

// an unresolved nettype wT whose data type is T
// a nettype wTsum whose data type is T and
// resolution function is Tsum
nettype T wTsum with Tsum;

// user-defined data type TR
typedef real TR[5];

// an unresolved nettype wTR whose data type
// is an array of real
nettype TR wTR;

// declare another name nettypeid2 for nettype wTsum
nettype wTsum nettypeid2;