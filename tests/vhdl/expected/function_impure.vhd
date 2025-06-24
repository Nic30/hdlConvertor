LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
ENTITY test_entity_top IS
END ENTITY;

ARCHITECTURE test OF test_entity_top IS
    SIGNAL test_signal : integer := 42;
BEGIN
    PROCESS(test_signal)
        IMPURE FUNCTION test_func RETURN integer
        IS
        BEGIN
            RETURN test_signal;
        END FUNCTION;
    BEGIN
    END PROCESS;
END ARCHITECTURE;
