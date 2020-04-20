LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
-- https://surf-vhdl.com/vhdl-syntax-web-course-surf-vhdl/vhdl-generics/
ENTITY RAM IS
    GENERIC(
        data_width : integer := 64;
        addr_width : integer := 12;
        Taa : time := 50;
        Toe : time := 40
    );
    PORT(
        oeb : IN std_logic;
        wrb : IN std_logic;
        csb : IN std_logic;
        data : INOUT std_logic_vector(data_width - 1 DOWNTO 0);
        addr : IN std_logic_vector(addr_width - 1 DOWNTO 0)
    );
END ENTITY;

