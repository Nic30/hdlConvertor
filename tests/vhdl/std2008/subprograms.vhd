-- p. 25
package P is
	function F return INTEGER;
	attribute FOREIGN of F: function is
		"implementation-dependent information";

	-- p. 27
	-- Declarations of overloaded subprograms:
	procedure Dump (F: inout Text; Value: Integer);
	procedure Dump (F: inout Text; Value: String);
	procedure Check (Setup: Time; signal D: Data; signal C: Clock);
	procedure Check (Hold: Time; signal C: Clock; signal D: Data);
	
	-- Ambiguous if the base type of DataBus is the same type
	-- as the base type of Clk.

	-- p. 28
	type MVL is ('0', '1', 'Z', 'X');
	type MVL_Vector is array (Natural range <>) of MVL;
	function "and" (Left, Right: MVL) return MVL;
	function "or" (Left, Right: MVL) return MVL;
	function "not" (Value: MVL) return MVL;
	function "xor" (Right: MVL_Vector) return MVL;

	-- p. 29
	attribute BuiltIn of "or" [MVL, MVL return MVL]: function is TRUE;
		-- Because of the presence of the signature, this attribute
		-- specification decorates only the "or" function defined in 4.5.2.
	attribute Mapping of JMP [return OpCode] :literal is "001";

end package P;

-- p. 27
architecture SUBPROG of DISP_MUX is
	signal Q,R,S,T: MVL;
	signal V: MVL_Vector(0 to 3);
		function WIRED_OR (Inputs: BIT_VECTOR) return BIT is
		constant FloatValue: BIT := '0';
	begin
		if Inputs'Length = 0 then
			-- This is a bus whose drivers are all off.
			return FloatValue;
		else
			for I in Inputs'Range loop
				if Inputs(I) = '1' then
					return '1';
				end if;
			end loop;
			return '0';
		end if;
	end function WIRED_OR;
begin
	-- Calls to overloaded subprograms:
	Dump (Sys_Output, 12);
	Dump (Sys_Error, "Actual output does not match expected output");
	Check (Setup=>10 ns, D=>DataBus, C=>Clk1);
	Check (Hold=>5 ns, D=>DataBus, C=>Clk2);
	Check (15 ns, DataBus, Clk) ;

	Q <= 'X' or '1';
	R <= "or" ('0','Z');
	S <= (Q and R) or not S;
	T <= xor V;
end SUBPROG;