library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

package types is
    type TestEnum is (TestEnum1, TestEnum2, TestEnum3);

    type TestArray1DUB is array (NATURAL range <>) of STD_LOGIC_VECTOR(7 downto 0);
    type TestArray1DUU is array (NATURAL range <>) of STD_LOGIC_VECTOR;
    type TestArray1DBB is array (7 downto 0) of STD_LOGIC_VECTOR(7 downto 0);
    type TestArray1DBU is array (7 downto 0) of STD_LOGIC_VECTOR;

    type TestArray2DUB is array (NATURAL range <>, NATURAL range <>) of STD_LOGIC_VECTOR(7 downto 0);
    type TestArray2DUU is array (NATURAL range <>, NATURAL range <>) of STD_LOGIC_VECTOR;
    type TestArray2DBB is array (7 downto 0, 7 downto 0) of STD_LOGIC_VECTOR(7 downto 0);
    type TestArray2DBU is array (7 downto 0, 7 downto 0) of STD_LOGIC_VECTOR;

    type TestInt is range -100 to 100;
    type TestFloat is range 1.0E10 to 2.0E10;
    subtype TestInt2 is TestInt range 0 to TestInt'HIGH;
    subtype TestFloat2 is TestFloat range 0.0E100 to TestFloat'HIGH;
    type TIME is range -2147483647 to 2147483647
        units
            fs;
            ps = 1000 fs;
            ns = 1000 ps;
            us = 1000 ns;
            ms = 1000 us;
            sec = 1000 ms;
            min = 60 sec;
            hr = 60 min;
        end units;
end package;