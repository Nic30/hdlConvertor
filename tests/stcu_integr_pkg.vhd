











library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

package stcu_integr_pkg is
 

 function Resolve_width (Number_lbist : integer) return integer;
 function Resolve_width_type (Number_lbist : integer) return integer;
 function Resolve_width_mtr_status (Number : integer ; difference :integer) return integer;
 function Return_max_of_seven_nmcut (Number : natural) return natural;

 function Evaluate_log2 (Number: integer) return integer;

 CONSTANT MAX_NLBIST 		      : natural := 128;
 CONSTANT MAX_NMCUT 		      : natural := 512;
 CONSTANT MAX_NRAM		      : natural := 512;
 CONSTANT MAX_NROM		      : natural := 512;
 CONSTANT PRPG_MAX_SIZE		      : natural := 64;
 CONSTANT MISR_MAX_SIZE       	      : natural := 64;
 CONSTANT MAX_NCUTSEL		      : natural := MAX_NMCUT+((2*Evaluate_log2(MAX_NMCUT/2))-1);


 CONSTANT NLBIST		      : natural range 0 to MAX_NLBIST := 128;
 CONSTANT NMCUT 		      : natural range 0 to MAX_NMCUT  := 256;
 CONSTANT NRAM			      : natural range 0 to MAX_NRAM   := 256;


 CONSTANT OFFLINE_SELFTEST_RUN        : std_logic := '0';  
 CONSTANT BOTH_KEYS_PRG       : std_logic := '1';  
 CONSTANT LBIST_SINGLE_STEP   : std_logic := '0';  
 CONSTANT RETAIN_ONLINE_STATUS: std_logic := '0';  
 CONSTANT CUMULATIVE_PASS_FAIL_STATUS: std_logic := '0';  

 CONSTANT MBIST_TDR_REG 	      : std_logic_vector(6 downto 0) := "0000000";
 CONSTANT MTR_MBIST_ARCHITECTURE      : std_logic := '1';

 CONSTANT MTR_MBIST_STATUS_REGS       : natural := 32;
 CONSTANT MTR_MBIST_SEL_REGS          : natural := 8 ;

 
 CONSTANT MTR_TDR_REG_SIZE            : natural := 6;
 CONSTANT MTR_TDR_REG_WIDTH           : natural := 102;
 CONSTANT MCT_LATENCY_IN_IPS_TRANSACTION : integer := 1;

 CONSTANT NLBIST_REGS		      : natural := 15;

 
CONSTANT NREGS			      : natural := 103+(NLBIST*NLBIST_REGS)+5+NMCUT+6+6;
CONSTANT LBIST_FIXED                  : natural := 24; 
 
 
 
 
 CONSTANT CWS_WIDTH                   : integer := 6;
 

 TYPE lb_res_reg 		 is array (Resolve_width_type(NLBIST) downto 0) of std_logic_vector(31 downto 0);
 TYPE mb_res_reg 		 is array (Resolve_width_type(NMCUT)  downto 0) of std_logic_vector(31 downto 0);
 TYPE mb_sel_reg                 is array (MTR_MBIST_SEL_REGS  downto 1) of std_logic_vector(31 downto 0);
 TYPE ips_rdata_reg              is array (Resolve_width_type(NREGS) downto 0) of std_logic_vector(31 downto 0);
 TYPE ips_rdata_lbctrl_reg       is array (Resolve_width_type(NLBIST) downto 0) of std_logic_vector(31 downto 0);
 TYPE ips_rdata_lbstatus_reg	 is array (Resolve_width_type(LBIST_FIXED) downto 0) of std_logic_vector(31 downto 0);
 TYPE ips_rdata_others_reg	 is array (Resolve_width_type(NREGS) downto 0) of std_logic_vector(31 downto 0);
 TYPE stcu_lb_ctrl_ptr_type      is array (Resolve_width_type(NLBIST) downto 0) of std_logic_vector(9  downto 0);
 TYPE stcu_lb_ctrl_shs_type      is array (Resolve_width_type(NLBIST) downto 0) of std_logic_vector(2  downto 0);
 TYPE stcu_lb_ctrl_scen_off_type is array (Resolve_width_type(NLBIST) downto 0) of std_logic_vector(3  downto 0); 
 TYPE stcu_lb_ctrl_scen_on_type  is array (Resolve_width_type(NLBIST) downto 0) of std_logic_vector(3  downto 0); 

 TYPE stcu_lb_pcs_type           is array (Resolve_width_type(NLBIST) downto 0) of std_logic_vector(25 downto 0); 
 TYPE stcu_lb_misr_type          is array (Resolve_width_type(NLBIST) downto 0) of std_logic_vector(63 downto 0);
 TYPE stcu_lb_prpg_type          is array (Resolve_width_type(NLBIST) downto 0) of std_logic_vector(63 downto 0);
 TYPE stcu_mb_ctrl_ptr_type      is array (Resolve_width_type(NMCUT)  downto 0) of std_logic_vector(9  downto 0);
 TYPE stcu_mb_ctrl_time_type     is array (Resolve_width_type(NMCUT)  downto 0) of std_logic_vector(5 downto 0);
 TYPE stcu_lb_pc_start_type      is array (Resolve_width_type(NLBIST) downto 0) of std_logic_vector(31 downto 0); 
 TYPE misr_size 		 is array (Resolve_width_type(NLBIST) downto 0) of natural;
 TYPE prpg_size			 is array (Resolve_width_type(NLBIST) downto 0) of natural;




 CONSTANT STCU_CFG_RES	      	      : std_logic_vector(31 downto 0):= "00000000000000000000000000000000";
 CONSTANT STCU_PLL_CFG_RES	      : std_logic_vector(31 downto 0):= X"00000000";
 CONSTANT STCU_WDG_RES	              : std_logic_vector(31 downto 0):= X"0000FFFF";
 CONSTANT STCU_CRCE_RES	      	      : std_logic_vector(31 downto 0):= X"00000000";
 CONSTANT STCU_CRCR_RES	      	      : std_logic_vector(31 downto 0):= X"FFFFFFFF";
 CONSTANT STCU_ERR_FM_RES      	      : std_logic_vector(31 downto 0):= X"00000000";


 CONSTANT STCU_LBRMSW_RES	      : std_logic_vector(127 downto 0):= X"00000000000000000000000000000000";
 CONSTANT STCU_LBCFM_RES	      : std_logic_vector(127 downto 0):= X"00000000000000000000000000000000";

 
 CONSTANT STCU_MBCFM_RES	      : std_logic_vector(511 downto 0):= X"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
