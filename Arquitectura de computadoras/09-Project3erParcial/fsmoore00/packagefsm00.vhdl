library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

package packagefsm00 is
	
	component osc00
		port(
		   cdiv: in std_logic_vector(4 downto 0);
		   oscout0: inout std_logic);
	end component;
	
	component contRead00
		port(
			clkcr: in std_logic;
			encr: in std_logic;
			outcr: inout std_logic_vector(4 downto 0));
	end component;
	
	component memrom00
		port(clkro: in std_logic;
			encro: in std_logic;
			incontro:  in std_logic_vector(4 downto 0);
			outro: out std_logic_vector(5 downto 0));
	end component;
	
	component fsm00
		port (
			clkfsm: in std_logic;
			enfsm: in std_logic;
			inxfsm: in std_logic_vector(5 downto 0);
			outfsm: out std_logic_vector(2 downto 0));
	end component;

end packagefsm00;