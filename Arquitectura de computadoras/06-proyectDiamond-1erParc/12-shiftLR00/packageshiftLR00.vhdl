library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library lattice;
use lattice.all;

package packageshiftLR00 is

	component osc00
	 port(
       cdiv: in std_logic_vector(4 downto 0);
       oscout0: inout std_logic);
	
	end component;
	
	component shiftLR
	port(clks: in std_logic;
		 ens: in std_logic;
		 ins: in std_logic_vector(7 downto 0);
		 outs: inout std_logic_vector(7 downto 0));
	
	end component;

end packageshiftLR00;