library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity fsm00 is
	port (
		clkfsm: in std_logic;
		enfsm: in std_logic;
		inxfsm: in std_logic_vector(5 downto 0);
		outfsm: out std_logic_vector(2 downto 0));
end fsm00;

architecture fsm0 of fsm00 is
type estados is(A, B, C, D, E, F, G, H);
signal E_act, E_sig: estados;
begin
--Proceso para la transmision de los estados
	p00: process(clkfsm)
		variable var0: bit:='0';
		begin
			case enfsm is
				when '0' =>
					E_act <= A;
					var0:='0';
				when '1' =>
					if(clkfsm'event and clkfsm='1') then
						if(var0 = '0')then
							var0 := '1';
						else
							E_act <= E_sig; 
						end if;
					end if;	
				when others => null;
			end case;
	end process p00;
	
--Proceso para la evaluacion de los estados
	p01: process(inxfsm)
		begin
			case enfsm is
				when '0' =>
					outfsm <= "000";
				when '1' =>
					case E_act is
						when A =>
							if(inxfsm = "000000") then
								E_sig <= B;
								outfsm <= "000";
							else
								E_sig <= A;
								outfsm <= "000";
							end if;
							
						when B =>
							if(inxfsm = "100000") then
								E_sig <= C;
								outfsm <= "001";
							else
								E_sig <= B;
								outfsm <= "000";
							end if;
							
						when C =>
							if(inxfsm = "010000") then
								E_sig <= D;
								outfsm <= "010";
							else
								E_sig <= A;
								outfsm <= "000";
							end if;
							
						when D =>
							if(inxfsm = "001000") then
								E_sig <= E;
								outfsm <= "011";
							else
								E_sig <= A;
								outfsm <= "000";
							end if;
							
						when E =>
							if(inxfsm = "000100") then
								E_sig <= F;
								outfsm <= "100";
							else
								E_sig <= A;
								outfsm <= "000";
							end if;
						
						when F =>
							if(inxfsm = "000010") then
								E_sig <= G;
								outfsm <= "101";
							else
								E_sig <= A;
								outfsm <= "000";
							end if;
						
						when G =>
							if(inxfsm = "000001") then
								E_sig <= H;
								outfsm <= "110";
							else
								E_sig <= A;
								outfsm <= "000";
							end if;
							
						when H =>
							if(inxfsm = "000001") then
								E_sig <= A;
								outfsm <= "000";
							else
								E_sig <= A;
								outfsm <= "000";
							end if;	
						when others => null;
					end case;
				when others => null;
			end case;
	end process p01;
end fsm0;