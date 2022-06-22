library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library lattice;
use lattice.all;

entity memram00 is
       port(
	        clkmr:in std_logic;
			resetmr, rwmr: in std_logic;
			indirWritemr: in std_logic_vector(5 downto 0);
			indirReadmr: in std_logic_vector(5 downto 0);
			inWordmr: in std_logic_vector(6 downto 0);
			outwordmr: out std_logic_vector(6 downto 0)
	        );
end memram00;


architecture memram0 of memram00 is
type arrayram is array(0 to 63) of std_logic_vector(6 downto 0);
signal wordram: arrayram;
signal scontrolmr: std_logic_vector(1 downto 0);
begin 
scontrolmr <= (resetmr)&(rwmr);
	pram: process(clkmr)
	begin
		if (clkmr'event and clkmr = '1') then
			case scontrolmr is
				when "10" =>
					wordram(conv_integer(indirWritemr)) <= inWordmr;
				when "11" =>
					outwordmr <= wordram(conv_integer(indirReadmr));
				when others => null;
			end case;
		end if;
	end process pram;
end memram0;

