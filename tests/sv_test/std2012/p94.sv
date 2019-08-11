package p1;
    typedef struct {int A;} t_1;
endpackage

typedef struct {int A;} t_2;

module sub();
    import p1::t_1;
    parameter type t_3 = int;
    parameter type t_4 = int;
    typedef struct {int A;} t_5;
    t_1 v1; 
    t_2 v2; 
    t_3 v3; 
    t_4 v4; 
    t_5 v5;
endmodule

module top();
    typedef struct {int A;} t_6;
    sub #(.t_3(t_6)) s1 ();
    sub #(.t_3(t_6)) s2 ();
    initial begin
        s1.v1 = s2.v1; // legal - both types from package p1 (rule 8)
        s1.v2 = s2.v2; // legal - both types from $unit (rule 4) 
        s1.v3 = s2.v3; // legal - both types from top (rule 2)
        s1.v4 = s2.v4; // legal - both types are int (rule 1)
        s1.v5 = s2.v5; // illegal - types from s1 and 2 (rule 4)
    end
endmodule
