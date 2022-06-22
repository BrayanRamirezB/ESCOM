library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
use packagepipeline00.all;

entity pipeline00 is
	port(
		clk0: inout std_logic;
		cdiv0: in std_logic_vector(4 downto 0);
		en0: in std_logic;
		in0: in std_logic_vector(7 downto 0);
		out0: out std_logic_vector(7 downto 0);--Salida de la ultima etapa WR
		outFlag00: inout std_logic;
		outFlag10: inout std_logic;
		outFlag20: inout std_logic;
		outFlag30: inout std_logic;
		outFlag40: inout std_logic;
		outFlag50: inout std_logic;
		outr00, outr10, outr20: out std_logic;
		outr30, outr40, outr50: out std_logic;
		statezz0: inout std_logic_vector(2 downto 0)
	);
end pipeline00;

architecture pipeline0 of pipeline00 is
signal soutr0s: std_logic_vector(7 downto 0);
signal soutr1s: std_logic_vector(7 downto 0);
signal soutr2s: std_logic_vector(7 downto 0);
signal soutr3s: std_logic_vector(7 downto 0);
signal soutr4s: std_logic_vector(7 downto 0);
begin

	FSM00: osc00 port map(
		cdiv => cdiv0,
		oscOut0 => clk0
	);
	
	FSM01: fi00 port map(
		clk0s => clk0,
        en0s => en0,
		instate0s => statezz0,
		inr0s => in0,
		outr0s => soutr0s,
		out0s => outr00,
        outFlag0s => outFlag00
	);
	
	FSM02: di00 port map(
		clk1s => clk0,
        en1s => outFlag00,
		instate1s => statezz0,
		inr1s => soutr0s,
		outr1s => soutr1s,
		out1s => outr10,
        outFlag1s => outFlag10
	);
	
	FSM03: co00 port map(
		clk2s => clk0,
		en2s => outFlag10,
		instate2s => statezz0,
		inr2s => soutr1s,
		outr2s => soutr2s,
		out2s => outr20,
        outFlag2s => outFlag20
	);
	
	FSM04: fo00 port map(
		clk3s => clk0,
        en3s => outFlag20,
		instate3s => statezz0,
		inr3s => soutr2s,
		outr3s => soutr3s,
		out3s => outr30,
        outFlag3s => outFlag30
	);
	
	FSM05: eo00 port map(
		clk4s => clk0,
        en4s => outFlag30,
		instate4s => statezz0,
		inr4s => soutr3s,
		outr4s => soutr4s,
		out4s => outr40,
        outFlag4s => outFlag40
	);
	
	FSM06: wr00 port map(
		clk5s => clk0,
        en5s => outFlag40,
		instate5s => statezz0,
		inr5s => soutr4s,
		outr5s => out0,
		out5s => outr50,
        outFlag5s => outFlag50
	);
	
	FSM07: fsmpipe02 port map(
		clkfsm => clk0,
        enfsm => en0,
		inx0 => outFlag00,
		inx1 => outFlag10,
		inx2 => outFlag20,
		inx3 => outFlag30,
		inx4 => outFlag40,
		inx5 => outFlag50,
		outzz => statezz0
	);

end pipeline0;