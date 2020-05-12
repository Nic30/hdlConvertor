ARCHITECTURE EXAMPLE OF ENUMERATION IS
    TYPE e1 IS (L, H);
    TYPE e2 IS ('0', '1');
    TYPE e3 IS ('0', '1', L, H);
    TYPE e4 IS (Init, Read, Decode, Execute, Write);
    SIGNAL s : e1;
BEGIN
    s <= L;
END ARCHITECTURE;
