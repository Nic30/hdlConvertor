LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY multiplexer4_1 IS
    PORT(
        i0 : IN std_logic,
        i1 : IN std_logic,
        i2 : IN std_logic,
        i3 : IN std_logic,
        sel : IN std_logic_vector((1 DOWNTO 0)),
        bitout : OUT std_logic
    );
END ENTITY;

ARCHITECTURE Behavioral OF multiplexer4_1 IS
BEGIN
    PROCESS(i0, i1, i2, i3, sel)
    BEGIN
        CASE sel IS
            WHEN "00" =>
                bitout <= i0;
            WHEN "01" =>
                bitout <= i1;
            WHEN "10" =>
                bitout <= i2;
            WHEN OTHERS =>
                bitout <= i2;
        END CASE;
    END PROCESS;
END ARCHITECTURE
