library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity mux00 is
	port(
		Am: in std_logic_vector(7 downto 0);
		Bm: in std_logic_vector(7 downto 0);
		selm: in std_logic_vector(3 downto 0);
		Ym: out std_logic_vector(7 downto 0));
end mux00;	

architecture mux0 of mux00 is
begin
	with selm select
		Ym <= Am and Bm when "0001",
			Am or Bm when "0011",
			Am xor Bm when "0010",
			Am nand Bm when "0110",
			Am nor Bm when "0111",
			Am xnor Bm when "1111",
			not (Am) when "1110",
			not (Bm) when "1100",
			Am when "1101",
			Bm when "1001",
			"00000000" when others;
end mux0;