CONSTANT STCU_MB_MTR_ALGO_RES	      : std_logic_vector(31 downto 0):= X"00000000";
CONSTANT STCU_MB_MTR_BSTGGR_RES	      : std_logic_vector(31 downto 0):= X"00000000";
CONSTANT STCU_MB_MTR_BSTART_RES	      : std_logic_vector(31 downto 0):= X"00000000";

 

 CONSTANT LBIST_WAIT_UPD_TIME 	      : natural := 24;


 CONSTANT AUTOLOCK_BITS		      : natural := 32;
 CONSTANT AUTOLOCK_VALUE              : std_logic_vector(Resolve_width(AUTOLOCK_BITS) downto 0) := (others => '1');


 CONSTANT PLL_PD_BITS		      : natural := 10;
 CONSTANT PLL_PD_VALUES               : std_logic_vector(Resolve_width(PLL_PD_BITS) downto 0) := "1000000000";

CONSTANT MCT_BIST_REP_BASE_ADDRESS :  std_logic_vector(31 downto 0) := X"F100_0070" ;
CONSTANT MCT_MTR_BASE_ADDRESS      :  std_logic_vector(31 downto 0) := X"F100_0000" ;


 CONSTANT MCT_ALGO_SEL    : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_0008";
 CONSTANT MCT_BSTART      : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_005C";
 CONSTANT MCT_BSTAGGER    : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_0060";

 CONSTANT MCT_BIST_ALL    : std_logic_vector(31 downto 0) := X"F100_0064";

CONSTANT MCT_BIST_SEL1   : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_0070" ;
CONSTANT MCT_BIST_SEL2   : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_0074" ;
CONSTANT MCT_BIST_SEL3   : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_0078" ;
CONSTANT MCT_BIST_SEL4   : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_007C" ;
CONSTANT MCT_BIST_SEL5   : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_0080" ;
CONSTANT MCT_BIST_SEL6   : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_0084" ;
CONSTANT MCT_BIST_SEL7   : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_0088" ;
CONSTANT MCT_BIST_SEL8   : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_008C" ;

