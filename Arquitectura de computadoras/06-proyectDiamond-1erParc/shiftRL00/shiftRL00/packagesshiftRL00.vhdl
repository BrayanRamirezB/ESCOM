library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

package packageshiftRL00 is 
   
  component osc00
    port(
       cdiv: in std_logic_vector(4 downto 0);
	   oscout0: inout std_logic);
  end component;
   
  component shiftRL00
    port(
       clks: in std_logic;
		ens: in std_logic_vector(7 downto 0);
		control: in std_logic_vector(2 downto 0);
		ins: in std_logic_vector(7 downto 0);
		outs: out std_logic_vector(7 downto 0));	
   end component;
   
end packageshiftRL00;
