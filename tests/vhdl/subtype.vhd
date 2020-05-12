library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity test_entity_top is
end entity;

architecture test of test_entity_top is
  -- http://vhdl.renerta.com/mobile/source/vhd00071.htm
  subtype DIGITS is INTEGER range 0 to 9;

  function RESOLVE_VALUE (anonymous: BIT_VECTOR) return BIT;
  subtype BIT_NEW is RESOLVE_VALUE BIT;
begin
end architecture;

