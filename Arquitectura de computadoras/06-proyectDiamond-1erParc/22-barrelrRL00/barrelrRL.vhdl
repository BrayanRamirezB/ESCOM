library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library lattice;
use lattice.all;

entity barrelrRL is
  port(
        clks: in std_logic;
		ens: in std_logic;
		incs: inout std_logic_vector(3 downto 0);
		ins: in std_logic_vector(7 downto 0);
        outs: inout std_logic_vector(7 downto 0));
end barrelrRL;

architecture barrel of barrelrRL is
signal scontrol: std_logic_vector(3 downto 0);
begin
  pshift: process(clks)
  begin
    if (clks'event and clks = '1') then
	  case ens is	
		when '0' =>
		  outs <= ins;
		  scontrol <= "0000";
		when '1' =>
		  if(scontrol < incs) then
			scontrol <= scontrol + '1';		  
			outs(0) <= outs(7);
			outs(7 downto 1) <= outs(6 downto 0);
		  else
			scontrol <= scontrol; 
		  end if;
		when others => null;
	  end case;
	end if;
  end process pshift;
end barrel;