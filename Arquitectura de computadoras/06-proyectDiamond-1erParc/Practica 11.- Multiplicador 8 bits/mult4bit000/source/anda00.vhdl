library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity anda00 is
  port(
       Aaa: in std_logic;
	   Baa: in std_logic;
	   Yaa: out std_logic
  );
end anda00;

architecture  anda0 of anda00 is
begin
   Yaa <= Aaa AND Baa;
end anda0;