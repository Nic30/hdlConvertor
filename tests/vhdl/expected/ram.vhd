
-- https://surf-vhdl.com/vhdl-syntax-web-course-surf-vhdl/vhdl-generics/
ENTITY RAM IS
    GENERIC(
        data_width : IN integer := 64,
        addr_width : IN integer := 12,
        Taa : IN time := 50,
        Toe : IN time := 40
    );
    PORT(
        oeb : IN std_logic,
        wrb : IN std_logic,
        csb : IN std_logic,
        data : INOUT std_logic_vector(((data_width - 1) DOWNTO 0)),
        addr : IN std_logic_vector(((addr_width - 1) DOWNTO 0))
    );
END ENTITY;

