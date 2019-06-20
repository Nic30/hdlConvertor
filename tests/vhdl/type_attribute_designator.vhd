
architecture Behavioral of file_read is
begin

	process (all)
	begin

		L1: write(buf_out, string'("This is an example offormatted IO"));
		L2: writeline(outfile, buf_out);
		L3: write(buf_out, string'("Enter the parameter"));
		L4: writeline(outfile, buf_out);
		L5: readline(infile, buf_in);
		L6: read(buf_in, count);
		L7: write(buf_out, string'("The parameter is="));
		L8: write(buf_out, count);
		L9: writeline(outfile, buf_out);
		L10: file_close(outfile);
		wait;
	end process;
end architecturebeh;