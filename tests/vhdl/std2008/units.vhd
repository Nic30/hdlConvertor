
architecture test of test_ent is
	variable x: distance;
	variable y: duration;
	variable z: integer;
begin
	process
	begin
		x := 5 Å + 13 ft - 27 inch;
		y := 3 ns + 5 min;
		z := ns / ps;
		x := z * mi;
		y := y/10;
		z := 39.34 inch / m;
	end process;
end architecture;
