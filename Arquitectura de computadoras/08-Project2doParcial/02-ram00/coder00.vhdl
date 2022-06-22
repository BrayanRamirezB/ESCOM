library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library lattice;
use lattice.all;

entity coder00 is
  port(
       clkc: in std_logic;
	   resetc, rwc: in std_logic;
	   incontc: in std_logic_vector(3 downto 0);
	   inkeyc: in std_logic_vector(3 downto 0);
	   outcontwritec: inout std_logic_vector(5 downto 0);
	   outcoderc: out std_logic_vector(6 downto 0)
      );
end coder00;

architecture coder0 of coder00 is
signal scontrolc: std_logic_vector(1 downto 0);
begin
scontrolc <= (resetc)&(rwc);
     pcoder: process(clkc, incontc, inkeyc)
	 variable aux0: bit:='0';
	 variable aux1: bit:='0';
	 variable aux2: bit:='0';
	 variable aux3: bit:='0';
	 begin
		case scontrolc is
			when "00" =>
				outcoderc <= "0000000";
				outcontwritec <= "000000";
				aux0 := '0';
			when "10" =>
				if(clkc'event and clkc='1')then 
					   case incontc is
							  when "1000" =>
									 case inkeyc is
										   when "0000" =>
												  aux0:='0';
												  outcontwritec <= outcontwritec;
					
										   when "0001" =>
												 if(aux0='0')then
													 aux0:='1';
													 outcoderc <= "1110111"; ---A 
													 outcontwritec <= outcontwritec + '1';
												  else
													outcontwritec <= outcontwritec;
												  end if;
												  
										   when "0010" =>
												 if(aux0='0')then
													 aux0:='1';
													 outcoderc <= "0011111";---B 
													 outcontwritec <= outcontwritec + '1';
												  else
													outcontwritec <= outcontwritec;
												  end if;
										   
										   when "0100" =>
												 if(aux0='0')then
													 aux0:='1';
													 outcoderc <= "1001110";---C 
													 outcontwritec <= outcontwritec + '1';
												  else
													outcontwritec <= outcontwritec;
												  end if;
										   
										   when "1000" =>
												 if(aux0='0')then
													 aux0:='1';
													 outcoderc <= "0000001";----
													outcontwritec <= outcontwritec + '1';
												  else
													outcontwritec <= outcontwritec;
												  end if;
										   when others => null;
										 end case;
							  
							  when "0100" =>
									 case inkeyc is
										   when "0000" =>
												  aux1:='0';
												  outcontwritec <= outcontwritec;
												  
										   when "0001" =>
												 if(aux1='0')then
													 aux1:='1';
													 outcoderc <= "1111001"; ---3
													 outcontwritec <= outcontwritec + '1';
												  else
													outcontwritec <= outcontwritec;
												  end if;
												  
										   when "0010" =>
												 if(aux1='0')then
													 aux1:='1';
													 outcoderc <= "1011111";---6
													 outcontwritec <= outcontwritec + '1';
												  else
													outcontwritec <= outcontwritec;
												  end if;
										   
										   when "0100" =>
												 if(aux1='0')then
													 aux1:='1';
													 outcoderc <= "1110011";---9
													 outcontwritec <= outcontwritec + '1';
												  else
													outcontwritec <= outcontwritec;
												  end if;
										   
										   when "1000" =>
												 if(aux1='0')then
													 aux1:='1';
													 outcoderc <= "0011101";---+
													 outcontwritec <= outcontwritec + '1';
												  else
													outcontwritec <= outcontwritec;
												  end if;
										   when others => null;
										 end case;
							  when "0010" =>
									 case inkeyc is
										   when "0000" =>
												  aux2:='0';
												  outcontwritec <= outcontwritec;
												  
										   when "0001" =>
												 if(aux2='0')then
													 aux2:='1';
													 outcoderc <= "1101101"; ---2
													 outcontwritec <= outcontwritec + '1';
												  else
													outcontwritec <= outcontwritec;
												  end if;
												  
										   when "0010" =>
												 if(aux2='0')then
													 aux2:='1';
													 outcoderc <= "1011011";---5
													 outcontwritec <= outcontwritec + '1';
												  else
													outcontwritec <= outcontwritec;
												  end if;
										   
										   when "0100" =>
												 if(aux2='0')then
													 aux2:='1';
													 outcoderc <= "1111111";---8
													 outcontwritec <= outcontwritec + '1';
												  else
													outcontwritec <= outcontwritec;
												  end if;
										   
										   when "1000" =>
												 if(aux2='0')then
													 aux2:='1';
													 outcoderc <= "1111110";---0
													 outcontwritec <= outcontwritec + '1';
												  else
													outcontwritec <= outcontwritec;
												  end if;
										   when others => null;
										 end case;
							  
							  when "0001" =>
									 case inkeyc is
										   when "0000" =>
												  aux3:='0';
												  outcontwritec <= outcontwritec;
												  
										   when "0001" =>
												 if(aux3='0')then
													 aux3:='1';
													 outcoderc <= "0110000"; ---1
													 outcontwritec <= outcontwritec + '1';
												  else
													outcontwritec <= outcontwritec;
												  end if;
												  
										   when "0010" =>
												 if(aux3='0')then
													 aux3:='1';
													 outcoderc <= "0110011";---4
													 outcontwritec <= outcontwritec + '1';
												  else
													outcontwritec <= outcontwritec;
												  end if;
										   
										   when "0100" =>
												 if(aux3='0')then
													 aux3:='1';
													 outcoderc <= "1110000";---7
													 outcontwritec <= outcontwritec + '1';
												  else
													outcontwritec <= outcontwritec;
												  end if;
										   
										   when "1000" =>
												 if(aux3='0')then
													 aux3:='1';
													 outcoderc <= "1100011";---*
													 outcontwritec <= outcontwritec + '1';
												  else
													outcontwritec <= outcontwritec;
												  end if;
										   when others => null;
										 end case;
							  when others => null;
						end case;
					end if;
			  when others => null;
			end case;
      end process pcoder;			
end coder0;
