library ieee;
use ieee.std_logic_1164.all;

entity test_entity_top is
end entity;

architecture test of test_entity_top is
begin
  process
  begin
    OuterLoop : loop
      for i in 3 to 5 loop
        if i = 5 then
          exit OuterLoop;
        end if;
      end loop;
    end loop;
  end process;
end architecture;