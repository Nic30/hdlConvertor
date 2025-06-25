ARCHITECTURE arch OF module IS
    SIGNAL test : std_ulogic;
    SIGNAL test_vector : std_ulogic_vector(7 DOWNTO 0);
    ALIAS test_alias1 IS test;
    ALIAS test_alias2 : std_ulogic IS test;
    ALIAS test_vector_alias IS test_vector(1 DOWNTO 0);
BEGIN
END ARCHITECTURE;
