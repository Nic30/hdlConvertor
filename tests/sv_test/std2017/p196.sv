
interface class PutImp#(type PUT_T = logic);
  pure virtual function void put(PUT_T a);
endclass

interface class GetImp#(type GET_T = logic);
  pure virtual function GET_T get();
endclass

class MyQueue #(type T = logic, int DEPTH = 1);
  T PipeQueue[$:DEPTH-1];
  virtual function void deleteQ();
    PipeQueue.delete();
  endfunction
endclass

class Fifo #(type T = logic, int DEPTH = 1) extends MyQueue#(T, DEPTH) implements PutImp#(T), GetImp#(T);
   virtual function void put(T a);
     PipeQueue.push_back(a);
   endfunction

   virtual function T get();
     get = PipeQueue.pop_front();
   endfunction
endclass
