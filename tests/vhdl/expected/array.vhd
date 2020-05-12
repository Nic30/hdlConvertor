LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
ENTITY test_entity_top IS
END ENTITY;

ARCHITECTURE test OF test_entity_top IS
    TYPE Real_Matrix IS ARRAY (1 TO 10) OF REAL;
    TYPE BYTE IS ARRAY (0 TO 7) OF BIT;
    TYPE Log_4_Vector IS ARRAY (POSITIVE RANGE 1 TO 8, POSITIVE RANGE 1 TO 2) OF Log_4;
    TYPE X IS (LOW, HIGH);
    TYPE DATA_BUS IS ARRAY (0 TO 7, X) OF BIT;
    TYPE Real_Matrix IS ARRAY (POSITIVE RANGE <>) OF Real;
    VARIABLE Real_Matrix_Object : Real_Matrix(1 TO 8);
    TYPE Log_4_Vector IS ARRAY (NATURAL RANGE <>, POSITIVE RANGE <>) OF Log_4;
    VARIABLE L4_Object : Log_4_Vector(0 TO 7, 1 TO 2);
BEGIN
END ARCHITECTURE;
