library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity fsmpipe02 is
  port(
       clkfsm: in std_logic;
	   enfsm: in std_logic;
	   inx0, inx1, inx2, inx3, inx4, inx5: std_logic;
       outzz: out std_logic_vector(2 downto 0));
end fsmpipe02;

architecture fsmpipe0 of fsmpipe02 is
signal sinx: std_logic_vector(5 downto 0);
begin
sinx <= (inx0)&(inx1)&(inx2)&(inx3)&(inx4)&(inx5);
 evalState: process(clkfsm)
 variable aux01: std_logic_vector(2 downto 0);
  begin
    if (clkfsm'event and clkfsm = '1') then
     case enfsm is
	  when '0' =>
	    aux01:="000";--estado A
		outzz <= "000";
	  when '1' =>
        case aux01 is
          when "000" =>-- estado A
             if (sinx = "000000") then
                aux01:="001";--estado B
				outzz <= "001";
             end if;
          when "001" =>-- estado B
             if (sinx = "100000") then
                aux01:="010";-- estado C
				outzz <= "010";
             end if;
          when "010" =>-- estado C
             if (sinx = "010000") then
                aux01:="011";-- Estado D
				outzz <= "011";
             end if;
          when "011" =>-- estado D
             if (sinx = "001000") then
                aux01:="100";-- estado E
				outzz <= "100";
             end if;
          when "100" =>-- estado E
             if (sinx = "000100") then
                aux01:="101";-- estado F
				outzz <= "101";
             end if;
          when "101" =>-- estado F
             if (sinx = "000010") then
                aux01:="110";-- estado G
				outzz <= "110";
             end if;
          when "110" =>-- estado G
             if (sinx = "000001") then
                aux01:="000";-- estado A
				outzz <= "000";
             end if;
          when others => null;
       end case;
	 when others => null;
   end case;
  end if;
end process evalState;
end fsmpipe0;