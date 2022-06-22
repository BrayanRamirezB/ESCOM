library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

package packagefa00 is

    component ha00 
       port(  
              A0: in std_logic;
              B0: in std_logic;
              S0: out std_logic;
              C0: out std_logic
           );
    end component;

    component ora00
      port( 
        Aoa: in std_logic;
        Boa: in std_logic;
        Yoa: out std_logic
        );
    end component;

end packagefa00;