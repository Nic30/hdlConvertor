LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;
LIBRARY std;
USE std.textio.ALL;
LIBRARY work;
ENTITY RightShifter_8_by_max_10_F700_uid80 IS
    PORT(
        clk : IN std_logic;
        rst : IN std_logic;
        X : IN std_logic_vector(7 DOWNTO 0);
        S : IN std_logic_vector(3 DOWNTO 0);
        R : OUT std_logic_vector(17 DOWNTO 0)
    );
END ENTITY;

ARCHITECTURE arch OF RightShifter_8_by_max_10_F700_uid80 IS
    SIGNAL level0 : std_logic_vector(7 DOWNTO 0);
    SIGNAL ps : std_logic_vector(3 DOWNTO 0);
    SIGNAL ps_d1 : std_logic_vector(3 DOWNTO 0);
    SIGNAL level1 : std_logic_vector(8 DOWNTO 0);
    SIGNAL level2 : std_logic_vector(10 DOWNTO 0);
    SIGNAL level2_d1 : std_logic_vector(10 DOWNTO 0);
    SIGNAL level3 : std_logic_vector(14 DOWNTO 0);
    SIGNAL level4 : std_logic_vector(22 DOWNTO 0);
BEGIN
    PROCESS(clk)
    BEGIN
        IF clk'event AND clk = '1' THEN
            ps_d1 <= ps;
            level2_d1 <= level2;
        END IF;
    END PROCESS;
    level0 <= X;
    ps <= S;
    level1 <= ((0 DOWNTO 0 => '0') & level0) WHEN (ps(0) = '1') ELSE level0 & (0 DOWNTO 0 => '0');
    level2 <= ((1 DOWNTO 0 => '0') & level1) WHEN (ps(1) = '1') ELSE level1 & (1 DOWNTO 0 => '0');
    level3 <= ((3 DOWNTO 0 => '0') & level2_d1) WHEN (ps_d1(2) = '1') ELSE level2_d1 & (3 DOWNTO 0 => '0');
    level4 <= ((7 DOWNTO 0 => '0') & level3) WHEN (ps_d1(3) = '1') ELSE level3 & (7 DOWNTO 0 => '0');
    R <= level4(22 DOWNTO 5);
END ARCHITECTURE;
