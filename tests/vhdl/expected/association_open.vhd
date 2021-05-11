LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
ENTITY test_module IS
    GENERIC(
        a : integer
    );
    PORT(
        clk : IN std_logic;
        b : IN std_logic := '0'
    );
END ENTITY;

ENTITY test_entity_top IS
END ENTITY;

ARCHITECTURE test OF test_entity_top IS
BEGIN
    test_inst: ENTITY work.test_module GENERIC MAP(
        a => 4
    ) PORT MAP(
        clk => clk,
        b => OPEN
    );
END ARCHITECTURE;
