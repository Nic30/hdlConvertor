module secret (a, b);
input a;
output b;
`pragma protect encoding=(enctype="raw")
`pragma protect data_method="x-caesar", data_keyname="rot13", begin
`pragma protect
runtime_license=(library="lic.so",feature="runSecret",entry="chk", match=42)
logic b;
initial
begin
b = 0;
end
always
begin
#5 b = a;
end
`pragma protect end
endmodule // secret
