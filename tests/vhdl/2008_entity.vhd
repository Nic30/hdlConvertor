-- p. 8
entity Full_Adder is
port (X, Y, Cin: in Bit; Cout, Sum: out Bit);
end Full_Adder;

-- An entity declaration with generic declarations also:
entity AndGate is
generic (N: Natural := 2);
port (Inputs: in Bit_Vector (1 to N);
Result: out Bit);
end entity AndGate;

-- An entity declaration with neither:
entity TestBench is
end TestBench;

-- p. 9
entity ROM is
	port (Addr: in Word;
			Data: out Word;
			Sel: in Bit);
	type Instruction is array (1 to 5) of Natural;
	type Program is array (Natural range <>) of Instruction;

	use Work.OpCodes.all, Work.RegisterNames.all;
	constant ROM_Code: Program := (
		(STM, R14, R12, 12, R13),
		(LD, R7, 32, 0, R1 ),
		(BAL, R14, 0, 0, R7 )
	);
end ROM;

-- p. 10
-- An entity declaration with statements:
entity Latch is
	port (Din: in Word;
		Dout: out Word;
		Load: in Bit;
		Clk: in Bit );
	constant Setup: Time := 12 ns;
	constant PulseWidth: Time := 50 ns;
	use Work.TimingMonitors.all;
begin
	assert Clk='1' or Clk'Delayed'Stable (PulseWidth);
	CheckTiming (Setup, Din, Load, Clk);
end;