interface class IntfBase;
  parameter SIZE = 64;
endclass

interface class IntfExt1 extends IntfBase;
  pure virtual function bit funcExt1();
endclass

interface class IntfExt2 extends IntfBase;
  pure virtual function bit funcExt2();
endclass

interface class IntfExt3 extends IntfExt1, IntfExt2;
endclass

interface class IntfBase #(type T = int);
  pure virtual function bit funcBase();
endclass

interface class IntfExt1 extends IntfBase#(bit);
  pure virtual function bit funcExt1();
endclass

interface class IntfExt2 extends IntfBase#(logic);
  pure virtual function bit funcExt2();
endclass

interface class IntfFinal extends IntfExt1, IntfExt2;
  typedef bit T; // Override the conflicting identifier name
  pure virtual function bit funcBase();
endclass
