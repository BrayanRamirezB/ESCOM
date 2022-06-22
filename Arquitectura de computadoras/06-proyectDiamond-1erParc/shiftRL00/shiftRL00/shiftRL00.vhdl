library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
library lattice;
use lattice.all;

entity shiftRL00 is
  port(
        clks: in std_logic;
		ens: in std_logic_vector(7 downto 0);
		control: in std_logic_vector(2 downto 0);
		ins: in std_logic_vector(7 downto 0);
		outs: out std_logic_vector(7 downto 0));		
end shiftRL00;

architecture shiftRL0 of shiftRL00 is 
signal sshift: std_logic_vector(7 downto 0);
signal controRL: std_logic_vector(2 downto 0);
begin
  pshift: process(clks)
  begin
      if(clks'event and clks = '1') then
          case ens is
	          when "00000000" =>
	              outs <= (others => '0');
	              sshift <= ins;
				  controRL<= (others => '0');
				  
	          when "00000001" =>
	               sshift(0) <= '0';
		           sshift(7 downto 1) <= sshift (6 downto 0);
		           outs <= sshift;
				   
			 when "00000010" =>
						sshift(7) <= '0';
						sshift(6 downto 0) <= sshift(7 downto 1);
						outs <= sshift;
						
			when "00000100" =>
						sshift(0) <= sshift(7);
						sshift(7 downto 1) <= sshift(6 downto 0);
						outs <= sshift;
						
			when "00001000" =>
						sshift(7) <= sshift(0);
						sshift(6 downto 0) <= sshift(7 downto 1);
						outs <= sshift;
						
						
			when "00010000" =>
						if(controRL < control ) then
							controRL <= controRL + '1' ;
							sshift(0) <= '0';
							sshift(7 downto 1) <= sshift(6 downto 0);
							outs <= sshift;
						else 
						    controRL<=controRL;
						end if;
						
			when "00100000" =>
						if(control > controRL) then
							controRL <= controRL + '1' ;
							sshift(7) <= '0';
							sshift(6 downto 0) <= sshift(7 downto 1);
							outs <= sshift;
						else 
						    controRL<=controRL;
						end if;
						
			when "01000000" =>
						if(control > controRL) then
							controRL <= controRL + 1 ;
							sshift(0) <= sshift(7);
							sshift(7 downto 1) <= sshift(6 downto 0);
							outs <= sshift;
						else 
						    controRL<=controRL;
						end if;
			when "10000000" =>
						if(control > controRL) then
							controRL <= controRL + 1 ;
							sshift(7) <= sshift(0);
							sshift(6 downto 0) <= sshift(7 downto 1);
							outs <= sshift;
						else 
						    controRL<=controRL;
						end if;
				   
	          when others => null;
          end case;
	  end if;
  end process pshift;
end shiftRL0;