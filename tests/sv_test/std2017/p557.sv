class MC;
logic [3:0] m_x;
local logic m_z;
bit m_e;
covergroup cv1 @(posedge clk); coverpoint m_x; endgroup
covergroup cv2 @m_e ; coverpoint m_z; endgroup
endclass

class Helper;
int m_ev;
endclass
class MyClass;
Helper m_obj;
int m_a;
covergroup Cov @(m_obj.m_ev);
coverpoint m_a;
endgroup
function new();
m_obj = new;
Cov = new;
endfunction
endclass


