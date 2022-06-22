library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
use packageshiftrLR00.all;

entity shiftrLR00 is
	port(clk0: inout std_logic;
		 cdiv0: in std_logic_vector(4 downto 0);
		 en0: in std_logic;
		 in0: in std_logic_vector(7 downto 0);
		 out0: inout std_logic_vector(7 downto 0));
	
end shiftrLR00;

architecture shiftrLR0 of shiftrLR00 is
begin
	S00: osc00 port map(oscout0 => clk0,
						cdiv => cdiv0);
	
	S01: shiftrLR port map(clks => clk0,
						   ens => en0,
						   ins => in0,
						outs => out0);
end shiftrLR0;