--------------------------------------------------------------------------------
--                    RightShifter_8_by_max_10_F700_uid80
-- This operator is part of the Infinite Virtual Library FloPoCoLib
-- All rights reserved 
-- Authors: Bogdan Pasca, Florent de Dinechin (2008-2011)
--------------------------------------------------------------------------------
-- Pipeline depth: 1 cycles

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library std;
use std.textio.all;
library work;

entity RightShifter_8_by_max_10_F700_uid80 is
   port ( clk, rst : in std_logic;
          X : in  std_logic_vector(7 downto 0);
          S : in  std_logic_vector(3 downto 0);
          R : out  std_logic_vector(17 downto 0)   );
end entity;

architecture arch of RightShifter_8_by_max_10_F700_uid80 is
signal level0 :  std_logic_vector(7 downto 0);
signal ps, ps_d1 :  std_logic_vector(3 downto 0);
signal level1 :  std_logic_vector(8 downto 0);
signal level2, level2_d1 :  std_logic_vector(10 downto 0);
signal level3 :  std_logic_vector(14 downto 0);
signal level4 :  std_logic_vector(22 downto 0);
begin
   process(clk)
      begin
         if clk'event and clk = '1' then
            ps_d1 <=  ps;
            level2_d1 <=  level2;
         end if;
      end process;
   level0<= X;
   ps<= S;
   level1<=  (0 downto 0 => '0') & level0 when ps(0) = '1' else    level0 & (0 downto 0 => '0');
   level2<=  (1 downto 0 => '0') & level1 when ps(1) = '1' else    level1 & (1 downto 0 => '0');
   ----------------Synchro barrier, entering cycle 1----------------
   level3<=  (3 downto 0 => '0') & level2_d1 when ps_d1(2) = '1' else    level2_d1 & (3 downto 0 => '0');
   level4<=  (7 downto 0 => '0') & level3 when ps_d1(3) = '1' else    level3 & (7 downto 0 => '0');
   R <= level4(22 downto 5);
end architecture;