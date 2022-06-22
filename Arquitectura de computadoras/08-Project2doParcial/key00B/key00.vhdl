library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
use packagekey00.all;

entity key00 is
  port(
        clk0: inout std_logic;
		cdiv0: in std_logic_vector(4 downto 0);
		en0: in std_logic;
		inkey0: in std_logic_vector(3 downto 0);
		outcoder0: out std_logic_vector(6 downto 0);
		outr0: inout std_logic_vector(3 downto 0);
		outtransist0: out std_logic_vector(3 downto 0)
	   );
end key00;
 

architecture key0 of key00 is
begin
     outtransist0 <= "0001";
	 
	 K00: osc00 port map(oscout0 => clk0, cdiv => cdiv0);
	 K01: contring00 port map(clkr => clk0, enr => en0, outr =>outr0 );
	 K02:  coder00 port map(clkc => clk0,enc => en0, inkeyc => inkey0 ,incontc => outr0, outcoderc => outcoder0);
	 

     

end key0;





