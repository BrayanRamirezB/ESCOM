library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
library lattice;
use lattice.all;

entity pc00 is
	port(
		clkpc: in std_logic;
		repc: in std_logic;
		enpc: in std_logic;
		inFlagpc: in std_logic;
		outpc: inout std_logic_vector(5 downto 0);
		outFlagpc: out std_logic
	);
end pc00;

architecture pc0 of pc00 is
signal scontrolpc: std_logic_vector(2 downto 0);
begin

	scontrolpc <= (repc)&(enpc)&(inFlagpc);
	
	ppc: process(clkpc)
	variable var0: bit:='0';
	variable var1: bit:='0';
	begin
		if(clkpc'event and clkpc='1') then
			case scontrolpc is
				--Vectors with reset = 1 must be at the beginning
				when "100" =>
					outpc <= "000000";
					outFlagpc <= '0';
					var0:='0';
				
				when "110" =>
					outpc <= "000000";
					outFlagpc <= '0';
					var0:='0';
				
				when "010" =>
					if(var0 = '0') then
						var0:='1';
						outFlagpc <= '1';
					else
						outpc <= outpc;
						outFlagpc <= '0';
					end if;
				
				when "011" =>
					if(var1 = '1') then
						var1:='0';
						outpc <= outpc + '1';
						outFlagpc <= '0';
					else
						outpc <= outpc;
						outFlagpc <= '0';
					end if;
					
				when others => null;
			end case;
		end if;
	end process ppc;

end pc0;