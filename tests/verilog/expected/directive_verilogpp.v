//+FHDR------------------------------------------------------------------------
//Copyright (c) 2013 Latin Group American Integhrated Circuit, Inc. All rights reserved
//GLADIC Open Source RTL
//-----------------------------------------------------------------------------
//FILE NAME	 :
//DEPARTMENT	 : IC Design / Verification
//AUTHOR	 : Felipe Fernandes da Costa
//AUTHOR’S EMAIL :
//-----------------------------------------------------------------------------
//RELEASE HISTORY
//VERSION DATE AUTHOR DESCRIPTION
//1.0 YYYY-MM-DD name
//-----------------------------------------------------------------------------
//KEYWORDS : General file searching keywords, leave blank if none.
//-----------------------------------------------------------------------------
//PURPOSE  : ECSS_E_ST_50_12C_31_july_2008
//-----------------------------------------------------------------------------
//PARAMETERS
//PARAM NAME		RANGE	: DESCRIPTION : DEFAULT : UNITS
//e.g.DATA_WIDTH	[32,16]	: width of the data : 32:
//-----------------------------------------------------------------------------
//REUSE ISSUES
//Reset Strategy	:
//Clock Domains		:
//Critical Timing	:
//Test Features		:
//Asynchronous I/F	:
//Scan Methodology	:
//Instantiations	:
//Synthesizable (y/n)	:
//Other			:
//-FHDR------------------------------------------------------------------------
module fifo_rx #(
    parameter integer DWIDTH = 9,
    parameter integer AWIDTH = 6
) (
    input wire clock,
    input wire reset,
    input wire wr_en,
    input wire rd_en,
    input wire[(DWIDTH - 1):0] data_in,
    output reg f_full,
    output reg f_empty,
    output reg open_slot_fct,
    output reg overflow_credit_error,
    output wire[(DWIDTH - 1):0] data_out,
    output reg[(AWIDTH - 1):0] counter
);
    reg[(AWIDTH - 1):0] wr_ptr;
    reg[(AWIDTH - 1):0] rd_ptr;
    reg[(AWIDTH - 1):0] credit_counter;
    reg[1:0] state_data_write;
    reg[1:0] next_state_data_write;
    reg[1:0] state_data_read;
    reg[1:0] next_state_data_read;
    reg[1:0] state_open_slot;
    reg[1:0] next_state_open_slot;
    reg[10:0] counter_wait;
    ///****************************************/
    always @(*) begin
        next_state_open_slot = state_open_slot;
        case(state_open_slot)
            2'd0:
                if (((((((((rd_ptr == 6'd7) || (rd_ptr == 6'd15)) || (rd_ptr == 6'd23)) || (rd_ptr == 6'd31)) || (rd_ptr == 6'd39)) || (rd_ptr == 6'd47)) || (rd_ptr == 6'd55)) || (rd_ptr == 6'd63)))
                    next_state_open_slot = 2'd1;
                else
                    next_state_open_slot = 2'd0;
            2'd1:
                if ((counter_wait != 11'd300))
                    next_state_open_slot = 2'd1;
                else
                    next_state_open_slot = 2'd2;
            2'd2:
                if (((((((((rd_ptr == 6'd7) || (rd_ptr == 6'd15)) || (rd_ptr == 6'd23)) || (rd_ptr == 6'd31)) || (rd_ptr == 6'd39)) || (rd_ptr == 6'd47)) || (rd_ptr == 6'd55)) || (rd_ptr == 6'd63)))
                    next_state_open_slot = 2'd2;
                else
                    next_state_open_slot = 2'd0;
            default:
                next_state_open_slot = 2'd0;
        endcase
    end

    ///****************************************/
    always @(*) begin
        next_state_data_write = state_data_write;
        case(state_data_write)
            2'd0:
                if ((wr_en && !f_full))
                    next_state_data_write = 2'd1;
                else
                    next_state_data_write = 2'd0;
            2'd1:
                if (wr_en)
                    next_state_data_write = 2'd1;
                else
                    next_state_data_write = 2'd2;
            2'd2:
                next_state_data_write = 2'd0;
            default:
                next_state_data_write = 2'd0;
        endcase
    end

    ///****************************************/
    always @(*) begin
        next_state_data_read = state_data_read;
        case(state_data_read)
            2'd0:
                if ((rd_en && !f_empty))
                    next_state_data_read = 2'd1;
                else
                    next_state_data_read = 2'd0;
            2'd1:
                if (rd_en)
                    next_state_data_read = 2'd1;
                else
                    next_state_data_read = 2'd2;
            2'd2:
                next_state_data_read = 2'd0;
            default:
                next_state_data_read = 2'd0;
        endcase
    end

    always @(posedge clock, negedge reset)
        if (!reset) begin
            state_open_slot <= 2'd0;
            open_slot_fct <= 1'b0;
            counter_wait <= 11'd0;
        end else begin
            state_open_slot <= next_state_open_slot;
            case(state_open_slot)
                2'd0:
                    if (((((((((rd_ptr == 6'd7) || (rd_ptr == 6'd15)) || (rd_ptr == 6'd23)) || (rd_ptr == 6'd31)) || (rd_ptr == 6'd39)) || (rd_ptr == 6'd47)) || (rd_ptr == 6'd55)) || (rd_ptr == 6'd63))) begin
                        open_slot_fct <= 1'b1;
                        counter_wait <= (counter_wait + 11'd1);
                    end else
                        open_slot_fct <= 1'b0;
                2'd1: begin
                    if ((counter_wait != 11'd300))
                        counter_wait <= (counter_wait + 11'd1);
                    else
                        counter_wait <= counter_wait;
                    open_slot_fct <= 1'b1;
                end
                2'd2: begin
                    counter_wait <= 11'd0;
                    open_slot_fct <= 1'b0;
                end
                default:
                    open_slot_fct <= open_slot_fct;
            endcase
        end

    //Write pointer
    always @(posedge clock, negedge reset)
        if (!reset) begin
            state_data_write <= 2'd0;
            wr_ptr <= {(AWIDTH){1'b0}};
        end else begin
            state_data_write <= next_state_data_write;
            case(state_data_write)
                2'd0:
                    wr_ptr <= wr_ptr;
                2'd1:
                    wr_ptr <= wr_ptr;
                2'd2:
                    wr_ptr <= (wr_ptr + 6'd1);
                default:
                    wr_ptr <= wr_ptr;
            endcase
        end

    //FULL - EMPTY COUNTER
    always @(posedge clock, negedge reset)
        if (!reset) begin
            f_full <= 1'b0;
            f_empty <= 1'b0;
            overflow_credit_error <= 1'b0;
            counter <= {(AWIDTH){1'b0}};
        end else begin
            if ((state_data_write == 2'd2))
                counter <= (counter + 6'd1);
            else
                if (((counter > 6'd0) && (state_data_read == 2'd2)))
                    counter <= (counter - 6'd1);
                else
                    counter <= counter;
            if ((counter > 6'd56))
                overflow_credit_error <= 1'b1;
            else
                overflow_credit_error <= 1'b0;
            if ((counter == 6'd56))
                f_full <= 1'b1;
            else
                f_full <= 1'b0;
            if ((counter == 6'd0))
                f_empty <= 1'b1;
            else
                f_empty <= 1'b0;
        end

    //Read pointer
    always @(posedge clock, negedge reset)
        if (!reset) begin
            rd_ptr <= {(AWIDTH){1'b0}};
            state_data_read <= 2'd0;
        end else begin
            state_data_read <= next_state_data_read;
            case(state_data_read)
                2'd0:
                    if (rd_en)
                        rd_ptr <= (rd_ptr + 6'd1);
                    else
                        rd_ptr <= rd_ptr;
                2'd1:
                    rd_ptr <= rd_ptr;
                2'd2:
                    rd_ptr <= rd_ptr;
                default:
                    rd_ptr <= rd_ptr;
            endcase
        end

    mem_data mem_dta_fifo_rx (
        .clock(clock),
        .reset(reset),
        .data_in(data_in),
        .wr_ptr(wr_ptr),
        .rd_ptr(rd_ptr),
        .data_out(data_out)
    );

endmodule
