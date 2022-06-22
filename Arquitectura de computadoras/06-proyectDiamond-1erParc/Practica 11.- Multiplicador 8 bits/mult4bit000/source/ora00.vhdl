library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity ora00 is
   port( 
        Aoa: in std_logic;
        Boa: in std_logic;
        Yoa: out std_logic
        );
end ora00;

architecture ora0 of ora00 is
begin
  Yoa <= Aoa OR Boa;
end ora0;