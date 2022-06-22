library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity di00 is
  port(
       clk1s: in std_logic;
	   en1s: in std_logic;
	   instate1s: in std_logic_vector(2 downto 0);
	   inr1s: in std_logic_vector(7 downto 0);
	   outr1s: out std_logic_vector(7 downto 0);
       out1s: out std_logic;
	   outFlag1s: out std_logic);
end di00;

architecture di0 of di00 is
signal soutr1s: std_logic_vector(7 downto 0);
begin
  ps1: process(clk1s)
  begin
   if (clk1s'event and clk1s = '1') then
     if (en1s = '1') then
	    soutr1s <= inr1s;
	    outFlag1s <= '0';
	    outr1s <= (others => '0');
	    out1s <= '0';
     elsif (instate1s = "010") then
		soutr1s(0) <= '0';
		soutr1s(7 downto 1) <= soutr1s(6 downto 0);
		outr1s <= soutr1s;
		out1s <= soutr1s(7);
		outFlag1s <= '1';
	 else
		outFlag1s <= '0';
		out1s <= '0';
	 end if;
  end if;
 end process ps1;
end di0;