library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

package components_pkg is

  component demo is
    generic (
      GENERIC1: boolean := false;
      GENERIC2: integer := 100
    );
    port (
      a, b : in std_ulogic := '1';
      c, d : out std_ulogic_vector(7 downto 0);
      e, f : inout unsigned(7 downto 0)
    );
  end component;
end components_pkg;
