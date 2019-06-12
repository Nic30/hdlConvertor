library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

-- https://www.nandland.com/vhdl/examples/example-procedure-simple.html
entity example_procedure_simple is
end example_procedure_simple;

architecture behave of ex_procedure_simple is

  signal r_TEST : std_logic_vector(7 downto 0) := X"42";

  -- Purpose: Increments a std_logic_vector by 1
  procedure p_INCREMENT_SLV (
    signal r_IN  : in  std_logic_vector(7 downto 0);
    signal r_OUT : out std_logic_vector(7 downto 0)
    ) is
  begin
    r_OUT <= std_logic_vector(unsigned(r_IN) + 1);
    wait for 1 ns;                      -- Wait is OK here.
  end p_INCREMENT_SLV;


begin

  process is
  begin
    wait for 10 ns;
    p_INCREMENT_SLV(r_TEST, r_TEST);
    wait for 10 ns;
    p_INCREMENT_SLV(r_TEST, r_TEST);
    wait for 10 ns;
    p_INCREMENT_SLV(r_TEST, r_TEST);
    wait;
  end process;

end behave;