-- https://www.allaboutcircuits.com/technical-articles/how-to-use-vhdl-components-to-create-a-neat-hierarchical-design/

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Four_Bit_Adder is
    Port ( a : in  STD_LOGIC_VECTOR (3 downto 0);
           b : in  STD_LOGIC_VECTOR (3 downto 0);
           cin : in  STD_LOGIC;
           s : out  STD_LOGIC_VECTOR (3 downto 0);
           cout : out  STD_LOGIC);
end Four_Bit_Adder;

architecture Behavioral of Four_Bit_Adder is
	
	component FA is
		port (a, b, c_in: in std_logic;
		          s, c_out: out std_logic);
	end component;
	signal c: std_logic_vector(4 downto 0);
begin

	u1: FA port map (a => a(0), b => b(0), c_in => c(0), s => s(0), c_out => c(1));
	u2: FA port map (a => a(1), b => b(1), c_in => c(1), s => s(1), c_out => c(2));
	u3: FA port map (a => a(2), b => b(2), c_in => c(2), s => s(2), c_out => c(3));
	u4: FA port map (a => a(3), b => b(3), c_in => c(3), s => s(3), c_out => c(4));
	c(0) <= cin;
	cout <= c(4);

end Behavioral;