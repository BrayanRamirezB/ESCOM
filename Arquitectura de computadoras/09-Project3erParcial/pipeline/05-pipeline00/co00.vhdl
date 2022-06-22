library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity co00 is
  port(
       clk2s: in std_logic;
	   en2s: in std_logic;
	   instate2s: in std_logic_vector(2 downto 0);
	   inr2s: in std_logic_vector(7 downto 0);
	   outr2s: out std_logic_vector(7 downto 0);
       out2s: out std_logic;
	   outFlag2s: out std_logic);
end co00;

architecture co0 of co00 is
signal soutr2s: std_logic_vector(7 downto 0);
begin
  ps2: process(clk2s)
  begin
   if (clk2s'event and clk2s = '1') then
     if (en2s = '1') then
	    soutr2s <= inr2s;
	    outFlag2s <= '0';
	    outr2s <= (others => '0');
	    out2s <= '0';
     elsif (instate2s = "011") then
		soutr2s(0) <= '0';
		soutr2s(7 downto 1) <= soutr2s(6 downto 0);
		outr2s <= soutr2s;
		out2s <= soutr2s(7);
		outFlag2s <= '1';
	 else
		outFlag2s <= '0';
		out2s <= '0';
	 end if;
  end if;
 end process ps2;
end co0;