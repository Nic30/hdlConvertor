class B1;
rand int x;
constraint a { soft x > 10 ; soft x < 100 ; }
endclass
/* a1 */
/* a2 */
class D1 extends B1;
constraint b { soft x inside {[5:9]} ; }
endclass
/* b1 */
class B2;
rand int y;
constraint c { soft y > 10 ; }
endclass


class D2 extends B2;
constraint d { soft y inside {[5:9]} ; }
constraint e ;
/* d1 */
rand D1 p1;
rand B1 p2;
rand D1 p3;
constraint f { soft p1.x < p2.x ; }
endclass
/* f1 */
constraint D2::e { soft y > 100 ; }
