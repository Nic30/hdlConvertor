ENTITY entity_declarative_item IS
    PORT(
        Addr : IN Word;
        Data : OUT Word;
        Sel : IN Bit
    );
    TYPE Instruction IS ARRAY (1 TO 5) OF Natural;
    TYPE Program IS ARRAY (Natural RANGE <>) OF Instruction;
    USE Work.OpCodes.ALL;
    USE Work.RegisterNames.ALL;
    CONSTANT ROM_Code : Program := ((
            STM,
            R14,
            R12,
            12,
            R13), (
            LD,
            R7,
            32,
            0,
            R1), (
            BAL,
            R14,
            0,
            0,
            R7));
END ENTITY;

