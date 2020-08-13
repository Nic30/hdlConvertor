ARCHITECTURE GEN OF REG_BANK IS
    COMPONENT REG IS
        PORT(
            D : IN std_ulogic;
            CLK : IN std_ulogic;
            RESET : IN std_ulogic;
            Q : OUT std_ulogic
        );
    END COMPONENT;
BEGIN
    GEN_REG: FOR I IN 0 TO 3 GENERATE
        REGX: REG PORT MAP(
            DIN(I),
            CLK,
            RESET,
            DOUT(I)
        );
    END GENERATE;
END ARCHITECTURE;
