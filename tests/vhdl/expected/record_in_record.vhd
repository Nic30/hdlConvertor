LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
ARCHITECTURE behave OF example_record IS
    TYPE register_0_t IS RECORD
        pll_lock : std_logic;
        cnt_limit : std_logic_vector(9 DOWNTO 0);
        latency : std_logic_vector(20 DOWNTO 0);
    END RECORD;
    TYPE register_record_t IS RECORD
        register_0 : register_0_t;
        register_1 : register_1_t;
    END RECORD;
    SIGNAL r_WR_DATA : register_record_t;
BEGIN
    regs.register_0.pll_lock <= '1';
END ARCHITECTURE;
