library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity coder7seg00 is
port(
     incontcr7: in std_logic_vector(3 downto 0);
	 in32cr7: in std_logic_vector(31 downto 0);
     out7seg: out std_logic_vector(6 downto 0)
);
end coder7seg00;

architecture coder7seg0 of coder7seg00 is
signal snibb0, snibb1, snibb2, snibb3, snibb4, snibb5, snibb6, snibb7: std_logic_vector(3 downto 0);
signal sout7seg0, sout7seg1, sout7seg2, sout7seg3, sout7seg4, sout7seg5, sout7seg6, sout7seg7: std_logic_vector(6 downto 0);

begin
-------------------------------------------------------------------------------------------

snibb0 <= in32cr7(3 downto 0);
snibb1 <= in32cr7(7 downto 4);
snibb2 <= in32cr7(11 downto 8);
snibb3 <= in32cr7(15 downto 12);
snibb4 <= in32cr7(19 downto 16);
snibb5 <= in32cr7(23 downto 20);
snibb6 <= in32cr7(27 downto 24);
snibb7 <= in32cr7(31 downto 28);

--------------------------------------------------------------------------------------------
   with snibb0 select
   sout7seg0 <= "1111110" when "0000", -- 0 <-- Estos valores sirven para los que tienen cátodo común, en mi caso mi placa de gallos tiene cátodo común
                "0110000" when "0001", -- 1 <-- Para los que tienen anodo común cambiar los 1 por 0 y viceversa 
				"1101101" when "0010", -- 2
                "1111001" when "0011", -- 3
                "0110011" when "0100", -- 4
                "1011011" when "0101", -- 5
                "1011111" when "0110", -- 6
                "1110000" when "0111", -- 7
                "1111111" when "1000", -- 8
                "1110011" when "1001", -- 9
                "1110111" when "1010", -- A
                "0011111" when "1011", -- b
                "1001110" when "1100", -- C
                "0111101" when "1101", -- d
                "1001111" when "1110", -- E
                "1000111" when "1111", -- F
                "1111111" when others;
--------------------------------------------------------------------------------------------
   with snibb1 select
   sout7seg1 <= "1111110" when "0000", -- 0 <-- Estos valores sirven para los que tienen cátodo común, en mi caso mi placa de gallos tiene cátodo común
                "0110000" when "0001", -- 1 <-- Para los que tienen anodo común cambiar los 1 por 0 y viceversa 
				"1101101" when "0010", -- 2
                "1111001" when "0011", -- 3
                "0110011" when "0100",
                "1011011" when "0101", -- 5
                "1011111" when "0110", -- 6
                "1110000" when "0111", -- 7
                "1111111" when "1000", -- 8
                "1110011" when "1001", -- 9
                "1110111" when "1010", -- A
                "0011111" when "1011", -- b
                "1001110" when "1100", -- C
                "0111101" when "1101", -- d
                "1001111" when "1110", -- E
                "1000111" when "1111", -- F
                "1111111" when others;
--------------------------------------------------------------------------------------------
   with snibb2 select
   sout7seg2 <= "1111110" when "0000", -- 0 <-- Estos valores sirven para los que tienen cátodo común, en mi caso mi placa de gallos tiene cátodo común
                "0110000" when "0001", -- 1 <-- Para los que tienen anodo común cambiar los 1 por 0 y viceversa 
				"1101101" when "0010", -- 2
                "1111001" when "0011", -- 3
                "0110011" when "0100",
                "1011011" when "0101", -- 5
                "1011111" when "0110", -- 6
                "1110000" when "0111", -- 7
                "1111111" when "1000", -- 8
                "1110011" when "1001", -- 9
                "1110111" when "1010", -- A
                "0011111" when "1011", -- b
                "1001110" when "1100", -- C
                "0111101" when "1101", -- d
                "1001111" when "1110", -- E
                "1000111" when "1111", -- F
                "1111111" when others;
--------------------------------------------------------------------------------------------
   with snibb3 select
   sout7seg3 <= "1111110" when "0000", -- 0 <-- Estos valores sirven para los que tienen cátodo común, en mi caso mi placa de gallos tiene cátodo común
                "0110000" when "0001", -- 1 <-- Para los que tienen anodo común cambiar los 1 por 0 y viceversa 
				"1101101" when "0010", -- 2
                "1111001" when "0011", -- 3
                "0110011" when "0100",
                "1011011" when "0101", -- 5
                "1011111" when "0110", -- 6
                "1110000" when "0111", -- 7
                "1111111" when "1000", -- 8
                "1110011" when "1001", -- 9
                "1110111" when "1010", -- A
                "0011111" when "1011", -- b
                "1001110" when "1100", -- C
                "0111101" when "1101", -- d
                "1001111" when "1110", -- E
                "1000111" when "1111", -- F
                "1111111" when others;
