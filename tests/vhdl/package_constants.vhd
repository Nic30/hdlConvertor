library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

package constants_pkg is
 function fn1(bits : integer) return integer;
 function fn0(n: integer ; diff :integer) return integer;
 function eval_log2(n: integer) return integer;

 CONSTANT MTR_MBIST_ARCHITECTURE      : std_logic := '1';
 CONSTANT CONST_NATURAL 	      : natural := 24;
 CONSTANT NATURAL_WITH_RANGE	      : natural range 0 to CONST_NATURAL  := 256;
 CONSTANT MAX_NCUTSEL		      : natural := NATURAL_WITH_RANGE+((2*eval_log2(NATURAL_WITH_RANGE/2))-1);
 CONSTANT NREGS			      : natural := 103+(CONST_NATURAL*CONST_NATURAL)+5+CONST_NATURAL+6+6;
 TYPE lb_res_reg 		 is array (fn1(CONST_NATURAL) downto 0) of std_logic_vector(31 downto 0);
 TYPE prpg_size			 is array (fn1(CONST_NATURAL) downto 0) of natural;

 CONSTANT CONST_32b_0	      	      : std_logic_vector(31 downto 0):= "00000000000000000000000000000000";
 CONSTANT CONST_32b_0_1		      : std_logic_vector(31 downto 0):= X"00000000";
 CONSTANT CONST_128b_0		      : std_logic_vector(127 downto 0):= X"00000000000000000000000000000000";
 CONSTANT CONST_512b_0		      : std_logic_vector(511 downto 0):= X"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
 CONSTANT CONST_expr_b_0              : std_logic_vector(fn1(CONST_NATURAL) downto 0) := (others => '1');
 CONSTANT CONST_expr_b_1		: std_logic_vector(fn1(CONST_NATURAL) downto 0) := "1000000000";
 CONSTANT CONST_32b_expr_0		: std_logic_vector(31 downto 0) := CONST_32b_0 + X"0000_0008";
 CONSTANT CONST_32b_expr_0		: std_logic_vector(31 downto 0) := CONST_32b_0_1 + X"0000_0070" ;

 CONSTANT TestConst4 : TestArray2DUU(TestInt'range, 100 downto -100)(10 downto 0); 

end constants_pkg;

