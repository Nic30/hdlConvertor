library ieee;
use ieee.std_logic_1164.all;

-- https://www.nandland.com/vhdl/examples/example-select.html
entity ex_select is
end ex_select;

architecture behave of ex_select is

  signal r_Index   : integer := 2;
  signal w_One_Hot : std_logic_vector(3 downto 0);

begin

  with r_Index select
    w_One_Hot <= "0000" when 0,
                 "0001" when 1,
                 "0010" when 2,
                 "0100" when 3,
                 "1000" when 4,
                 "0000" when others;

end behave;