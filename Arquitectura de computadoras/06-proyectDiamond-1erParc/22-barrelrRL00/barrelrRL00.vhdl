library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
use packagebarrelrRL00.all;

entity barrelrRL00 is
  port(
       clk0: inout std_logic;
	   cdiv0: in std_logic_vector(4 downto 0);
	   en0: in std_logic;
	   inc0: inout std_logic_vector(3 downto 0);
	   in0: in std_logic_vector(7 downto 0);
       out0: inout std_logic_vector(7 downto 0));
end barrelrRL00;

architecture barrelrRL0 of barrelrRL00 is
begin

  S00: osc00 port map(oscout0 => clk0,
                      cdiv => cdiv0);
  
  S01: barrelrRL port map(clks => clk0,
                        ens => en0,
						incs => inc0,
						ins => in0,
                        outs => out0);

end barrelrRL0;