library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.MATH_REAL.ALL;

library BigRISC_LIB;
use BigRISC_LIB.BigRISC_CONFIG.ALL;
use BigRISC_LIB.BigRISC_HELPERS.ALL;

entity Shifter is
    Generic
    (
        SIZE                        : NATURAL               :=          WORD_SIZE;
        SHIFT_SIZE                  : NATURAL               :=          LOG2(WORD_SIZE);
        PIPELINED                   : NATURAL               :=          2
    );
    Port
    (
        -- ************************************  G L O B A L S ************************************ --
        Clk_in                              : in                STD_LOGIC;
        Reset_in                            : in                STD_LOGIC;
        Enable_in                           : in                STD_LOGIC;

        -- *************************************  I N P U T S ************************************* --
        Operand_in                          : in                STD_LOGIC_VECTOR(SIZE-1 downto 0);
        Shift_in                            : in                STD_LOGIC_VECTOR(SHIFT_SIZE-1 downto 0);
        ShiftType_in                        : in                STD_LOGIC_VECTOR(SHIFT_SELECT_SIZE-1 downto 0);

        -- ************************************  O U T P U T S ************************************ --
        -- Actual Outputs
        Result_out                          : out               STD_LOGIC_VECTOR(SIZE-1 downto 0)
    );
end entity; -- Shifter

architecture arch of Shifter is
    
    constant STAGE_STAGES           : INTEGER           := integer(ceil(real(SHIFT_SIZE)/real(PIPELINED)));

    type StageArray is array (NATURAL range <>) of STD_LOGIC_VECTOR(SIZE-1 downto 0);
    signal Stages                           : StageArray(SHIFT_SIZE downto 0);
    signal PipelinedStages                  : StageArray(SHIFT_SIZE downto 1);

    type ShiftArray is array (SHIFT_SIZE-1 downto 0) of STD_LOGIC_VECTOR(SHIFT_SIZE-1 downto 0);
    type TypeArray is array (SHIFT_SIZE-1 downto 0) of STD_LOGIC_VECTOR(SHIFT_SELECT_SIZE-1 downto 0);
    signal PipelinedShift                   : ShiftArray;
    signal PipelinedType                    : TypeArray;

begin
    
    -- *************************************  C H E C K S ************************************* --
	assert (SHIFT_SIZE = LOG2(SIZE)) report "Shift Amount must have LOG2 bits of operand." severity FAILURE;
	assert (PIPELINED <= SHIFT_SIZE) report "Cannot pipeline more than the number of stages." severity FAILURE;

    -- *********************************  P I P E L I N I N G ********************************* --
    Pipelining: for i in SHIFT_SIZE-1 downto 1 generate
        PipelineRegs: if (SHIFT_SIZE-i) mod STAGE_STAGES = 0 generate
            Reg: process(Clk_in, Reset_in)
            begin
                if (Reset_in=RESET_VALUE) then
                    PipelinedStages(i) <= (others => '0');
                elsif (Clk_in'event and Clk_in=CLOCK_VALUE and Enable_in=ENABLE_VALUE) then
                    PipelinedStages(i) <= Stages(i);
                end if;
            end process;
        end generate PipelineRegs;
        NoPipeline: if ((SHIFT_SIZE-i) mod STAGE_STAGES) /= 0 generate
            PipelinedStages(i) <= Stages(i);
        end generate NoPipeline;
    end generate Pipelining;
    
    -- **************************************  L O G I C ************************************** --

    Stages(SHIFT_SIZE) <= Operand_in;
    PipelinedStages(SHIFT_SIZE) <= Stages(SHIFT_SIZE);

    ShiftStages: for i in SHIFT_SIZE-1 downto 0 generate
    begin

        Stages(i) <= PipelinedStages(i+1) when Shift_in(i) = '0' else
                     REPEAT('0',2**i) & PipelinedStages(i+1)(SIZE-1 downto 2**i) when Shift_in(i) = '1' and ShiftType_in = CT_SHIFT_SRL else
                     REPEAT(PipelinedStages(i+1)(SIZE-1),2**i) & PipelinedStages(i+1)(SIZE-1 downto 2**i) when Shift_in(i) = '1' and ShiftType_in = CT_SHIFT_SRA else
                     PipelinedStages(i+1)(SIZE-(2**i)-1 downto 0) & REPEAT('0',2**i); -- when Shift_in(i) = '1' and ShiftType_in = CT_SHIFT_SLL

    end generate ShiftStages;

    Result_out <= Stages(0);

end architecture; -- arch