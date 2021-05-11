LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
ENTITY test_entity_top IS
END ENTITY;

ARCHITECTURE test OF test_entity_top IS
BEGIN
    PROCESS
    BEGIN
        OuterLoop: LOOP
            FOR i IN 3 TO 5 LOOP
                IF i = 5 THEN
                    EXIT OuterLoop;
                END IF;
            END LOOP;
        END LOOP;
    END PROCESS;
END ARCHITECTURE;
