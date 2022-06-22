library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
use packageshiftRL00.all;

entity shiftRL00 is
	port(clk0: inout std_logic;
		 cdiv0: in std_logic_vector(4 downto 0);
		 en0: in std_logic;
		 in0: in std_logic_vector(7 downto 0);
		 out0: inout std_logic_vector(7 downto 0));
	
end shiftRL00;

architecture shiftRL0 of shiftRL00 is
begin
	S00: osc00 port map(oscout0 => clk0,
						cdiv => cdiv0);
	
	S01: shiftRL port map(clks => clk0,
						   ens => en0,
						   ins => in0,
						outs => out0);
end shiftRL0;