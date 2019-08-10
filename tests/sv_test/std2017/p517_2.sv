class C;
rand bit [7:0] A[] ;
constraint c1 { A.size == 5; }
constraint c2 { A.sum() with (int'(item)) < 1000; }
endclass


class A;
// leaf node
rand bit [7:0] v;
endclass

class B extends A; // heap node
rand A left;
rand A right;
constraint heapcond {left.v <= v; right.v > v;}
endclass

