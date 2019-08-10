interface class IntfClass;
  pure virtual function bit funcA();
  pure virtual function bit funcB();
endclass

// Partial implementation of IntfClass
virtual class ClassA implements IntfClass;
  virtual function bit funcA();
    return (1);
  endfunction

  pure virtual function bit funcB();

endclass

// Complete implementation of IntfClass
class ClassB extends ClassA;
  virtual function bit funcB();
    return (1);
  endfunction
endclass
