library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity malformed is
port (
      i0);
end sadfas%;

architecture Behavioral of multiplexer4_1 is
begin

process(i0,i1,i2,i3,sel, *)
begin
case sel is
  when "00" => bitout <= i0;
  when "01" => bitout <= i1;
  << <<;
  when others => bitout <= i3;
end case;
end process;

end Behavioral;

