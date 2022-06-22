library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity xora00 is
  port(
       Axa: in std_logic;
	   Bxa: in std_logic;
	   Yxa: out std_logic
  );
end xora00;

architecture xora0 of xora00 is
begin
   Yxa <= Axa XOR Bxa;
end xora0;