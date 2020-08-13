LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
ENTITY CarryLookaheadBlock IS
    GENERIC(
        SIZE : NATURAL := 4
    );
    PORT(
        Propagates : IN STD_LOGIC_VECTOR(SIZE - 1 DOWNTO 0);
        Generates : IN STD_LOGIC_VECTOR(SIZE - 1 DOWNTO 0);
        CarryIn : IN STD_LOGIC;
        CarryOuts : OUT STD_LOGIC_VECTOR(SIZE DOWNTO 0)
    );
END ENTITY;

ARCHITECTURE arch OF CarryLookaheadBlock IS
BEGIN
    ASSERT SIZE = 4 REPORT "Size must be 4 bits. This is only a building block." SEVERITY FAILURE;
    CarryOuts(0) <= CarryIn;
    CarryOuts(1) <= Generates(0) OR (Propagates(0) AND CarryIn);
    CarryOuts(2) <= Generates(1) OR (Propagates(1) AND Generates(0)) OR (Propagates(1) AND Propagates(0) AND CarryIn);
    CarryOuts(3) <= Generates(2) OR (Propagates(2) AND Generates(1)) OR (Propagates(2) AND Propagates(1) AND Generates(0)) OR (Propagates(2) AND Propagates(1) AND Propagates(0) AND CarryIn);
    CarryOuts(4) <= Generates(3) OR (Propagates(3) AND Generates(2)) OR (Propagates(3) AND Propagates(2) AND Generates(1)) OR (Propagates(3) AND Propagates(2) AND Propagates(1) AND Generates(0)) OR (Propagates(3) AND Propagates(2) AND Propagates(1) AND Propagates(0) AND CarryIn);
END ARCHITECTURE;
