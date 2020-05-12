library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity test_entity_top is
end entity;

architecture test of test_entity_top is
  -- http://vhdl.renerta.com/mobile/source/vhd00006.htm
  type Real_Matrix is array (1 to 10) of REAL;
  type BYTE is array (0 to 7) of BIT;
  type Log_4_Vector is array (POSITIVE range 1 to 8, POSITIVE range 1 to 2) of Log_4;
  type X is (LOW, HIGH);
  type DATA_BUS is array (0 to 7, X) of BIT;

  -- unconstrained array of element of Real type:
  type Real_Matrix is array (POSITIVE range <>) of Real;
  variable Real_Matrix_Object : Real_Matrix (1 to 8);
  -- unconstrained array of elements of Log_4 type:
  type Log_4_Vector is array (NATURAL range <>, POSITIVE range<>) of Log_4;
  variable L4_Object : Log_4_Vector (0 to 7, 1 to 2);
begin
end architecture arch;
