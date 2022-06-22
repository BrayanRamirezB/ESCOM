library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity coder00 is
   port(
       clkc: in std_logic;
	   enc: in std_logic;
       incontc: in std_logic_vector(3 downto 0);
       inkeyc: in std_logic_vector(3 downto 0);
       outcoder: out std_logic_vector(3 downto 0);
       outpushc: out std_logic	   
       );
end coder00;

architecture coder0 of coder00 is
begin
     pcoder: process(clkc)
variable var0: bit := '0';
variable var1: bit := '0';
variable var2: bit := '0';
variable var3: bit := '0';
     begin
	  case enc is 
	  
	  when '0' => 
	    outcoder <= "0000";
		outpushc <= '0';
	  
	  when '1' => 
	   if(clkc 'event and clkc = '1') then
		   case incontc is
	------------------------------------------------------------
			 when "1000" =>  -- Primer caso de incontc
				case inkeyc is 

	when "0000" => 

	var0 := '0';
	outpushc <= '0';

	when "0001" =>
	if(var0 = '0' )then
	  var0 := '1';
	  outcoder <= "1010"; -- 1 A
	   outpushc <= '1';
	  else 
	   outpushc <= '0';
	end if;
	when "0010" =>

	if(var0 = '0' )then
	  var0 := '1';
	  outcoder <= "1011"; -- 2 B
	  	  outpushc <= '1';
	  else 
	   outpushc <= '0';
	end if;

	when "0100" =>

	if(var0 = '0' )then
	  var0 := '1';
	  outcoder <= "1100"; -- 3  C
	  	  outpushc <= '1';
	  else 
	   outpushc <= '0';
	end if;

	when "1000" =>

	if(var0 = '0' )then
	  var0 := '1';
	  outcoder <= "1101"; -- A D
	  	   outpushc <= '1';
	  else 
	   outpushc <= '0';
	end if;

	when others => null;             
				end case;
	---------------------------------------------------------------
			 when "0100" => -- Segundo caso de incontc
				case inkeyc is 

	when "0000" => 

	var1 := '0';
	outpushc <= '0';

	when "0001" =>
	if(var1 = '0' )then
	  var1 := '1';
	  outcoder <= "0011"; -- 4 3
	  	   outpushc <= '1';
	  else 
	   outpushc <= '0';
	end if;
	when "0010" =>

	if(var1 = '0' )then
	  var1 := '1';
	  outcoder <= "0110"; -- 5 6
	  	   outpushc <= '1';
	  else 
	   outpushc <= '0';
	end if;

	when "0100" =>

	if(var1 = '0' )then
	  var1 := '1';
	  outcoder <= "1001"; -- 6 9 
	  	   outpushc <= '1';
	  else 
	   outpushc <= '0';
	end if;

	when "1000" =>

	if(var1 = '0' )then
	  var1 := '1';
	  outcoder <= "1110"; -- b E
	  	   outpushc <= '1';
	  else 
	   outpushc <= '0';
	end if;

	when others => null;             
				end case;
	---------------------------------------------------------------

			 when "0010" =>  -- Tercer caso de incontc
				case inkeyc is 

	when "0000" => 

	var2 := '0';
	outpushc <= '0';

	when "0001" =>
	if(var2 = '0' )then
	  var2 := '1';
	  outcoder <= "0010"; -- 7 2
	  	   outpushc <= '1';
	  else 
	   outpushc <= '0';
	end if;
	when "0010" =>

	if(var2 = '0' )then
	  var2 := '1';
	  outcoder <= "0101"; -- 8 5 
	  	   outpushc <= '1';
	  else 
	   outpushc <= '0';
	end if;

	when "0100" =>

	if(var2 = '0' )then
	  var2 := '1';
	  outcoder <= "1000"; -- 9 8
	  	   outpushc <= '1';
	  else 
	   outpushc <= '0';
	end if;

	when "1000" =>

	if(var2 = '0' )then
	  var2 := '1';
	  outcoder <= "0000"; -- C 0
	  	   outpushc <= '1';
	  else 
	   outpushc <= '0';
	end if;

	when others => null;             
				end case;
	---------------------------------------------------------------
			 when "0001" => -- Úlitmo caso de incontc
				case inkeyc is 

	when "0000" => 

	var3 := '0';
	outpushc <= '0';

	when "0001" =>
	if(var3 = '0' )then
	  var3 := '1';
	  outcoder <= "0001"; -- 0 1
	  	   outpushc <= '1';
	  else 
	   outpushc <= '0';
	end if;
	when "0010" =>

	if(var3 = '0' )then
	  var3 := '1';
	  outcoder <= "0100"; -- d 4 
	  	   outpushc <= '1';
	  else 
	   outpushc <= '0';
	end if;

	when "0100" =>

	if(var3 = '0' )then
	  var3 := '1';
	  outcoder <= "0111"; -- e 7
	  	   outpushc <= '1';
	  else 
	   outpushc <= '0';
	end if;

	when "1000" =>

	if(var3 = '0' )then
	  var3 := '1';
	  outcoder <= "1111"; -- f F
	  	   outpushc <= '1';
	  else 
	   outpushc <= '0';
	end if;

	when others => null;             
				end case;
	---------------------------------------------------------------
			 when others => null; 
		   end case;
	    end if;
	   when others => null;
	  end case; 
     end process pcoder;
end coder0;