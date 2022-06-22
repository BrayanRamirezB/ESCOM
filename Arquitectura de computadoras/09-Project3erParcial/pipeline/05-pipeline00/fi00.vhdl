library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity fi00 is
  port(
       clk0s: in std_logic;
	   en0s: in std_logic;
	   instate0s: in std_logic_vector(2 downto 0);
	   inr0s: in std_logic_vector(7 downto 0);
	   outr0s: out std_logic_vector(7 downto 0);
       out0s: out std_logic;
	   outFlag0s: out std_logic);
end fi00;

architecture fi0 of fi00 is
signal soutr0s: std_logic_vector(7 downto 0);
begin
  ps0: process(clk0s)
  begin
   if (instate0s = "000")or(en0s = '0') then
	  soutr0s <= inr0s;
	  outFlag0s <= '0';
	  outr0s <= (others => '0');
	  out0s <= '0';
   elsif (en0s = '1') then
      if (clk0s'event and clk0s = '1') then
		  if (instate0s = "001") then
		    soutr0s(0) <= '0';
		    soutr0s(7 downto 1) <= soutr0s(6 downto 0);
		    outr0s <= soutr0s;
		    out0s <= soutr0s(7);
		    outFlag0s <= '1';
		  else
		    outFlag0s <= '0';
			out0s <= '0';
	      end if;
	  end if;
   end if;
  end process ps0;
end fi0;