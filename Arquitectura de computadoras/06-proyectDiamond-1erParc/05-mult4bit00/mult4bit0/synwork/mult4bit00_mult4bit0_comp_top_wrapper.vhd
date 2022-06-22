--
-- Synopsys
-- Vhdl wrapper for top level design, written on Wed Mar  2 09:44:17 2022
--
library ieee;
use ieee.std_logic_1164.all;
library work;
use work.packagemult4bit00.all;

entity wrapper_for_mult4bit00 is
   port (
      Ai : in std_logic_vector(3 downto 0);
      Bi : in std_logic_vector(3 downto 0);
      Ro : out std_logic_vector(7 downto 0)
   );
end wrapper_for_mult4bit00;

architecture mult4bit0 of wrapper_for_mult4bit00 is

component mult4bit00
 port (
   Ai : in std_logic_vector (3 downto 0);
   Bi : in std_logic_vector (3 downto 0);
   Ro : out std_logic_vector (7 downto 0)
 );
end component;

signal tmp_Ai : std_logic_vector (3 downto 0);
signal tmp_Bi : std_logic_vector (3 downto 0);
signal tmp_Ro : std_logic_vector (7 downto 0);

begin

tmp_Ai <= Ai;

tmp_Bi <= Bi;

Ro <= tmp_Ro;



u1:   mult4bit00 port map (
		Ai => tmp_Ai,
		Bi => tmp_Bi,
		Ro => tmp_Ro
       );
end mult4bit0;
