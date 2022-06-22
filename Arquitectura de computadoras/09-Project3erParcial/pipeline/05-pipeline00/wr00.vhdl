library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity wr00 is
  port(
       clk5s: in std_logic;
	   en5s: in std_logic;
	   instate5s: in std_logic_vector(2 downto 0);
	   inr5s: in std_logic_vector(7 downto 0);
	   outr5s: out std_logic_vector(7 downto 0);
       out5s: out std_logic;
	   outFlag5s: out std_logic);
end wr00;

architecture wr0 of wr00 is
signal soutr5s: std_logic_vector(7 downto 0);
begin
  ps5: process(clk5s)
  begin
   if (clk5s'event and clk5s = '1') then
     if (en5s = '1') then
	    soutr5s <= inr5s;
	    outFlag5s <= '0';
	    outr5s <= (others => '0');
	    out5s <= '0';
     elsif (instate5s = "110") then
		soutr5s(0) <= '0';
		soutr5s(7 downto 1) <= soutr5s(6 downto 0);
		outr5s <= soutr5s;
		out5s <= soutr5s(7);
		outFlag5s <= '1';
	 else
		outFlag5s <= '0';
		outr5s <= (others => '0');
		out5s <= '0';
	 end if;
  end if;
  end process ps5;
end wr0;