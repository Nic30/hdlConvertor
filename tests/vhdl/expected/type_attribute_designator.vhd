ARCHITECTURE Behavioral OF file_read IS
BEGIN
    PROCESS(ALL)
    BEGIN
        write(buf_out, string'("This is an example offormatted IO"));
        writeline(outfile, buf_out);
        write(buf_out, string'("Enter the parameter"));
        writeline(outfile, buf_out);
        readline(infile, buf_in);
        read(buf_in, count);
        write(buf_out, string'("The parameter is="));
        write(buf_out, count);
        writeline(outfile, buf_out);
        file_close(outfile);
        WAIT;
    END PROCESS;
END ARCHITECTURE;
