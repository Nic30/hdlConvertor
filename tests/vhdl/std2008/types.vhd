-- p. 49
entity E is
	generic (ROM: Memory);
	port (Op1, Op2: in Word; Result: out Word);
end entity E;
	
-- p. 38
package p_38 is

	type MULTI_LEVEL_LOGIC is (LOW, HIGH, RISING, FALLING, AMBIGUOUS);
	type BIT is ('0','1');
	type SWITCH_LEVEL is ('0','1','X');
	-- Overloads '0' and '1'

	-- p. 39
	type TWOS_COMPLEMENT_INTEGER is range -32768 to 32767;
	type BYTE_LENGTH_INTEGER is range 0 to 255;
	type WORD_INDEX is range 31 downto 0;
	subtype HIGH_BIT_LOW is BYTE_LENGTH_INTEGER range 0 to 127;

	-- p. 40
	type DURATION is range -1E18 to 1E18
	units
		fs; --femtosecond
		ps = 1000 fs; --picosecond
		ns = 1000 ps; --nanosecond
		us = 1000 ns; --microsecond
		ms = 1000 us; --millisecond
		sec = 1000 ms; --second
		min = 60 sec; --minute
	end units;
	type DISTANCE is range 0 to 1E16
		units
			-- primary unit:
			Å; -- metric lengths: --angstrom
			nm = 10 Å;            --nanometer
			um = 1000 nm;         --micrometer (or micron)
			mm = 1000 um;         --millimeter
			cm = 10 mm;           --centimeter
			m  = 1000 mm;         --meter
			km = 1000 m;          --kilometer
			-- English lengths:
			mil = 254000 Å;       --mil
			inch = 1000 mil;      --inch
			ft = 12 inch;         --foot
			yd = 3 ft;            --yard
			fm = 6 ft;            --fathom
			mi = 5280 ft;         --mile
			lg = 3 mi;            --league
		end units DISTANCE;




	-- p. 42
	function MINIMUM (L, R: T) return T;
	function MAXIMUM (L, R: T) return T;
	-- p. 43
	function TO_STRING (VALUE: T) return STRING;
	function RISING_EDGE (signal S: BOOLEAN) return BOOLEAN;
	function FALLING_EDGE (signal S: BOOLEAN) return BOOLEAN;
	function RISING_EDGE (signal S: BIT) return BOOLEAN;
	function FALLING_EDGE (signal S: BIT) return BOOLEAN;
	function TO_STRING (VALUE: TIME; UNIT: TIME) return STRING;
	function TO_STRING (VALUE: REAL; DIGITS: NATURAL) return STRING;
	function TO_STRING (VALUE: REAL; FORMAT: STRING) return STRING;

	-- p. 46

	-- Examples of fully constrained array declarations:
	type MY_WORD is array (0 to 31) of BIT;
	-- A memory word type with an ascending range.
	type DATA_IN is array (7 downto 0) of FIVE_LEVEL_LOGIC;
	-- An input port type with a descending range.
	-- Example of partially constrained array declarations:
	type MEMORY is array (INTEGER range <>) of MY_WORD;
	-- A memory array type.
	-- Example of unconstrained array declarations:
	type SIGNED_FXPT is array (INTEGER range <>) of BIT;
	-- A signed fixed-point array type
	type SIGNED_FXPT_VECTOR is array (NATURAL range <>) of SIGNED_FXPT;
	-- A vector of signed fixed-point elements
	-- Example of partially constrained array declarations:
	type SIGNED_FXPT_5x4 is array (1 to 5, 1 to 4) of SIGNED_FXPT;
	-- A matrix of signed fixed-point elements
	-- Examples of array object declarations:
	signal DATA_LINE: DATA_IN;
	-- Defines a data input line.
	variable MY_MEMORY: MEMORY (0 to 2**n-1);
	-- Defines a memory of 2 n 32-bit words.
	signal FXPT_VAL: SIGNED_FXPT (3 downto -4);
	-- Defines an 8-bit fixed-point signal
	signal VEC: SIGNED_FXPT_VECTOR (1 to 20)(9 downto 0);
	-- Defines a vector of 20 10-bit fixed-point elements
	variable SMATRIX: SIGNED_FXPT_5x4 (open)(3 downto -4);
	-- Defines a 5x4 matrix of 8-bit fixed-point elements

	type T is array (POSITIVE range MIN_BOUND to MAX_BOUND) of ELEMENT;

	-- p. 47
	subtype index_subtype is POSITIVE range MIN_BOUND to MAX_BOUND;
	type array_type is array (index_subtype range <>) of ELEMENT'BASE;
	subtype T is array_type (index_subtype)element_constraint;
	type T is array (INTEGER range <>) of STRING(1 to 10);
	type array_type is array (INTEGER range <>) of STRING'BASE;
	subtype T is array_type (open)(1 to 10);


	-- p. 48
	type Word is array (NATURAL range <>) of BIT;
	type Memory is array (NATURAL range <>) of Word (31 downto 0);
	constant A_Word: Word := "10011";
	-- The index range of A_Word is 0 to 4


	-- The index ranges of the generic and the ports are defined by
	-- the actuals associated with an instance bound to E; these index
	-- ranges are accessible via the predefined array attributes
	-- (see 16.2).
	signal A, B: Word (1 to 4);
	signal C: Word (5 downto 0);
	Instance: entity E
		generic map (ROM(1 to 2) => (others => (others => '0')))
		port map (A, Op2(3 to 4) => B(1 to 2), Op2(2) => B(3),
				Result => C(3 downto 1));
			-- In this instance, the index range of ROM is 1 to 2 (matching
			-- that of the actual), the index range of Op1 is 1 to 4 (matching
			-- the index range of A), the index range of Op2 is 2 to 4, and
			-- the index range of Result is (3 downto 1) (again matching the
			-- index range of the actual).

	type E is array (NATURAL range <>) of INTEGER;
	type T is array (1 to 10) of E (1 to 0);

	-- Predefined array types
	subtype POSITIVE is INTEGER range 1 to INTEGER'HIGH;
	type STRING is array (POSITIVE range <>) of CHARACTER;

	subtype NATURAL is INTEGER range 0 to INTEGER'HIGH;
	type BOOLEAN_VECTOR is array (NATURAL range <>) of BOOLEAN;
	type BIT_VECTOR is array (NATURAL range <>) of BIT;
	type INTEGER_VECTOR is array (NATURAL range <>) of INTEGER;
	type REAL_VECTOR is array (NATURAL range <>) of REAL;
	type TIME_VECTOR is array (NATURAL range <>) of TIME;

	-- p. 50
	variable MESSAGE: STRING (1 to 17) := "THIS IS A MESSAGE";
	signal LOW_BYTE: BIT_VECTOR (0 to 7);
	constant MONITOR_ELEMENTS: BOOLEAN_VECTOR (LOW_BYTE'RANGE) := (others => FALSE);
	constant ELEMENT_DELAYS: TIME_VECTOR (LOW_BYTE'RANGE) := (others => UNIT_DELAY);
	variable BUCKETS: INTEGER_VECTOR (1 to 10);
	variable AVERAGES: REAL_VECTOR (1 to 10);

	function MINIMUM (L, R: T) return T;
	function MAXIMUM (L, R: T) return T;

	function MINIMUM (L: T) return E;
	function MAXIMUM (L: T) return E;

	-- p. 51
	alias TO_BSTRING is TO_STRING [BIT_VECTOR return STRING];
	alias TO_BINARY_STRING is TO_STRING [BIT_VECTOR return STRING];
	function TO_OSTRING (VALUE: BIT_VECTOR) return STRING;
	alias TO_OCTAL_STRING is TO_OSTRING [BIT_VECTOR return STRING];
	function TO_HSTRING (VALUE: BIT_VECTOR) return STRING;
	alias TO_HEX_STRING is TO_HSTRING [BIT_VECTOR return STRING];

	-- p. 52
	type DATE is
		record
			DAY : INTEGER range 1 to 31;
			MONTH : MONTH_NAME;
			YEAR : INTEGER range 0 to 4000;
		end record;
	type SIGNED_FXPT_COMPLEX is
		record
			RE : SIGNED_FXPT;
			IM : SIGNED_FXPT;
		end record;
	signal COMPLEX_VAL: SIGNED_FXPT_COMPLEX (RE(4 downto -16),
		IM(4 downto -12));

	-- p. 53
	type ADDRESS is access MEMORY;
	type BUFFER_PTR is access TEMP_BUFFER;

	-- p. 54
	-- Example of a recursive type:
	type CELL;
	-- An incomplete type declaration.
	type LINK is access CELL;
	type CELL is
		record
			VALUE : INTEGER;
			SUCC : LINK;
			PRED : LINK;
		end record CELL;
	variable HEAD: LINK := new CELL'(0, null, null);
	variable \NEXT\: LINK := HEAD.SUCC;
	-- Examples of mutually dependent access types:
	type PART;
	type WIRE;
	-- Incomplete type declarations.
	type PART_PTR is access PART;
	type WIRE_PTR is access WIRE;
	type PART_LIST is array (POSITIVE range <>) of PART_PTR;
	type WIRE_LIST is array (POSITIVE range <>) of WIRE_PTR;
	type PART_LIST_PTR is access PART_LIST;
	type WIRE_LIST_PTR is access WIRE_LIST;
	type PART is
		record
			PART_NAME : STRING (1 to MAX_STRING_LEN);
			CONNECTIONS : WIRE_LIST_PTR;
		end record;
	type WIRE is
		record
			WIRE_NAME : STRING (1 to MAX_STRING_LEN);
			CONNECTS : PART_LIST_PTR;
		end record;

	-- p. 55
	type AT is access T;
	procedure DEALLOCATE (P: inout AT);

	type FT is file of TM;
	procedure FILE_OPEN (file F: FT;
						 External_Name: in STRING;
						 Open_Kind: in FILE_OPEN_KIND := READ_MODE);
	procedure FILE_OPEN (Status: out FILE_OPEN_STATUS;
			file F: FT;
			External_Name: in STRING;
			Open_Kind: in FILE_OPEN_KIND := READ_MODE);
	procedure FILE_CLOSE (file F: FT);
	procedure READ (file F: FT; VALUE: out TM);
	procedure WRITE (file F: FT; VALUE: in TM);
	procedure FLUSH (file F: FT);
	function ENDFILE (file F: FT) return BOOLEAN;

	-- p. 56
	procedure READ (file F: FT; VALUE: out TM; LENGTH: out Natural);

	-- p. 59
	type SharedCounter is protected
		procedure increment (N: Integer := 1);
		procedure decrement (N: Integer := 1);
		impure function value return Integer;
	end protected SharedCounter;
	type ComplexNumber is protected
		procedure extract (variable r, i: out Real);
		procedure add (variable a, b: inout ComplexNumber);
	end protected ComplexNumber;
	type VariableSizeBitArray is protected
		procedure add_bit (index: Positive; value: Bit);
		impure function size return Natural;
	end protected VariableSizeBitArray;

	-- p. 60
	type SharedCounter is protected body
		variable counter: Integer := 0;

		procedure increment (N: Integer := 1) is
		begin
			counter := counter + N;
		end procedure increment;

		procedure decrement (N: Integer := 1) is
		begin
			counter := counter - N;
		end procedure decrement;

		impure function value return Integer is
		begin
			return counter;
		end function value;
	end protected body SharedCounter;
	type ComplexNumber is protected body
		variable re, im: Real;

		procedure extract (r, i: out Real) is
		begin
			r := re;
			i := im;
		end procedure extract;

		procedure add (variable a, b: inout ComplexNumber) is
			variable a_real, b_real: Real;
			variable a_imag, b_imag: Real;
		begin
			a.extract (a_real, a_imag);
			b.extract (b_real, b_imag);
			re := a_real + b_real;
			im := a_imag + b_imag;
		end procedure add;
	end protected body ComplexNumber;

	type VariableSizeBitArray is protected body
		type bit_vector_access is access Bit_Vector;
		variable bit_array: bit_vector_access := null;
		variable bit_array_length: Natural := 0;
		procedure add_bit (index: Positive; value: Bit) is
			variable tmp: bit_vector_access;
	-- p. 61
		begin
			if index > bit_array_length then
				tmp := bit_array;
				bit_array := new bit_vector (1 to index);
				if tmp /= null then
					bit_array (1 to bit_array_length) := tmp.all;
					deallocate (tmp);
				end if;
				bit_array_length := index;
			end if;
			bit_array (index) := value;
		end procedure add_bit;
		impure function size return Natural is
		begin
			return bit_array_length;
		end function size;
	end protected body VariableSizeBitArray;

end package;


architecture test of test_ent is
	variable x: distance;
	variable y: duration;
	variable z: integer;
begin
	x := 5 Å + 13 ft - 27 inch;
	y := 3 ns + 5 min;
	z := ns / ps;
	x := z * mi;
	y := y/10;
	z := 39.34 inch / m;
end architecture;
