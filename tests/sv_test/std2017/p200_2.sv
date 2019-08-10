interface class PutImp#(type T = logic);
  pure virtual function void put(T a);
endclass

interface class GetImp#(type T = logic);
  pure virtual function T get();
endclass

interface class PutGetIntf#(type TYPE = logic) extends PutImp#(TYPE), GetImp#(TYPE);
  typedef TYPE T;
endclass
