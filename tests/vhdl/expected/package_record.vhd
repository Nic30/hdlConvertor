LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
PACKAGE example_record_pkg IS
    TYPE t_FROM_FIFO IS RECORD
        wr_full : std_logic;
        rd_empty : std_logic;
        rd_dv : std_logic;
        rd_data : std_logic_vector(7 DOWNTO 0);
    END RECORD;
    TYPE t_TO_FIFO IS RECORD
        wr_en : std_logic;
        wr_data : std_logic_vector(7 DOWNTO 0);
        rd_en : std_logic;
    END RECORD;
    CONSTANT c_FROM_FIFO_INIT : t_FROM_FIFO := (
        wr_full => '0',
        rd_empty => '1',
        rd_dv => '0',
        rd_data => (OTHERS => '0'));
    CONSTANT c_TO_FIFO_INIT : t_TO_FIFO := (wr_en => '0', wr_data => (OTHERS => '0'), rd_en => '0');
END PACKAGE;

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
USE work.example_record_pkg.ALL;
-- USING PACKAGE HERE!
ENTITY example_record IS
    PORT(
        i_clk : IN std_logic;
        i_fifo : IN t_FROM_FIFO;
        o_fifo : OUT t_TO_FIFO := c_TO_FIFO_INIT
    );
END ENTITY;

ARCHITECTURE behave OF example_record IS
    SIGNAL r_WR_DATA : unsigned(7 DOWNTO 0) := (OTHERS => '0');
BEGIN
    p_FIFO_WR: PROCESS(i_clk)
    BEGIN
        IF rising_edge(i_clk) THEN
            IF i_fifo.wr_full = '0' THEN
                o_fifo.wr_en <= '1';
                o_fifo.wr_data <= std_logic_vector(r_WR_DATA + 1);
            END IF;
        END IF;
    END PROCESS;
    p_FIFO_RD: PROCESS(i_clk)
    BEGIN
        IF rising_edge(i_clk) THEN
            IF i_fifo.rd_empty = '0' THEN
                o_fifo.rd_en <= '1';
            END IF;
        END IF;
    END PROCESS;
END ARCHITECTURE;
