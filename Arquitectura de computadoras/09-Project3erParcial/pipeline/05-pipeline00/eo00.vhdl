library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity eo00 is
  port(
       clk4s: in std_logic;
	   en4s: in std_logic;
	   instate4s: in std_logic_vector(2 downto 0);
	   inr4s: in std_logic_vector(7 downto 0);
	   outr4s: out std_logic_vector(7 downto 0);
       out4s: out std_logic;
	   outFlag4s: out std_logic);
end eo00;

architecture eo0 of eo00 is
signal soutr4s: std_logic_vector(7 downto 0);
begin
  ps4: process(clk4s)
  begin
   if (clk4s'event and clk4s = '1') then
     if (en4s = '1') then
	    soutr4s <= inr4s;
	    outFlag4s <= '0';
	    outr4s <= (others => '0');
	    out4s <= '0';
     elsif (instate4s = "101") then
		soutr4s(0) <= '0';
		soutr4s(7 downto 1) <= soutr4s(6 downto 0);
		outr4s <= soutr4s;
		out4s <= soutr4s(7);
		outFlag4s <= '1';
	 else
		outFlag4s <= '0';
		out4s <= '0';
	 end if;
  end if;
  end process ps4;
end eo0;