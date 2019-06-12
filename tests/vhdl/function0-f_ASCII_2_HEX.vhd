library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity example_function_advanced is
end example_function_advanced;

architecture behave of example_function_advanced is

  signal r_TEST_ASCII : std_logic_vector(7 downto 0) := X"42";
  signal r_TEST_HEX   : std_logic_vector(3 downto 0) := (others => '0');

  -- Purpose: This function converts ascii characters to hexadecimal.
  -- Numbers are 0x30-0x39 so only interpret least sig nibble.
  function f_ASCII_2_HEX (
    r_ASCII_IN : in std_logic_vector(7 downto 0))
    return std_logic_vector is
    variable v_TEMP : std_logic_vector(3 downto 0);
  begin
    if (r_ASCII_IN = X"41" or r_ASCII_IN = X"61") then
      v_TEMP := X"A";
    elsif (r_ASCII_IN = X"42" or r_ASCII_IN = X"62") then
      v_TEMP := X"B";
    elsif (r_ASCII_IN = X"43" or r_ASCII_IN = X"63") then
      v_TEMP := X"C";
    elsif (r_ASCII_IN = X"44" or r_ASCII_IN = X"64") then
      v_TEMP := X"D";
    elsif (r_ASCII_IN = X"45" or r_ASCII_IN = X"65") then
      v_TEMP := X"E";
    elsif (r_ASCII_IN = X"46" or r_ASCII_IN = X"66") then
      v_TEMP := X"F";
    else
      v_TEMP := r_ASCII_IN(3 downto 0);
    end if;
    return std_logic_vector(v_TEMP);
  end;

  -- Purpose: This function performs a bitwise xor on the input vector
  function f_BITWISE_XOR (
    r_SLV_IN    : in std_logic_vector)
    return std_logic is
    variable v_XOR : std_logic := '0';
  begin
    for i in 0 to r_SLV_IN'length-1 loop
      v_XOR := v_XOR xor r_SLV_IN(i);
    end loop;
    return v_XOR;

  end function f_BITWISE_XOR;


begin

  process is
  begin
    r_TEST_HEX   <= f_ASCII_2_HEX(r_TEST_ASCII);  -- function

    if f_BITWISE_XOR(r_TEST_ASCII) = '1' then
      report "RX Character has Odd Parity" severity note;
    else
      report "RX Character has Even Parity" severity note;
    end if;

    wait for 10 ns;

    r_TEST_ASCII <= X"37";
    wait for 10 ns;
    r_TEST_HEX   <= f_ASCII_2_HEX(r_TEST_ASCII);  -- function

    if f_BITWISE_XOR(r_TEST_ASCII) = '1' then
      report "RX Character has Odd Parity" severity note;
    else
      report "RX Character has Even Parity" severity note;
    end if;

    wait;
  end process;

end behave;