LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
ARCHITECTURE behave OF Example_For_Loop IS
    SIGNAL r_Shift_With_For : std_logic_vector(3 DOWNTO 0) := X"1";
    SIGNAL r_Shift_Regular : std_logic_vector(3 DOWNTO 0) := X"1";
BEGIN
    p_Shift_With_For: PROCESS(i_Clock)
    BEGIN
        IF rising_edge(i_Clock) THEN
            FOR ii IN 0 TO 2 LOOP
                r_Shift_With_For(ii + 1) <= r_Shift_With_For(ii);
            END LOOP;
        END IF;
    END PROCESS;
END ARCHITECTURE;
