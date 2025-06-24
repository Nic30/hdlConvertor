architecture arch of module is
    signal test : std_ulogic;
    signal test_vector : std_ulogic_vector(7 downto 0);
    alias test_alias1 is test;
    alias test_alias2 : std_ulogic is test;
    alias test_vector_alias is test_vector(1 downto 0);
begin
end architecture arch;
