library ieee;
use ieee.std_logic_1164.all;

entity test_module is
  generic (
    a : integer
  );
  port (
    clk : std_logic
  );
end entity;

entity test_entity_top is
end entity;

architecture test of test_entity_top is
begin
  test_inst : entity work.test_module
    generic map (
      a => 4
    )
	port map (
      clk => clk
    );
end architecture;