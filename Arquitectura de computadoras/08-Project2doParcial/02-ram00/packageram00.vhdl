library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

package packageram00 is
    component osc00
        port(
            cdiv: in std_logic_vector(4 downto 0);
            oscout0: inout std_logic);
    end component;

    component contring00 
		port(
			clkr: in std_logic;
			resetr: in std_logic;
			rwr: in std_logic;
			outr: inout std_logic_vector(3 downto 0)
		);
    end component;

    component coder00
		  port(
			   clkc: in std_logic;
			   resetc, rwc: in std_logic;
			   incontc: in std_logic_vector(3 downto 0);
			   inkeyc: in std_logic_vector(3 downto 0);
			   outcontwritec: inout std_logic_vector(5 downto 0);
			   outcoderc: out std_logic_vector(6 downto 0)
			  );
    end component;

    component memram00
       port(
	        clkmr:in std_logic;
			resetmr, rwmr: in std_logic;
			indirWritemr: in std_logic_vector(5 downto 0);
			indirReadmr: in std_logic_vector(5 downto 0);
			inWordmr: in std_logic_vector(6 downto 0);
			outwordmr: out std_logic_vector(6 downto 0)
	        );
    end component;

    component contRead00
		port(
			clkcr, resetcr, rwcr: in std_logic;
			incontwcr: in std_logic_vector(5 downto 0);
			outcontcr: inout std_logic_vector(5 downto 0)
		);
    end component;

    component muxram00
		port(
			resetm, rwm: in std_logic;
			inwordcm, inwordrm: in std_logic_vector(6 downto 0);
			outwordm: out std_logic_vector(6 downto 0));
    end component;
end packageram00;