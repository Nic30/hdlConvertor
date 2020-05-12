LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
-- https://www.nandland.com/vhdl/examples/example-select.html
ENTITY ex_select IS
END ENTITY;

ARCHITECTURE behave OF ex_select IS
    SIGNAL r_Index : integer := 2;
    SIGNAL w_One_Hot : std_logic_vector(3 DOWNTO 0);
BEGIN
    CASE r_Index IS
        WHEN 0 =>
            w_One_Hot <= "0000";
        WHEN 1 =>
            w_One_Hot <= "0001";
        WHEN 2 =>
            w_One_Hot <= "0010";
        WHEN 3 =>
            w_One_Hot <= "0100";
        WHEN 4 =>
            w_One_Hot <= "1000";
        WHEN OTHERS =>
            w_One_Hot <= "0000";
    END CASE;
END ARCHITECTURE;
