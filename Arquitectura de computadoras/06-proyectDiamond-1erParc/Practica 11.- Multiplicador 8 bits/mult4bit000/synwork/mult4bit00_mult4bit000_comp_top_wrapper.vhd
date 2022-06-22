--
-- Synopsys
-- Vhdl wrapper for top level design, written on Wed Sep 22 23:35:25 2021
--
library ieee;
use ieee.std_logic_1164.all;
library work;
use work.packagemult4bit00.all;

entity wrapper_for_mult4bit00 is
   port (
      Am : in std_logic_vector(7 downto 0);
      Bm : in std_logic_vector(7 downto 0);
      Rm : out std_logic_vector(15 downto 0)
   );
end wrapper_for_mult4bit00;

architecture mult4bit0 of wrapper_for_mult4bit00 is

component mult4bit00
 port (
   Am : in std_logic_vector (7 downto 0);
   Bm : in std_logic_vector (7 downto 0);
   Rm : out std_logic_vector (15 downto 0)
 );
end component;

signal tmp_Am : std_logic_vector (7 downto 0);
signal tmp_Bm : std_logic_vector (7 downto 0);
signal tmp_Rm : std_logic_vector (15 downto 0);

begin

tmp_Am <= Am;

tmp_Bm <= Bm;

Rm <= tmp_Rm;



u1:   mult4bit00 port map (
		Am => tmp_Am,
		Bm => tmp_Bm,
		Rm => tmp_Rm
       );
end mult4bit0;