--------------------------------------------------------------------------------------------
   with snibb4 select
   sout7seg4 <= "1111110" when "0000", -- 0 <-- Estos valores sirven para los que tienen cátodo común, en mi caso mi placa de gallos tiene cátodo común
                "0110000" when "0001", -- 1 <-- Para los que tienen anodo común cambiar los 1 por 0 y viceversa 
				"1101101" when "0010", -- 2
                "1111001" when "0011", -- 3
                "0110011" when "0100",
                "1011011" when "0101", -- 5
                "1011111" when "0110", -- 6
                "1110000" when "0111", -- 7
                "1111111" when "1000", -- 8
                "1110011" when "1001", -- 9
                "1110111" when "1010", -- A
                "0011111" when "1011", -- b
                "1001110" when "1100", -- C
                "0111101" when "1101", -- d
                "1001111" when "1110", -- E
                "1000111" when "1111", -- F
                "1111111" when others;
--------------------------------------------------------------------------------------------
   with snibb5 select
   sout7seg5 <= "1111110" when "0000", -- 0 <-- Estos valores sirven para los que tienen cátodo común, en mi caso mi placa de gallos tiene cátodo común
                "0110000" when "0001", -- 1 <-- Para los que tienen anodo común cambiar los 1 por 0 y viceversa 
				"1101101" when "0010", -- 2
                "1111001" when "0011", -- 3
                "0110011" when "0100",
                "1011011" when "0101", -- 5
                "1011111" when "0110", -- 6
                "1110000" when "0111", -- 7
                "1111111" when "1000", -- 8
                "1110011" when "1001", -- 9
                "1110111" when "1010", -- A
                "0011111" when "1011", -- b
                "1001110" when "1100", -- C
                "0111101" when "1101", -- d
                "1001111" when "1110", -- E
                "1000111" when "1111", -- F
                "1111111" when others;
--------------------------------------------------------------------------------------------
   with snibb6 select
   sout7seg6 <= "1111110" when "0000", -- 0 <-- Estos valores sirven para los que tienen cátodo común, en mi caso mi placa de gallos tiene cátodo común
                "0110000" when "0001", -- 1 <-- Para los que tienen anodo común cambiar los 1 por 0 y viceversa 
				"1101101" when "0010", -- 2
                "1111001" when "0011", -- 3
                "0110011" when "0100",
                "1011011" when "0101", -- 5
                "1011111" when "0110", -- 6
                "1110000" when "0111", -- 7
                "1111111" when "1000", -- 8
                "1110011" when "1001", -- 9
                "1110111" when "1010", -- A
                "0011111" when "1011", -- b
                "1001110" when "1100", -- C
                "0111101" when "1101", -- d
                "1001111" when "1110", -- E
                "1000111" when "1111", -- F
                "1111111" when others;
--------------------------------------------------------------------------------------------

   with snibb7 select
   sout7seg7 <= "1111110" when "0000", -- 0 <-- Estos valores sirven para los que tienen cátodo común, en mi caso mi placa de gallos tiene cátodo común
                "0110000" when "0001", -- 1 <-- Para los que tienen anodo común cambiar los 1 por 0 y viceversa 
				"1101101" when "0010", -- 2
                "1111001" when "0011", -- 3
                "0110011" when "0100", -- 4
                "1011011" when "0101", -- 5
                "1011111" when "0110", -- 6
                "1110000" when "0111", -- 7
                "1111111" when "1000", -- 8
                "1110011" when "1001", -- 9
                "1110111" when "1010", -- A
                "0011111" when "1011", -- b
                "1001110" when "1100", -- C
                "0111101" when "1101", -- d
                "1001111" when "1110", -- E
                "1000111" when "1111", -- F
                "1111111" when others;
--------------------------------------------------------------------------------------------
  
  with incontcr7 select
    out7seg <= sout7seg0 when "0001", -- display de unidades 
	           sout7seg1 when "0010", -- display de hexenas
	           sout7seg2 when "0100", -- 
	           sout7seg3 when "1000",
	"1111111" when others;


end coder7seg0;