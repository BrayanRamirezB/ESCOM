--
-- Synopsys
-- Vhdl wrapper for top level design, written on Fri Feb 18 23:22:24 2022
--
library ieee;
use ieee.std_logic_1164.all;

entity wrapper_for_and00 is
   port (
      Aa : in std_logic_vector(7 downto 0);
      Ba : in std_logic_vector(7 downto 0);
      Ya : out std_logic_vector(7 downto 0)
   );
end wrapper_for_and00;

architecture and0 of wrapper_for_and00 is

component and00
 port (
   Aa : in std_logic_vector (7 downto 0);
   Ba : in std_logic_vector (7 downto 0);
   Ya : out std_logic_vector (7 downto 0)
 );
end component;

signal tmp_Aa : std_logic_vector (7 downto 0);
signal tmp_Ba : std_logic_vector (7 downto 0);
signal tmp_Ya : std_logic_vector (7 downto 0);

begin

tmp_Aa <= Aa;

tmp_Ba <= Ba;

Ya <= tmp_Ya;



u1:   and00 port map (
		Aa => tmp_Aa,
		Ba => tmp_Ba,
		Ya => tmp_Ya
       );
end and0;
