library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity CarryLookaheadBlock is
	Generic
	(
		SIZE						: NATURAL 				:= 		4
	);
	PORT
	(
        Propagates							: in 				STD_LOGIC_VECTOR(SIZE-1 downto 0);
        Generates							: in 				STD_LOGIC_VECTOR(SIZE-1 downto 0);
        CarryIn								: in 				STD_LOGIC;
        CarryOuts							: out 			    STD_LOGIC_VECTOR(SIZE downto 0)
	);
end entity ; -- CarryLookaheadBlock

architecture arch of CarryLookaheadBlock is
begin

	-- *************************************  C H E C K S ************************************* --
	assert (SIZE = 4) report "Size must be 4 bits. This is only a building block." severity FAILURE;

	-- **************************************  L O G I C ************************************** --
	CarryOuts(0) <= CarryIn;
	CarryOuts(1) <= Generates(0) or (Propagates(0) and CarryIn);
	CarryOuts(2) <= Generates(1) or (Propagates(1) and Generates(0)) or (Propagates(1) and Propagates(0) and CarryIn);
	CarryOuts(3) <= Generates(2) or (Propagates(2) and Generates(1)) or (Propagates(2) and Propagates(1) and Generates(0)) or (Propagates(2) and Propagates(1) and Propagates(0) and CarryIn);
	CarryOuts(4) <= Generates(3) or (Propagates(3) and Generates(2)) or (Propagates(3) and Propagates(2) and Generates(1)) or (Propagates(3) and Propagates(2) and Propagates(1) and Generates(0)) or (Propagates(3) and Propagates(2) and Propagates(1) and Propagates(0) and CarryIn);


end architecture ; -- arch