library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

package packagekey0200 is
--------------------------------------------------------------------------------------------
    component osc00
	
	  port(
       cdiv: in std_logic_vector(4 downto 0);
       oscout0: inout std_logic
	       );
		   
	end component;
	
--------------------------------------------------------------------------------------------	
	component contring00
	
	port(
    clkr: in std_logic;
    enr: in std_logic;
    outr: inout std_logic_vector(3 downto 0)
         );
	
	end component;
--------------------------------------------------------------------------------------------
	component coder00
	
	   port(
       clkc: in std_logic;
	   enc: in std_logic;
       incontc: in std_logic_vector(3 downto 0);
       inkeyc: in std_logic_vector(3 downto 0);
       outcoder: out std_logic_vector(3 downto 0);
       outpushc: out std_logic	   
            );
	
	end component;
--------------------------------------------------------------------------------------------
	component lect00
	
	port(
     clklc: in std_logic;
	 enlc: in std_logic;
	 inpushlc: in std_logic;
	 inhexalc: in std_logic_vector(3 downto 0);
	 out32lc: inout std_logic_vector(31 downto 0)
         );
	
	end component;
--------------------------------------------------------------------------------------------	
	component contring7seg00
	
	port(
    clkr7: in std_logic;
    enr7: in std_logic;
    outr7: inout std_logic_vector(3 downto 0)
         );
	
	end component;
--------------------------------------------------------------------------------------------
	component coder7seg00
	
	port(
     incontcr7: in std_logic_vector(3 downto 0);
	 in32cr7: in std_logic_vector(31 downto 0);
     out7seg: out std_logic_vector(6 downto 0)
        );
	
	end component;
--------------------------------------------------------------------------------------------

end packagekey0200;