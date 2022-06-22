library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity fo00 is
  port(
       clk3s: in std_logic;
	   en3s: in std_logic;
	   instate3s: in std_logic_vector(2 downto 0);
	   inr3s: in std_logic_vector(7 downto 0);
	   outr3s: out std_logic_vector(7 downto 0);
       out3s: out std_logic;
	   outFlag3s: out std_logic);
end fo00;

architecture fo0 of fo00 is
signal soutr3s: std_logic_vector(7 downto 0);
begin
  ps3: process(clk3s)
  begin
   if (clk3s'event and clk3s = '1') then
     if (en3s = '1') then
	    soutr3s <= inr3s;
	    outFlag3s <= '0';
	    outr3s <= (others => '0');
	    out3s <= '0';
     elsif (instate3s = "100") then
		soutr3s(0) <= '0';
		soutr3s(7 downto 1) <= soutr3s(6 downto 0);
		outr3s <= soutr3s;
		out3s <= soutr3s(7);
		outFlag3s <= '1';
	 else
		outFlag3s <= '0';
		out3s <= '0';
	 end if;
  end if;
  end process ps3;
end fo0;