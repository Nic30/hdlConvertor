-- p. 14
-- A configuration of the microprocessor:
library TTL, Work;
configuration V4_27_87 of Processor is
	use Work.all;
	for Structure_View
		for A1: ALU
			use configuration TTL.SN74LS181;
		end for;
		for M1,M2,M3: MUX
			use entity Multiplex4 (Behavior);
		end for;
		for all: Latch
			-- use defaults
		end for;

		-- p. 16
		for Adders(31 downto 0)
			--
		end for;
		for Adders(0 to 31)
			--
		end for;
	
		-- p. 18
		-- A component configuration with binding indication:
		for all: IOPort
			use entity StdCells.PadTriState4 (DataFlow)
				port map (Pout=>A, Pin=>B, IO=>Dir, Vdd=>Pwr, Gnd=>Gnd);
		end for;
	    
		-- A component configuration containing block configurations:
		for D1: DSP
			for DSP_STRUCTURE
				-- Binding specified in design entity or else defaults.
				for Filterer
					-- Configuration items for filtering components.
				end for;
				for Processor
					-- Configuration items for processing components.
				end for;
			end for;
		end for;
	end for;
end configuration V4_27_87;

architecture A of E is
	component C is end component C;
	for L1: C use entity E1(X);
	for L2: C use entity E2(X);
begin
	L1: C;
	L2: C;
end architecture A;
configuration Illegal of Work.E is
	for A
		for all: C
			for X
				-- Does not apply to the same design entity in all instances of C.
			end for; -- X
		end for; -- C
	end for; -- A
end configuration Illegal;