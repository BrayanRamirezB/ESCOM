library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
library machxo2;
use machxo2.all;

package packageOsc00 is

component osc00 is
	port(
		osc_int0:inout std_logic
	);
end component;

component div00 is
	port(
		osc_int:inout std_logic;
		indiv:in std_logic_vector(4 downto 0);
		oscOut:inout std_logic
	);
end component;


end packageOsc00;