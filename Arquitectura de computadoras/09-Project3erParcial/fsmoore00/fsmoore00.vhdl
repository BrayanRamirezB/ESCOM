library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

use packagefsm00.all;

entity fsmoore00 is
	port(
		clk0: inout std_logic;
		cdiv0: in std_logic_vector(4 downto 0);
		en0: in std_logic;
		address0: inout std_logic_vector(4 downto 0);
		inxfsm0: inout std_logic_vector(5 downto 0);
		outfsm0: out std_logic_vector(2 downto 0));
end fsmoore00;

architecture fsmoore0 of fsmoore00 is
begin

	FS00: osc00 port map(oscout0 => clk0,
						cdiv => cdiv0);
	
	FS01: contRead00 port map(clkcr => clk0,
								encr => en0,
								outcr => address0);
		
	FS02: memrom00 port map(clkro => clk0,
							encro => en0,
							incontro => address0,
							outro => inxfsm0);	
	
	FS03: fsm00 port map(clkfsm => clk0,
						enfsm => en0,
						inxfsm => inxfsm0,
						outfsm => outfsm0);	
	
end fsmoore0;