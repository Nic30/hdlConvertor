library ieee;
use ieee.std_logic_1164.all;
-- https://www.nandland.com/vhdl/examples/example-record.html
package example_record_pkg is
 
  -- Outputs from the FIFO.
  type t_FROM_FIFO is record
    wr_full  : std_logic;                -- FIFO Full Flag
    rd_empty : std_logic;                -- FIFO Empty Flag
    rd_dv    : std_logic;
    rd_data  : std_logic_vector(7 downto 0);
  end record t_FROM_FIFO;  
 
  -- Inputs to the FIFO.
  type t_TO_FIFO is record
    wr_en    : std_logic;
    wr_data  : std_logic_vector(7 downto 0);
    rd_en    : std_logic;
  end record t_TO_FIFO;
 
  constant c_FROM_FIFO_INIT : t_FROM_FIFO := (wr_full => '0',
                                              rd_empty => '1',
                                              rd_dv => '0',
                                              rd_data => (others => '0'));
 
  constant c_TO_FIFO_INIT : t_TO_FIFO := (wr_en => '0',
                                          wr_data => (others => '0'),
                                          rd_en => '0');
   
   
end package example_record_pkg;

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
 
use work.example_record_pkg.all; -- USING PACKAGE HERE!
 
entity example_record is
  port (
    i_clk  : in  std_logic;
    i_fifo : in  t_FROM_FIFO;
    o_fifo : out t_TO_FIFO := c_TO_FIFO_INIT  -- intialize output record
    );
end example_record;
 
architecture behave of example_record is
 
  signal r_WR_DATA : unsigned(7 downto 0) := (others => '0');
   
begin
 
  -- Handles writes to the FIFO
  p_FIFO_WR : process (i_clk) is
  begin
    if rising_edge(i_clk) then
      if i_fifo.wr_full = '0' then
        o_fifo.wr_en   <= '1';
        o_fifo.wr_data <= std_logic_vector(r_WR_DATA + 1);
      end if;
    end if;
  end process p_FIFO_WR;
   
  -- Handles reads from the FIFO
  p_FIFO_RD : process (i_clk) is
  begin
    if rising_edge(i_clk) then
      if i_fifo.rd_empty = '0' then
        o_fifo.rd_en <= '1';
      end if;
    end if;
  end process p_FIFO_RD;
   
end behave;
