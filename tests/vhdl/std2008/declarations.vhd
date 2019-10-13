-- p. 63
package p_63 is
-- p. 64
	type A is range 1 to 10;
	type B is range 1 to 10;

	-- p. 68
	constant TOLER: DISTANCE := 1.5 nm;
	constant PI: REAL := 3.141592;
	constant CYCLE_TIME: TIME := 100 ns;
	constant Propagation_Delay: DELAY_LENGTH; -- A deferred constant.

	-- p. 69
	signal S: STANDARD.BIT_VECTOR (1 to 10);
	signal CLK1, CLK2: TIME;
	signal OUTPUT: WIRED_OR MULTI_VALUED_LOGIC;

	

	variable INDEX: INTEGER range 0 to 99 := 0;
	-- Initial value is determined by the initial value expression
	variable COUNT: POSITIVE;
	-- Initial value is POSITIVE'LEFT; that is,1
	variable MEMORY: BIT_MATRIX (0 to 7, 0 to 1023);
	-- Initial value is the aggregate of the initial values of each	element
	shared variable Counter: SharedCounter;
	-- See 5.6.2 and 5.6.3 for the definitions of SharedCounter
	shared variable addend, augend, result: ComplexNumber;
	-- See 5.6.2 and 5.6.3 for the definition of ComplexNumber
	variable bit_stack: VariableSizeBitArray;
	-- See 5.6.2 and 5.6.3 for the definition of VariableSizeBitArray;


	-- p. 72
	type IntegerFile is file of INTEGER;
	file F1: IntegerFile;
	-- No implicit FILE_OPEN is performed during elaboration.
	file F2: IntegerFile is "test.dat";
	-- At elaboration, an implicit call is performed:
	-- FILE_OPEN (F2, "test.dat");

	-- p. 73
	-- The OPEN_KIND parameter defaults to READ_MODE.
	file F3: IntegerFile open WRITE_MODE is "test.dat";
	-- At elaboration, an implicit call is performed:
	-- FILE_OPEN (F3, "test.dat", WRITE_MODE);

end package;

-- p. 70
architecture UseSharedVariables of SomeEntity is
	subtype ShortRange is INTEGER range -1 to 1;
	type ShortRangeProtected is protected
		procedure Set (V: ShortRange);
		procedure Get (V: out ShortRange);
	end protected;
	type ShortRangeProtected is protected body
		variable Local: ShortRange := 0;

		procedure Set (V: ShortRange) is
		begin
			Local := V;
		end procedure Set;
		-- p. 71
		procedure Get (V: out ShortRange) is
		begin
			V := Local;
		end procedure Get;
	end protected body;

	shared variable ShortCounter: ShortRangeProtected;

begin
	PROC1: process
		variable V: ShortRange;
	begin
		ShortCounter.Get (V);
		ShortCounter.Set (V+1);
		wait;
	end process PROC1;

	PROC2: process
		variable V: ShortRange;
	begin
		ShortCounter.Get (V);
		ShortCounter.Set (V-1);
		wait;
	end process PROC2;
end architecture UseSharedVariables;

-- entity E is
-- 	port (P1: STRING; P2: STRING(P1'RANGE));                     	-- Illegal
-- 	procedure X (Y1, Y2: INTEGER; Y3: INTEGER range Y1 to Y2);   	-- Illegal
-- end E;
-- However, the following interface lists are legal:
entity E is
	generic (G1: INTEGER; G2: INTEGER := G1; G3, G4, G5, G6: INTEGER);
	port (P1, P2: STRING (G3 to G4));
	procedure X (Y3: INTEGER range G5 to G6);
end E;


-- p. 85
package fixed_generic_pkg is
	generic (fixed_round_style: BOOLEAN;
		fixed_overflow_style: BOOLEAN;
		fixed_guard_bits: NATURAL;
		no_warning: BOOLEAN);
	type ufixed is array (INTEGER range <>) of STD_ULOGIC;
	type sfixed is array (INTEGER range <>) of STD_ULOGIC;
end package fixed_generic_pkg;

-- The package may be instantiated in a design unit as follows:
package fixed_dsp_pkg is new IEEE.fixed_generic_pkg
	generic map (fixed_rounding_style => FALSE,
		fixed_overflow_style => FALSE,
		fixed_guard_bits => 0, no_warning => TRUE);

-- p. 86
package fixed_complex_generic_pkg is
	generic (complex_fixed_left, complex_fixed_right: INTEGER;
			package complex_fixed_formal_pkg is
				new IEEE.fixed_generic_pkg generic map (<>));
	use complex_fixed_formal_pkg.all;
	type complex is record
		re, im : sfixed(complex_fixed_left downto complex_fixed_right);
	end record;
	function "-" (z : complex ) return complex;
	function conj (z : complex ) return complex;
	function "+" (l: complex; r: complex) return complex;
	function "-" (l: complex; r: complex) return complex;
	function "*" (l: complex; r: complex) return complex;
	function "/" (l: complex; r: complex) return complex;
end package fixed_vector_generic_pkg;


package dsp_complex_pkg is new fixed_complex_generic_pkg
	generic map (complex_fixed_left => 3, complex_fixed_right => -12,
				 complex_fixed_formal_pkg => fixed_dsp_pkg);

package fixed_math_generic_pkg is
	generic (package math_fixed_formal_pkg is
			 new IEEE.fixed_generic_pkg generic map (<>));
	use math_fixed_formal_pkg.all;
	function sqrt (x: sfixed) return sfixed;
	function exp (x: sfixed) return sfixed;
end package fixed_math_generic_pkg;

package fixed_complex_math_generic_pkg is
	generic (complex_math_fixed_left, complex_math_fixed_right: integer;
		package complex_math_fixed_formal_pkg is
			new IEEE.fixed_generic_pkg generic map (<>);
		package fixed_math_formal_pkg is
			new fixed_math_generic_pkg
		-- p. 87
		generic map (math_fixed_formal_pkg =>
			complex_math_fixed_formal_pkg);
		package fixed_complex_formal_pkg is
			new fixed_complex_generic_pkg
			generic map (complex_fixed_left =>
				complex_math_fixed_left,
				complex_fixed_right =>
				complex_math_fixed_right,
				complex_fixed_formal_pkg =>
				complex_math_fixed_formal_pkg));
	use complex_math_fixed_formal_pkg.all,
		fixed_math_formal_pkg.all,
		fixed_complex_formal_pkg.all;
	function "abs" (z: complex) return sfixed;
	function arg (z: complex) return sfixed;
	function sqrt (z: complex) return complex;


	package dsp_math_pkg is new fixed_math_generic_pkg
		generic map ( math_fixed_formal_pkg => fixed_dsp_pkg );
	package dsp_complex_math_pkg is new fixed_complex_math_generic_pkg
		generic map (complex_math_fixed_left => 3,
			complex_math_fixed_right => 3,
			complex_math_fixed_formal_pkg => fixed_dsp_pkg,
			fixed_math_formal_pkg => dsp_math_pkg,
			fixed_complex_formal_pkg => dsp_complex_pkg);

end package fixed_complex_math_generic_pkg;
