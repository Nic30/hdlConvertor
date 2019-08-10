virtual class XFifo#(type T_in = logic, type T_out = logic, int DEPTH = 1) extends MyQueue#(T_out)
    implements PutImp#(T_in), GetImp#(T_out);
    pure virtual function T_out translate(T_in a);
    virtual function void put(T_in a);
        PipeQueue.push_back(translate(a));
    endfunction
    virtual function T_out get();
        get = PipeQueue.pop_front();
    endfunction
endclass