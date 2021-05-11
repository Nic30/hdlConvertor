library ieee;
use ieee.std_logic_1164.all;

entity test_entity_top is
end entity;

architecture test of test_entity_top is
  function test_func
    return integer is
  begin
    return 42;
  end function;
  constant test_const : integer := test_func;
begin
end architecture;