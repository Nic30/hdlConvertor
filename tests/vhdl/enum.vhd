architecture EXAMPLE of ENUMERATION is
  -- http://vhdl.renerta.com/mobile/source/vhd00026.htm
  type e1 is (L, H);
  type e2 is ('0', '1');
  type e3 is ('0', '1', L, H);
  type e4 is (Init, Read, Decode, Execute, Write);
 
  signal s : e1;
begin
  s <= L;
end;
