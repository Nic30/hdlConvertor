-- https://www.doulos.com/knowhow/vhdl_designers_guide/components_and_port_maps/
library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity MUX2I is
  port (SEL, A, B: in STD_LOGIC;
  F : out STD_LOGIC);
end;

architecture STRUCTURE of MUX2I is

component INV
  port (A: in STD_LOGIC;
  F: out STD_LOGIC);
end component;

component AOI
  port (A, B, C, D: in STD_LOGIC;
  F : out STD_LOGIC);
end component;

signal SELB: STD_LOGIC;

begin
  G1: INV port map (SEL, SELB);
  G2: AOI port map (SEL, A, SELB, B, F);
end; 