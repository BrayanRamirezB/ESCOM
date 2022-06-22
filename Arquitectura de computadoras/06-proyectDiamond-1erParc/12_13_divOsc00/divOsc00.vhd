library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
library machxo2;
use machxo2.all;

use packageOsc00.all;

entity divOsc00 is
	port(
		cdiv:in std_logic_vector(4 downto 0);
		oscOut0:inout std_logic
	);
end divOsc00;

architecture divOsc0 of divOsc00 is

signal clkaux: std_logic;

begin
	C00: osc00 port map(
						osc_int0=>clkaux
					);
	
	C01: div00 port map(
						osc_int=>clkaux,
						indiv=>cdiv,
						oscOut=>oscOut0
					);
end divOsc0;