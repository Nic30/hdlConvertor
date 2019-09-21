-- p. 12
-- A body of entity Full_Adder:
architecture DataFlow of Full_Adder is
	signal A,B: Bit;
begin
	A <= X xor Y;
	B <= A and Cin;
	Sum <= A xor Cin;
	Cout <= B or (X and Y);
end architecture DataFlow;

-- A body of entity TestBench:
library Test;
use Test.Components.all;
architecture Structure of TestBench is
	component Full_Adder
		port (X, Y, Cin: Bit; Cout, Sum: out Bit);
	end component;
	signal A,B,C,D,E,F,G: Bit;
	signal OK: Boolean;
begin
	UUT:
	Full_Adder port map (A,B,C,D,E);
	Generator: AdderTest port map (A,B,C,F,G);
	Comparator: AdderCheck port map (D,E,F,G,OK);
end Structure;

-- A body of entity AndGate:
architecture Behavior of AndGate is
begin
	process (Inputs)
		variable Temp: Bit;
	begin
		Temp := '1';
		for i in Inputs'Range loop
			if Inputs(i) = '0' then
				Temp := '0';
				exit;
			end if;
		end loop;
		Result <= Temp after 10 ns;
	end process;
end Behavior;

-- p. 13
-- An architecture of a microprocessor:
architecture Structure_View of Processor is
	component ALU port ( Cin: Bit ); end component;
	component MUX port ( Cin: Bit ); end component;
	component Latch port ( Cin: Bit ); end component;
begin
	A1: ALU port map ( X );
	M1: MUX port map ( X );
	M2: MUX port map ( X );
	M3: MUX port map ( X );
	L1: Latch port map ( X );
	L2: Latch port map ( X );
end Structure_View;
