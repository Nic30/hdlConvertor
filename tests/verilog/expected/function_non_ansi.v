module module0;
    function clkout_duty_chk (
        input integer CLKOUT_DIVIDE,
        input real CLKOUT_DUTY_CYCLE,
        input [160:0] CLKOUT_DUTY_CYCLE_N
    );
        integer step_tmp;
        real CLK_DUTY_CYCLE_MIN;
        real CLK_DUTY_CYCLE_MAX;
        real CLK_DUTY_CYCLE_STEP;
        real CLK_DUTY_CYCLE_MIN_rnd;
        reg clk_duty_tmp_int;
        begin
            clkout_duty_chk = 1'b1;
        end
    endfunction

endmodule
