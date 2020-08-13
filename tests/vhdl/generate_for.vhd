architecture GEN of REG_BANK is
  component REG
    port(D,CLK,RESET : in  std_ulogic;
         Q           : out std_ulogic);
  end component;
begin
   GEN_REG: 
   for I in 0 to 3 generate
      REGX : REG port map
        (DIN(I), CLK, RESET, DOUT(I));
   end generate GEN_REG;
end GEN;
