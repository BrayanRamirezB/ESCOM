--
-- Synopsys
-- Vhdl wrapper for top level design, written on Wed Feb 16 09:10:39 2022
--
library ieee;
use ieee.std_logic_1164.all;

entity wrapper_for_mux00 is
   port (
      Am : in std_logic_vector(7 downto 0);
      Bm : in std_logic_vector(7 downto 0);
      selm : in std_logic_vector(3 downto 0);
      Ym : out std_logic_vector(7 downto 0)
   );
end wrapper_for_mux00;

architecture mux0 of wrapper_for_mux00 is

component mux00
 port (
   Am : in std_logic_vector (7 downto 0);
   Bm : in std_logic_vector (7 downto 0);
   selm : in std_logic_vector (3 downto 0);
   Ym : out std_logic_vector (7 downto 0)
 );
end component;

signal tmp_Am : std_logic_vector (7 downto 0);
signal tmp_Bm : std_logic_vector (7 downto 0);
signal tmp_selm : std_logic_vector (3 downto 0);
signal tmp_Ym : std_logic_vector (7 downto 0);

begin

tmp_Am <= Am;

tmp_Bm <= Bm;

tmp_selm <= selm;

Ym <= tmp_Ym;



u1:   mux00 port map (
		Am => tmp_Am,
		Bm => tmp_Bm,
		selm => tmp_selm,
		Ym => tmp_Ym
       );
end mux0;
