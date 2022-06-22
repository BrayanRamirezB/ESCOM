library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity contring7seg00 is
port(
    clkr7: in std_logic;
    enr7: in std_logic;
    outr7: inout std_logic_vector(3 downto 0)
);
end contring7seg00;

architecture contring7seg0 of contring7seg00 is 
begin
   pring: process(clkr7)
   begin
   if (clkr7'event and clkr7 = '1') then 
    case enr7 is
      when '0' => 
         outr7 <= "0001"; -- Se inicializa así porque los displays que tiene mi placa de gallos es de Cátodo Común
      when '1' =>         -- En caso de que usted esté utilizando el prototipo del profe Gelacio deberá cambiar los 0 por 1
          outr7(0) <= outr7(3);
          outr7(3 downto 1) <= outr7(2 downto 0);
      when others => null; 
    end case;
	end if;
   end process pring;
end contring7seg0;