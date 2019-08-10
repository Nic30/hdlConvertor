class C #(int p = 1);
parameter int q = 5; // local parameter
static task t;
int p;
int x = C::p; // C::p disambiguates p
// C::p is not p in the default specialization
endtask
endclass
