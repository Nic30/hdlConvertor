-- p. 31
-- A package declaration that needs no package body:
package TimeConstants is
	constant tPLH: Time := 10 ns;
	constant tPHL: Time := 12 ns;
	constant tPLZ: Time := 7 ns;
	constant tPZL: Time := 8 ns;
	constant tPHZ: Time := 8 ns;
	constant tPZH: Time := 9 ns;
end TimeConstants;

-- A package declaration that needs a package body:
package TriState is
	type Tri is ('0', '1', 'Z', 'E');
	function BitVal (Value: Tri) return Bit;
	function TriVal (Value: Bit) return Tri;
	type TriVector is array (Natural range <>) of Tri;
	function Resolve (Sources: TriVector) return Tri;
end package TriState;

-- p. 32
package body TriState is
	function BitVal (Value: Tri) return Bit is
		constant Bits : Bit_Vector := "0100";
	begin
		return Bits(Tri'Pos(Value));
	end;
	function TriVal (Value: Bit) return Tri is
	begin
		return Tri'Val(Bit'Pos(Value));
	end;
	function Resolve (Sources: TriVector) return Tri is
		variable V: Tri := 'Z';
	begin
		for i in Sources'Range loop
			if Sources(i) /= 'Z' then
				if V = 'Z' then
					V := Sources(i);
				else
					return 'E';
				end if;
			end if;
		end loop;
		return V;
	end;

	-- p. 34
	procedure P (X,Y: INTEGER) is begin end;
	procedure P (X: INTEGER; Y: INTEGER) is begin end;
	procedure P (X,Y: in INTEGER) is begin end;

end package body TriState;