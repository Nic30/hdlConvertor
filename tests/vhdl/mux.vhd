library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity multiplexer4_1 is
port (
      i0 : in std_logic;
      i1 : in std_logic;
      i2 : in std_logic;
      i3 : in std_logic;
     sel : in std_logic_vector(1 downto 0);
     bitout : out std_logic
     );
end multiplexer4_1;

architecture Behavioral of multiplexer4_1 is
begin

process(i0,i1,i2,i3,sel)
begin
case sel is
  when "00" => bitout <= i0;
  when "01" => bitout <= i1;
  when "10" => bitout <= i2;
  when others => bitout <= i3;
end case;
end process;

end Behavioral;

