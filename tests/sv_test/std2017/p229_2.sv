class process;
  typedef enum { FINISHED, RUNNING, WAITING, SUSPENDED, KILLED } state;
  static function process self();
  endfunction
  
  function state status();
  endfunction
  
  function void kill();
  endfunction

  task await();
  endtask

  function void suspend();
  endfunction

  function void resume();
  endfunction

  function void srandom( int seed );
  endfunction

  function string get_randstate();
  endfunction

  function void set_randstate( string state );
  endfunction

endclass
