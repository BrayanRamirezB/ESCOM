library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

package packagepipeline00 is

	component osc00 is
		port(
			cdiv:in std_logic_vector(4 downto 0);
			oscOut0: inout std_logic
		);
	end component;
	
	component fi00 is
		port(
		   clk0s: in std_logic;
		   en0s: in std_logic;
		   instate0s: in std_logic_vector(2 downto 0);
		   inr0s: in std_logic_vector(7 downto 0);
		   outr0s: out std_logic_vector(7 downto 0);
		   out0s: out std_logic;
		   outFlag0s: out std_logic
		);
	end component;
	
	component di00 is
		port(
		   clk1s: in std_logic;
		   en1s: in std_logic;
		   instate1s: in std_logic_vector(2 downto 0);
		   inr1s: in std_logic_vector(7 downto 0);
		   outr1s: out std_logic_vector(7 downto 0);
		   out1s: out std_logic;
		   outFlag1s: out std_logic
		);
	end component;
	
	component co00 is
		port(
		   clk2s: in std_logic;
		   en2s: in std_logic;
		   instate2s: in std_logic_vector(2 downto 0);
		   inr2s: in std_logic_vector(7 downto 0);
		   outr2s: out std_logic_vector(7 downto 0);
		   out2s: out std_logic;
		   outFlag2s: out std_logic
		);
	end component;
	
	component fo00 is
		port(
		   clk3s: in std_logic;
		   en3s: in std_logic;
		   instate3s: in std_logic_vector(2 downto 0);
		   inr3s: in std_logic_vector(7 downto 0);
		   outr3s: out std_logic_vector(7 downto 0);
		   out3s: out std_logic;
		   outFlag3s: out std_logic
		);
	end component;
	
	component eo00 is
		port(
		   clk4s: in std_logic;
		   en4s: in std_logic;
		   instate4s: in std_logic_vector(2 downto 0);
		   inr4s: in std_logic_vector(7 downto 0);
		   outr4s: out std_logic_vector(7 downto 0);
		   out4s: out std_logic;
		   outFlag4s: out std_logic
		);
	end component;
	
	component wr00 is
		port(
		   clk5s: in std_logic;
		   en5s: in std_logic;
		   instate5s: in std_logic_vector(2 downto 0);
		   inr5s: in std_logic_vector(7 downto 0);
		   outr5s: out std_logic_vector(7 downto 0);
		   out5s: out std_logic;
		   outFlag5s: out std_logic
		);
	end component;
	
	component fsmpipe02 is
		port(
		   clkfsm: in std_logic;
		   enfsm: in std_logic;
		   inx0, inx1, inx2, inx3, inx4, inx5: std_logic;
		   outzz: out std_logic_vector(2 downto 0)
		);
	end component;

end packagepipeline00;