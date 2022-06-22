--
-- Synopsys
-- Vhdl wrapper for top level design, written on Thu Mar 10 09:18:31 2022
--
library ieee;
use ieee.std_logic_1164.all;
library work;
use work.packageosc00.all;

entity wrapper_for_osc00 is
   port (
      cdiv : in std_logic_vector(4 downto 0);
      oscout0 : in std_logic
   );
end wrapper_for_osc00;

architecture osc0 of wrapper_for_osc00 is

component osc00
 port (
   cdiv : in std_logic_vector (4 downto 0);
   oscout0 : inout std_logic
 );
end component;

signal tmp_cdiv : std_logic_vector (4 downto 0);
signal tmp_oscout0 : std_logic;

begin

tmp_cdiv <= cdiv;

tmp_oscout0 <= oscout0;



u1:   osc00 port map (
		cdiv => tmp_cdiv,
		oscout0 => tmp_oscout0
       );
end osc0;
