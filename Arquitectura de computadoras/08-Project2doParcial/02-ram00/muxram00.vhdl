library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity muxram00 is 
    port(
        resetm, rwm: in std_logic;
        inwordcm, inwordrm: in std_logic_vector(6 downto 0);
        outwordm: out std_logic_vector(6 downto 0));
end muxram00;

architecture muxram0 of muxram00 is
signal scontrolm: std_logic_vector(1 downto 0);
begin
    scontrolm <= (resetm)&(rwm);
    with scontrolm select
        outwordm <= inwordcm when "10",
                    inwordrm when "11",
                    "0000000" when others;
end muxram0;