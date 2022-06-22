library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library lattice;
use lattice.all;

entity contRead00 is 
    port(
        clkcr, resetcr, rwcr: in std_logic;
        incontwcr: in std_logic_vector(5 downto 0);
        outcontcr: inout std_logic_vector(5 downto 0)
    );
end contRead00;

architecture contRead0 of contRead00 is 
signal scontrolc: std_logic_vector(1 downto 0);
begin
    scontrolc <= (resetcr)&(rwcr);
    pread: process(clkcr)
    begin
        if(clkcr'event and clkcr='1')then
            case scontrolc is
                when "00" =>
                    outcontcr <= "000000";
                when "10" =>
                    outcontcr <= "000000";
                when "11" =>
                    if(outcontcr < incontwcr)then  
                        outcontcr <= outcontcr + '1';
                    else
                        outcontcr <= outcontcr;
                    end if;
                when others => null;
            end case;
        end if;
    end process pread;
end contRead0;