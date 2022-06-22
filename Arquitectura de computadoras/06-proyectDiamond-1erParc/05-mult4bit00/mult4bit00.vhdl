library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
use packagemult4bit00.all;

entity mult4bit00 is
	port(
		Ai: in std_logic_vector(3 downto 0);
		Bi: in std_logic_vector(3 downto 0);
		Ro: out std_logic_vector(7 downto 0));
end mult4bit00;

architecture mult4bit0 of mult4bit00 is
signal S0, S3, S6, S8: std_logic_vector(2 downto 0);
signal S1, S2, S4, S5, S7: std_logic_vector(3 downto 0);
begin

	M400: and00 port map(Aa => Ai(0),
						Ba => Bi(0),
						Ya => Ro(0));
						
	M401: and00 port map(Aa => Ai(1),
						Ba => Bi(0),
						Ya => S0(0)); 
							M402: and00 port map(Aa => Ai(2),
						Ba => Bi(0),
						Ya => S0(1));
						
	M403: and00 port map(Aa => Ai(3),
						Ba => Bi(0),
						Ya => S0(2)); 
	
	
	M404: and00 port map(Aa => Ai(0),
						Ba => Bi(1),
						Ya => S1(0));
						
	M405: and00 port map(Aa => Ai(1),
						Ba => Bi(1),
						Ya => S1(1)); 
	
	M406: and00 port map(Aa => Ai(2),
						Ba => Bi(1),
						Ya => S1(2)); 
	
	M407: and00 port map(Aa => Ai(3),
						Ba => Bi(1),
						Ya => S1(3));
	
	
	M408: fa00 port map(C00 => '0',
						A00 => S0(0),
						B00 => S1(0),
						C01 => S2(0),
						S00 => Ro(1));
	
	M409: fa00 port map(C00 => S2(0),
						A00 => S0(1),
						B00 => S1(1),
						C01 => S2(1),
						S00 => S3(0));
		M410: fa00 port map(C00 => S2(1),
						A00 => S0(2),
						B00 => S1(2),
						C01 => S2(2),
						S00 => S3(1));
	
	M411: fa00 port map(C00 => S2(2),
						A00 => '0',
						B00 => S1(3),
						C01 => S2(3),
						S00 => S3(2)); 
	
	
	M412: and00 port map(Aa => Ai(0),
						Ba => Bi(2),
						Ya => S4(0));
						
	M413: and00 port map(Aa => Ai(1),
						Ba => Bi(2),
						Ya => S4(1));
		M414: and00 port map(Aa => Ai(2),
						Ba => Bi(2),
						Ya => S4(2)); 

	M415: and00 port map(Aa => Ai(3),
						Ba => Bi(2),
						Ya => S4(3)); 
	
	
	M416: fa00 port map(C00 => '0',
						A00 => S3(0),
						B00 => S4(0),
						C01 => S5(0),
						S00 => Ro(2));
						
	M417: fa00 port map(C00 => S5(0),
						A00 => S3(1),
						B00 => S4(1),
						C01 => S5(1),
						S00 => S6(0)); 	
	
	M418: fa00 port map(C00 => S5(1),
						A00 => S3(2),
						B00 => S4(2),
						C01 => S5(2),
						S00 => S6(1)); 
	
	M419: fa00 port map(C00 => S5(2),
						A00 => S2(3),
						B00 => S4(3),
						C01 => S5(3),
						S00 => S6(2));
	
	
	M420: and00 port map(Aa => Ai(0),
						Ba => Bi(3),
						Ya => S7(0));
	
	M421: and00 port map(Aa => Ai(1),
						Ba => Bi(3),
						Ya => S7(1)); 	
	
	M422: and00 port map(Aa => Ai(2),
						Ba => Bi(3),
						Ya => S7(2)); 
	
	M423: and00 port map(Aa => Ai(3),
						Ba => Bi(3),
						Ya => S7(3));

	M424: fa00 port map(C00 => '0',
						A00 => S6(0),
						B00 => S7(0),
						C01 => S8(0),
						S00 => Ro(3));
	
	M425: fa00 port map(C00 => S8(0),
						A00 => S6(1),
						B00 => S7(1),
						C01 => S8(1),
						S00 => Ro(4)); 	
	
	M426: fa00 port map(C00 => S8(1),
						A00 => S6(2),
						B00 => S7(2),
						C01 => S8(2),
						S00 => Ro(5)); 
	
	M427: fa00 port map(C00 => S8(2),
						A00 => S5(3),
						B00 => S7(3),
						C01 => Ro(7),
						S00 => Ro(6));

end mult4bit0;