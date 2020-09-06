LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
-- http://cseweb.ucsd.edu/~hepeng/cse143-w08/labs/VHDLReference/05.pdf
ENTITY proc IS
    PORT(
        A : IN STD_LOGIC;
        B : IN STD_LOGIC;
        C : IN STD_LOGIC;
        D : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        o1 : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
        Tri_out : INOUT STD_LOGIC
    );
END ENTITY;

ARCHITECTURE maxpld OF proc IS
    PROCEDURE op_example (SIGNAL A : INTEGER;
        SIGNAL B : INTEGER;
        SIGNAL C : INTEGER;
        SIGNAL bool : BOOLEAN;
        SIGNAL a1 : STD_LOGIC_VECTOR(0 TO 3);
        SIGNAL a2 : STD_LOGIC_VECTOR(0 TO 3))
    IS
        VARIABLE res : integer;
        VARIABLE L : BOOLEAN;
        VARIABLE M : BOOLEAN;
        VARIABLE N : BOOLEAN;
        VARIABLE O : BOOLEAN;
        VARIABLE P : BOOLEAN;
        VARIABLE V0 : BIT_VECTOR(3 DOWNTO 0);
        VARIABLE B0 : BIT;
        VARIABLE B1 : BIT;
        VARIABLE temp : STD_LOGIC_VECTOR(0 TO 4);
        VARIABLE X : STD_LOGIC_VECTOR(0 TO 4);
        VARIABLE Y : STD_LOGIC_VECTOR(0 TO 4);
        VARIABLE Z : STD_LOGIC_VECTOR(0 TO 4);
    BEGIN
        temp := std_logic_vector(unsigned(a1(0) & a1) + unsigned(a2(0) & a2));
        res := A + B * C;
        res := A + B * C;
        res := (A + B) * C;
        L := NOT BOOL AND A = 4;
        L := NOT BOOL AND A = 4;
        L := NOT (BOOL AND A = 4);
        L := (M XOR N) AND (O XOR P);
        L := M XOR (N AND (O XOR P));
        L := M XOR (N AND O) XOR P;
        L := (M NAND N) NAND (O NAND P);
        L := (M NAND (N NAND O)) NAND P;
        L := M NAND ((N NAND O) NAND P);
        L := M AND (N OR O);
        L := (M AND N) OR O;
        V0 := NOT B0 & NOT B1;
        V0 := NOT B0 & NOT B1;
        V0 := NOT (B0 & NOT B1);
        res := -A;
        res := -(-A);
        res := +A;
        res := +(+A);
        res := -A + B * C;
        res := A + (-B) * C;
        res := A + (-B) * C;
        res := -(A + B * C);
        res := A * 4;
        res := A / 4;
        res := A MOD 4;
        res := A REM 4;
        res := ABS(A);
        res := 2 ** A;
        temp := std_logic_vector(NOT unsigned(X) & unsigned(Y) XOR unsigned(Z) ROL 1);
        temp := std_logic_vector(NOT unsigned(X) & unsigned(Y) XOR unsigned(Z) ROL 1);
    END PROCEDURE;
    FUNCTION FUNC (SIGNAL A : INTEGER;
        SIGNAL B : INTEGER;
        SIGNAL C : INTEGER) RETURN BIT
    IS
    BEGIN
    END FUNCTION;
    SIGNAL X : std_logic;
    SIGNAL X0 : std_logic_vector(0 TO 7);
    SIGNAL X1 : std_logic_vector(0 TO 7);
BEGIN
    X <= A AND NOT (B OR C) AND (D(1) XOR D(2));
    Tri_out <= A WHEN (B = '0') ELSE 'Z';
    o1 <= "00" WHEN (D = "1000") ELSE
        "01" WHEN (D = "0100") ELSE
        "10" WHEN (D = "0010") ELSE
        "11" WHEN (D = "0001");
    X0(0 TO 3) <= X1(4 TO 7);
    X0(4 TO 7) <= X1(0 TO 3);
    PROCESS
        VARIABLE res : bit;
    BEGIN
        res := FUNC(1, 2, 3);
        res := FUNC(B => 2, A => 1, C => 7 MOD 4);
        res := FUNC(1, 2, C => -3 + 6);
        res := -(3 + 6);
        WAIT;
    END PROCESS;
    PROCESS
    BEGIN
        REPORT "-5 mod (-3) : " & integer'image(-5 MOD (-3));
        REPORT "-(5 mod (-3)) : " & integer'image(-5 MOD (-3));
        REPORT "(-5) mod (-3) : " & integer'image((-5) MOD (-3));
        REPORT "-16 ** 2 : " & integer'image(-16 ** 2);
        REPORT "-(16 ** 2) : " & integer'image(-16 ** 2);
        REPORT "(-16) ** 2 : " & integer'image((-16) ** 2);
        WAIT;
    END PROCESS;
END ARCHITECTURE;
