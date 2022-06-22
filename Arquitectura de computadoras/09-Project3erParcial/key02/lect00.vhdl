library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all; 

entity lect00 is 
port(
     clklc: in std_logic;
	 enlc: in std_logic;
	 inpushlc: in std_logic;
	 inhexalc: in std_logic_vector(3 downto 0);
	 out32lc: inout std_logic_vector(31 downto 0)
);
end lect00;

architecture lect0 of lect00 is
signal scontrollc: std_logic_vector(1 downto 0);
begin
   scontrollc <= (enlc)&(inpushlc);
   plec: process(clklc)
   begin
      case scontrollc is 
	  when "00" => 
	     out32lc <= (others => '0');

			  	  when "11" => 
				    if(clklc'event and clklc = '1') then
					   out32lc(3 downto 0) <= inhexalc;   -- Finalización de la clase 11 / 05 / 2022
					   out32lc(31 downto 4) <= out32lc(27 downto 0); 
					end if;
				  	  when others => null;
	  end case;
   
   end process plec;

end lect0;