CONSTANT MCT_BIST_SEL9   : std_logic_vector(31 downto 0) := MCT_BIST_REP_BASE_ADDRESS + X"0000_0220" ;
CONSTANT MCT_BIST_SEL10  : std_logic_vector(31 downto 0) := MCT_BIST_REP_BASE_ADDRESS + X"0000_0224" ;
CONSTANT MCT_BIST_SEL11  : std_logic_vector(31 downto 0) := MCT_BIST_REP_BASE_ADDRESS + X"0000_0228" ;
CONSTANT MCT_BIST_SEL12  : std_logic_vector(31 downto 0) := MCT_BIST_REP_BASE_ADDRESS + X"0000_022C" ;
CONSTANT MCT_BIST_SEL13  : std_logic_vector(31 downto 0) := MCT_BIST_REP_BASE_ADDRESS + X"0000_0230" ;
CONSTANT MCT_BIST_SEL14  : std_logic_vector(31 downto 0) := MCT_BIST_REP_BASE_ADDRESS + X"0000_0234" ;
CONSTANT MCT_BIST_SEL15  : std_logic_vector(31 downto 0) := MCT_BIST_REP_BASE_ADDRESS + X"0000_0238" ;
CONSTANT MCT_BIST_SEL16  : std_logic_vector(31 downto 0) := MCT_BIST_REP_BASE_ADDRESS + X"0000_023C" ;


 CONSTANT MCT_BIST_STATUS0 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS  + X"0000_0090" ;
 CONSTANT MCT_BIST_STATUS1 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS  + X"0000_0094" ;
 CONSTANT MCT_BIST_STATUS2 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS  + X"0000_0098" ;
 CONSTANT MCT_BIST_STATUS3 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS  + X"0000_009C";
 CONSTANT MCT_BIST_STATUS4 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS  + X"0000_00A0" ;
 CONSTANT MCT_BIST_STATUS5 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS  + X"0000_00A4" ;
 CONSTANT MCT_BIST_STATUS6 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS  + X"0000_00A8" ;
 CONSTANT MCT_BIST_STATUS7 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS  + X"0000_00AC" ;
 CONSTANT MCT_BIST_STATUS8 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS  + X"0000_00B0" ;
 CONSTANT MCT_BIST_STATUS9 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS  + X"0000_00B4" ;
 CONSTANT MCT_BIST_STATUS10 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00B8" ;
 CONSTANT MCT_BIST_STATUS11 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00BC" ;
 CONSTANT MCT_BIST_STATUS12 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00C0" ;
 CONSTANT MCT_BIST_STATUS13 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00C4" ;
 CONSTANT MCT_BIST_STATUS14 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00C8" ;
 CONSTANT MCT_BIST_STATUS15 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00CC" ;
 CONSTANT MCT_BIST_STATUS16 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00D0" ; 
 CONSTANT MCT_BIST_STATUS17 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00D4" ; 
 CONSTANT MCT_BIST_STATUS18 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00D8" ; 
 CONSTANT MCT_BIST_STATUS19 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00DC" ; 
 CONSTANT MCT_BIST_STATUS20 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00E0" ; 
 CONSTANT MCT_BIST_STATUS21 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00E4" ; 
 CONSTANT MCT_BIST_STATUS22 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00E8" ; 
 CONSTANT MCT_BIST_STATUS23 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00EC" ; 
 CONSTANT MCT_BIST_STATUS24 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00F0" ; 
 CONSTANT MCT_BIST_STATUS25 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00F4" ; 
 CONSTANT MCT_BIST_STATUS26 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00F8" ; 
 CONSTANT MCT_BIST_STATUS27 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_00FC" ; 
 CONSTANT MCT_BIST_STATUS28 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_0100" ; 
 CONSTANT MCT_BIST_STATUS29 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_0104" ; 
 CONSTANT MCT_BIST_STATUS30 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_0108" ; 
 CONSTANT MCT_BIST_STATUS31 : std_logic_vector(31 downto 0) := MCT_MTR_BASE_ADDRESS + X"0000_010C" ; 

 
 CONSTANT MCT_BIST_STATUS32 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_0380" ; 
 CONSTANT MCT_BIST_STATUS33 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_0384" ; 
 CONSTANT MCT_BIST_STATUS34 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_0388" ; 
 CONSTANT MCT_BIST_STATUS35 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_038C" ; 
 CONSTANT MCT_BIST_STATUS36 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_0390" ; 
 CONSTANT MCT_BIST_STATUS37 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_0394" ; 
 CONSTANT MCT_BIST_STATUS38 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_0398" ; 
 CONSTANT MCT_BIST_STATUS39 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_039C" ; 
 CONSTANT MCT_BIST_STATUS40 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03A0" ; 
 CONSTANT MCT_BIST_STATUS41 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03A4" ; 
 CONSTANT MCT_BIST_STATUS42 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03A8" ; 
 CONSTANT MCT_BIST_STATUS43 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03AC" ; 
 CONSTANT MCT_BIST_STATUS44 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03B0" ; 
 CONSTANT MCT_BIST_STATUS45 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03B4" ; 
 CONSTANT MCT_BIST_STATUS46 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03B8" ; 
 CONSTANT MCT_BIST_STATUS47 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03BC" ; 
 CONSTANT MCT_BIST_STATUS48 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03C0" ; 
 CONSTANT MCT_BIST_STATUS49 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03C4" ; 
 CONSTANT MCT_BIST_STATUS50 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03C8" ; 
 CONSTANT MCT_BIST_STATUS51 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03CC" ; 
 CONSTANT MCT_BIST_STATUS52 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03D0" ; 
 CONSTANT MCT_BIST_STATUS53 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03D4" ; 
 CONSTANT MCT_BIST_STATUS54 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03D8" ; 
 CONSTANT MCT_BIST_STATUS55 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03DC" ; 
 CONSTANT MCT_BIST_STATUS56 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03E0" ; 
 CONSTANT MCT_BIST_STATUS57 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03E4" ; 
 CONSTANT MCT_BIST_STATUS58 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03E8" ; 
 CONSTANT MCT_BIST_STATUS59 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03EC" ; 
 CONSTANT MCT_BIST_STATUS60 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03F0" ; 
 CONSTANT MCT_BIST_STATUS61 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03F4" ; 
 CONSTANT MCT_BIST_STATUS62 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03F8" ; 
 CONSTANT MCT_BIST_STATUS63 : std_logic_vector(31 downto 0) :=MCT_BIST_REP_BASE_ADDRESS + X"0000_03FC" ; 


end stcu_integr_pkg ;

