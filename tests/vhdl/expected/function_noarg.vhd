LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
ENTITY test_entity_top IS
END ENTITY;

ARCHITECTURE test OF test_entity_top IS
    FUNCTION test_func RETURN integer
    IS
    BEGIN
        RETURN 42;
    END FUNCTION;
    CONSTANT test_const : integer := test_func;
BEGIN
END ARCHITECTURE;
