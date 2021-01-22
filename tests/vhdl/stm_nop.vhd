library ieee ;
use ieee.std_logic_1164.all;

architecture rtl of mux4_case is
begin
  p_mux : process(a,b,c,d,s)
  begin
    case s is
      when "00"   => m <= a;
      when "01"   => m <= b;
      when "10"   => m <= c;
      when others => null;
    end case;
  end process p_mux;
end rtl;
