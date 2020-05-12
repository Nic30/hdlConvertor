library ieee;
use ieee.std_logic_1164.all;
 
architecture behave of example_record is
  type register_0_t is record
    pll_lock    : std_logic;
    cnt_limit   : std_logic_vector(9 downto 0);
    latency     : std_logic_vector(20 downto 0);
  end record;

  type register_record_t is record
    register_0  : register_0_t;
    register_1 : register_1_t;
  end record; 

  signal r_WR_DATA : register_record_t;
begin
  regs.register_0.pll_lock  <= '1';
end architecture;

