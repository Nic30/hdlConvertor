LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

-- http://cseweb.ucsd.edu/~hepeng/cse143-w08/labs/VHDLReference/05.pdf
ENTITY proc IS
   PORT
   (
      A, B, C : IN STD_LOGIC;
      D     : IN STD_LOGIC_VECTOR( 3 DOWNTO 0 );
      o1    : OUT STD_LOGIC_VECTOR(1 downto 0);
      Tri_out : INOUT STD_LOGIC
   );
END proc;
ARCHITECTURE maxpld OF proc IS
     
     PROCEDURE op_example (SIGNAL A, B, C : IN INTEGER;
                 SIGNAL bool: IN BOOLEAN;
                 SIGNAL a1, a2 : IN STD_LOGIC_VECTOR(0 TO 3)
     ) IS
          VARIABLE res: integer;
          VARIABLE L, M, N, O, P: BOOLEAN;
          VARIABLE V0 : BIT_VECTOR(3 downto 0);
          VARIABLE B0, B1: BIT;
          VARIABLE temp, X, Y, Z: STD_LOGIC_VECTOR(0 TO 4);
     BEGIN
          temp := std_logic_vector(unsigned(a1(0)&a1) + unsigned(a2(0)&a2));
          res:= A + B * C;
          res:= A + (B * C);
          res:= (A + B) * C;
          L:= not BOOL and (A = 4);
          L:= (not BOOL) and (A = 4);
          L:= not (BOOL and (A = 4));
          L := (M xor N) and (O xor P);
          L := M xor (N and (O xor P));
          L := M xor (N and O) xor P;
          L := (M nand N) nand (O nand P);  -- Parenthesis required;
          L := (M nand (N nand O)) nand P;
          L := M nand ((N nand O) nand P);
          L := M and (N or O);  -- Parenthesis required;
          L := (M and N) or O;
          V0 := not B0 & not B1;
          V0 := (not B0) & (not B1);
          V0 := not (B0 & (not B1));
          res:= -A;
          res:= -(-A);
          res:= +A;
          res:= +(+A);
          res:= -A + B * C;
          res:= A + (-B) * C;
          res:= A + ((-B) * C);
          res:= -(A + B * C);
          res:= A * 4;
          res:= A / 4;
          res:= A mod 4;
          res:= A rem 4;
          res:= abs(A);
          res:= 2 ** A;
          temp := std_logic_vector(not unsigned(X) & unsigned(Y) xor unsigned(Z) rol 1);
          temp := std_logic_vector(((not unsigned(X)) & unsigned(Y)) xor (unsigned(Z) rol 1));
     END PROCEDURE;
     function FUNC(A, B, C: INTEGER) return BIT IS
     BEGIN
     END FUNCTION;
     
     signal X: std_logic;
     signal X0, X1: std_logic_vector(0 to 7);
BEGIN
   X <= (A AND NOT(B OR C)) AND (D(1) XOR D(2));
   Tri_out <= A WHEN B = '0' ELSE 'Z';
   o1 <= "00" when D = "1000" else 
      "01" when D = "0100" else 
      "10" when D = "0010" else 
      "11" when D = "0001";
   
   X0(0 to 3) <= X1(4 to 7);
   X0(4 to 7) <= X1(0 to 3);
   
   PROCESS -- If WAIT is used no sensitivity list is used
      variable res: bit;
   BEGIN
     --WAIT UNTIL ( C'EVENT AND C = '1' );
     res:= FUNC(1, 2, 3);
     res:= FUNC(B => 2, A => 1, C => 7 mod 4);
     res:= FUNC(1, 2, C => -3+6);
     res:= -(3+6);
     WAIT;
   END PROCESS; 

   -- https://insights.sigasi.com/tech/be-careful-vhdl-operator-precedence/
   process is
   begin
      -- -5 mod -3, is not valid VHDL. This again is because unary minus has lower priority than the modulo operator.
      report "-5 mod (-3) : " & integer'image(-5 mod (-3));
      report "-(5 mod (-3)) : " & integer'image(-(5 mod (-3))); -- same as previous
      report "(-5) mod (-3) : " & integer'image((-5) mod (-3));
      report "-16 ** 2 : " & integer'image(-16 ** 2);
      report "-(16 ** 2) : " & integer'image(-(16 ** 2));  -- same as previous
      report "(-16) ** 2 : " & integer'image((-16) ** 2);
      wait;
   end process ;

END maxpld;
