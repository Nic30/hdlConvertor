interface class IntfA #(type T1 = logic);
  typedef T1[1:0] T2;
  pure virtual function T2 funcA();
endclass : IntfA

interface class IntfB #(type T = bit) extends IntfA #(T);
  pure virtual function T2 funcB(); // legal, type T2 is inherited
endclass : IntfB

interface class IntfC;
  typedef enum {ONE, TWO, THREE} t1_t;
  pure virtual function t1_t funcC();
endclass : IntfC

class ClassA implements IntfC;
  virtual function IntfC::t1_t funcC();
    return (IntfC::ONE);
  endfunction : funcC
endclass : ClassA

typedef interface class IntfD;

class ClassB implements IntfD #(bit);
  virtual function bit[1:0] funcD();
    return 2'b11;
  endfunction : funcD
endclass : ClassB

// This interface class declaration must be declared before ClassB
interface class IntfD #(type T1 = logic);
  typedef T1[1:0] T2;
  pure virtual function T2 funcD();
endclass : IntfD


