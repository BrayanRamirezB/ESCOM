library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

use packagekey0200.all;

entity key02 is
port(
     clk0: inout std_logic;
	 cdiv0: in std_logic_vector(4 downto 0);
	 en0: in std_logic;
	 outr0: inout std_logic_vector(3 downto 0);
	 inkey0: in std_logic_vector(3 downto 0);
	 out32lc0: inout std_logic_vector(31 downto 0);
	 outr70: inout std_logic_vector(3 downto 0);
	 out7seg0: out std_logic_vector(6 downto 0)
);
end key02; 


architecture key0 of key02 is
signal soutcoderc: std_logic_vector(3 downto 0);
signal soutpushc: std_logic;

begin

K0200: osc00 port map(
     oscout0 => clk0,
	 cdiv => cdiv0
	 

);

K0201: contring00 port map(
     clkr => clk0,
	 enr => en0,
     outr => outr0
);

K0202: coder00 port map(
     clkc => clk0,
	 enc => en0,
	 incontc => outr0,
	 inkeyc => inkey0,
	 outcoder => soutcoderc,
	 outpushc => soutpushc
);



K0203: lect00 port map(
     clklc => clk0,
	 enlc => en0,
	 inpushlc => soutpushc,
	 inhexalc => soutcoderc,
	 out32lc => out32lc0
);



K0204: contring7seg00 port map(
     clkr7 => clk0,
	 enr7 => en0,
	 outr7 => outr70
);




K0205: coder7seg00 port map(
     incontcr7 => outr70,
	 in32cr7 => out32lc0,
	 out7seg => out7seg0
);


end key0;