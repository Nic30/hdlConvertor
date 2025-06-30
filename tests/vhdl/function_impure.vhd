library ieee;
use ieee.std_logic_1164.all;

entity test_entity_top is
end entity;

architecture test of test_entity_top is
  signal test_signal : integer := 42;
begin
  process(test_signal)
    impure function test_func
        return integer is
      begin
        return test_signal;
    end function;
  begin
  end process;
end architecture;