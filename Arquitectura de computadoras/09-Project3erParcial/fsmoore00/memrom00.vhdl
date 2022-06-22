library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library lattice;
use lattice.all;

entity memrom00 is
	port(clkro: in std_logic;
		encro: in std_logic;
		incontro:  in std_logic_vector(4 downto 0);
		outro: out std_logic_vector(5 downto 0));
end memrom00;

architecture memrom0 of memrom00 is
type arrayrom is array(0 to 63) of std_logic_vector(5 downto 0);
constant wordrom: arrayrom :=("000000",
							"000000",
							"000000",
							"000000",
							"100000",
							"010000",
							"001000",
							"000100",
							"000010",
							"000001",
							"001111",
							"111100",
							"001111",
							"111100",
							"000000",
							"000000",
							"000000",
							"000000",
							"100000",
							"010000",
							"001000",
							"000100",
							"000010",
							"000001",
							"001111",
							"111100",
							"001111",
							"111100",
							"001111",
							"111100",
							"001111",
							"111100",
							others => "000000");
begin
	prom: process(clkro)
			begin
				case encro is
					when '0' =>
						outro <= "000000";
					when '1' =>
						if(clkro'event and clkro='1')then
							outro <= wordrom(conv_integer(incontro));
						end if;
					when others => null;
				end case;
	end process prom;
end memrom0;