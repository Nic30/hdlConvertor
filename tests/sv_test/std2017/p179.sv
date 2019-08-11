class baseA ;
integer j = 5;
endclass
class B ;
integer i = 1;
baseA a = new;
endclass
class xtndA extends baseA;
rand int x;
constraint cst1 { x < 10; }
endclass
function integer test;
xtndA xtnd1;
baseA base2, base3;
B b1 = new;
B b2 = new b1;
b2.i = 10;
b2.a.j = 50;
test = b1.i;
test = b1.a.j;
xtnd1 = new;
xtnd1.x = 3;
base2 = xtnd1;
base3 = new base2;
endfunction
