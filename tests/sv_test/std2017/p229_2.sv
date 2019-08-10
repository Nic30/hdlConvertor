class process;
typedef enum { FINISHED, RUNNING, WAITING, SUSPENDED, KILLED } state;
static function process self();
function state status();
function void kill();
task await();
function void suspend();
function void resume();
function void srandom( int seed );
function string get_randstate();
function void set_randstate( string state );
endclass
