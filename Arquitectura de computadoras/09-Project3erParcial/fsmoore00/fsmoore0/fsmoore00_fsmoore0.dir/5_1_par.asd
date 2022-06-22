[ActiveSupport PAR]
; Global primary clocks
GLOBAL_PRIMARY_USED = 2;
; Global primary clock #0
GLOBAL_PRIMARY_0_SIGNALNAME = FS00/sclk;
GLOBAL_PRIMARY_0_DRIVERTYPE = OSC;
GLOBAL_PRIMARY_0_LOADNUM = 13;
; Global primary clock #1
GLOBAL_PRIMARY_1_SIGNALNAME = clk0_c;
GLOBAL_PRIMARY_1_DRIVERTYPE = SLICE;
GLOBAL_PRIMARY_1_LOADNUM = 12;
; # of global secondary clocks
GLOBAL_SECONDARY_USED = 2;
; Global secondary clock #0
GLOBAL_SECONDARY_0_SIGNALNAME = en0_c;
GLOBAL_SECONDARY_0_DRIVERTYPE = PIO;
GLOBAL_SECONDARY_0_LOADNUM = 11;
GLOBAL_SECONDARY_0_SIGTYPE = CLK+RST;
; Global secondary clock #1
GLOBAL_SECONDARY_1_SIGNALNAME = FS00/D01/un1_sdiv61_RNIOULJ;
GLOBAL_SECONDARY_1_DRIVERTYPE = SLICE;
GLOBAL_SECONDARY_1_LOADNUM = 12;
GLOBAL_SECONDARY_1_SIGTYPE = RST;
; I/O Bank 0 Usage
BANK_0_USED = 0;
BANK_0_AVAIL = 28;
BANK_0_VCCIO = NA;
BANK_0_VREF1 = NA;
; I/O Bank 1 Usage
BANK_1_USED = 11;
BANK_1_AVAIL = 29;
BANK_1_VCCIO = 2.5V;
BANK_1_VREF1 = NA;
; I/O Bank 2 Usage
BANK_2_USED = 4;
BANK_2_AVAIL = 29;
BANK_2_VCCIO = 2.5V;
BANK_2_VREF1 = NA;
; I/O Bank 3 Usage
BANK_3_USED = 5;
BANK_3_AVAIL = 9;
BANK_3_VCCIO = 2.5V;
BANK_3_VREF1 = NA;
; I/O Bank 4 Usage
BANK_4_USED = 0;
BANK_4_AVAIL = 10;
BANK_4_VCCIO = NA;
BANK_4_VREF1 = NA;
; I/O Bank 5 Usage
BANK_5_USED = 1;
BANK_5_AVAIL = 10;
BANK_5_VCCIO = 2.5V;
BANK_5_VREF1 = NA;