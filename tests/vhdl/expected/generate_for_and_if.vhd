LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE IEEE.MATH_REAL.ALL;
LIBRARY BigRISC_LIB;
USE BigRISC_LIB.BigRISC_CONFIG.ALL;
USE BigRISC_LIB.BigRISC_HELPERS.ALL;
ENTITY Shifter IS
    GENERIC(
        SIZE : NATURAL := WORD_SIZE;
        SHIFT_SIZE : NATURAL := LOG2(WORD_SIZE);
        PIPELINED : NATURAL := 2
    );
    PORT(
        Clk_in : IN STD_LOGIC;
        Reset_in : IN STD_LOGIC;
        Enable_in : IN STD_LOGIC;
        Operand_in : IN STD_LOGIC_VECTOR(SIZE - 1 DOWNTO 0);
        Shift_in : IN STD_LOGIC_VECTOR(SHIFT_SIZE - 1 DOWNTO 0);
        ShiftType_in : IN STD_LOGIC_VECTOR(SHIFT_SELECT_SIZE - 1 DOWNTO 0);
        Result_out : OUT STD_LOGIC_VECTOR(SIZE - 1 DOWNTO 0)
    );
END ENTITY;

ARCHITECTURE arch OF Shifter IS
    CONSTANT STAGE_STAGES : INTEGER := integer(ceil(real(SHIFT_SIZE) / real(PIPELINED)));
    TYPE StageArray IS ARRAY (NATURAL RANGE <>) OF STD_LOGIC_VECTOR(SIZE - 1 DOWNTO 0);
    SIGNAL Stages : StageArray(SHIFT_SIZE DOWNTO 0);
    SIGNAL PipelinedStages : StageArray(SHIFT_SIZE DOWNTO 1);
    TYPE ShiftArray IS ARRAY (SHIFT_SIZE - 1 DOWNTO 0) OF STD_LOGIC_VECTOR(SHIFT_SIZE - 1 DOWNTO 0);
    TYPE TypeArray IS ARRAY (SHIFT_SIZE - 1 DOWNTO 0) OF STD_LOGIC_VECTOR(SHIFT_SELECT_SIZE - 1 DOWNTO 0);
    SIGNAL PipelinedShift : ShiftArray;
    SIGNAL PipelinedType : TypeArray;
BEGIN
    ASSERT SHIFT_SIZE = LOG2(SIZE) REPORT "Shift Amount must have LOG2 bits of operand." SEVERITY FAILURE;
    ASSERT PIPELINED <= SHIFT_SIZE REPORT "Cannot pipeline more than the number of stages." SEVERITY FAILURE;
    Pipelining: FOR i IN SHIFT_SIZE - 1 DOWNTO 1 GENERATE
         BEGIN
            PipelineRegs: IF (SHIFT_SIZE - i) MOD STAGE_STAGES = 0 GENERATE
                Reg: PROCESS(Clk_in, Reset_in)
                BEGIN
                    IF Reset_in = RESET_VALUE THEN
                        PipelinedStages(i) <= (OTHERS => '0');
                    ELSIF Clk_in'event AND Clk_in = CLOCK_VALUE AND Enable_in = ENABLE_VALUE THEN
                        PipelinedStages(i) <= Stages(i);
                    END IF;
                END PROCESS;
            END GENERATE;
            NoPipeline: IF (SHIFT_SIZE - i) MOD STAGE_STAGES /= 0 GENERATE
                PipelinedStages(i) <= Stages(i);
            END GENERATE;
        END GENERATE;
    Stages(SHIFT_SIZE) <= Operand_in;
    PipelinedStages(SHIFT_SIZE) <= Stages(SHIFT_SIZE);
    ShiftStages: FOR i IN SHIFT_SIZE - 1 DOWNTO 0 GENERATE
         BEGIN
            Stages(i) <= (PipelinedStages(i + 1)) WHEN (Shift_in(i) = '0') ELSE
                (REPEAT('0', 2 ** i) & PipelinedStages(i + 1)(SIZE - 1 DOWNTO 2 ** i)) WHEN (Shift_in(i) = '1' AND ShiftType_in = CT_SHIFT_SRL) ELSE
                (REPEAT(PipelinedStages(i + 1)(SIZE - 1), 2 ** i) & PipelinedStages(i + 1)(SIZE - 1 DOWNTO 2 ** i)) WHEN (Shift_in(i) = '1' AND ShiftType_in = CT_SHIFT_SRA) ELSE PipelinedStages(i + 1)(SIZE - 2 ** i - 1 DOWNTO 0) & REPEAT('0', 2 ** i);
        END GENERATE;
    Result_out <= Stages(0);
END ARCHITECTURE;
