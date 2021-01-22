LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
ARCHITECTURE rtl OF mux4_case IS
BEGIN
    p_mux: PROCESS(a, b, c, d, s)
    BEGIN
        CASE s IS
            WHEN "00" =>
                m <= a;
            WHEN "01" =>
                m <= b;
            WHEN "10" =>
                m <= c;
            WHEN OTHERS =>
                NULL;
        END CASE;
    END PROCESS;
END ARCHITECTURE;
