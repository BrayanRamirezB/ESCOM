library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library lattice;
use lattice.all;

entity shiftrLR is
	port(clks: in std_logic;
		 ens: in std_logic;
		 ins: in std_logic_vector(7 downto 0);
		 outs: inout std_logic_vector(7 downto 0));
end shiftrLR;

architecture shift of shiftrLR is
begin
	pshift: process(clks)
		begin 
		if (clks'event and clks ='1') then
			case ens is
				when '0' =>
					outs <= ins;
				when '1' => 
					outs(7) <= outs(0);
					outs(6 downto 0) <= outs(7 downto 1);
				when others => null; 

			end case;
		end if;
	end process pshift;

end shift;