library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library lattice;
use lattice.all;

--Tabla de 0 a 6
--Contador puede ser de 3 bits o debe ser de 3 bits

entity contRead00 is
	port(
		clkcr: in std_logic;
		encr: in std_logic;
		outcr: inout std_logic_vector(4 downto 0));
end contRead00;

architecture contRead0 of contRead00 is
begin
	pcont: process(clkcr)
		begin
			if(clkcr'event and clkcr='1') then
				case encr is
					when '0' =>
						outcr <= "00000";
					when '1' =>
						outcr <= outcr + '1';
					when others => null;
				end case;
			end if;
	end process pcont;
end contRead0;