library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
use packageadder8bit00.all;

entity adder8bit00 is
	port(
		Ai: in std_logic_vector(7 downto 0);
		Bi: in std_logic_vector(7 downto 0);
		SL: in std_logic;
		So: out std_logic_vector(7 downto 0);
		LED: out std_logic);
end adder8bit00;
architecture adder8bit0 of adder8bit00 is
signal SB, SC, SA: std_logic_vector(7 downto 0);
signal Sx: std_logic;
begin

	A00: xor00 port map(Ax => SL,
						Bx => Bi(0),
						Yx => SB(0));
	
	A01: xor00 port map(Ax => SL,
						Bx => Bi(1),
						Yx => SB(1));
	
	A02: xor00 port map(Ax => SL,
						Bx => Bi(2),
						Yx => SB(2));
	
	A03: xor00 port map(Ax => SL,
						Bx => Bi(3),
						Yx => SB(3));
	
	A04: xor00 port map(Ax => SL,
						Bx => Bi(4),
						Yx => SB(4));
	
	A05: xor00 port map(Ax => SL,
						Bx => Bi(5),
						Yx => SB(5));
	
	A06: xor00 port map(Ax => SL,
						Bx => Bi(6),
						Yx => SB(6));
	
	A07: xor00 port map(Ax => SL,
						Bx => Bi(7),
						Yx => SB(7));
	
	A08: fa00 port map(C00 => SL,
						A00 => Ai(0),
						B00 => SB(0),
						C01 => SC(0),
						S00 => SA(0));
	
	A09: fa00 port map(C00 => SC(0),
						A00 => Ai(1),
						B00 => SB(1),
						C01 => SC(1),
						S00 => SA(1));
	
	A10: fa00 port map(C00 => SC(1),
						A00 => Ai(2),
						B00 => SB(2),
						C01 => SC(2),
						S00 => SA(2));
	
	A11: fa00 port map(C00 => SC(2),
						A00 => Ai(3),
						B00 => SB(3),
						C01 => SC(3),
						S00 => SA(3));
	
	A12: fa00 port map(C00 => SC(3),
						A00 => Ai(4),
						B00 => SB(4),
						C01 => SC(4),
						S00 => SA(4));
	
	A13: fa00 port map(C00 => SC(4),
						A00 => Ai(5),
						B00 => SB(5),
						C01 => SC(5),
						S00 => SA(5));
	
	A14: fa00 port map(C00 => SC(5),
						A00 => Ai(6),
						B00 => SB(6),
						C01 => SC(6),
						S00 => SA(6));
	
	A15: fa00 port map(C00 => SC(6),
						A00 => Ai(7),
						B00 => SB(7),
						C01 => SC(7),
						S00 => SA(7));
	
	A16: and00 port map(Aa => Sx,
						Ba => SA(0),
						Ya => So(0));
	
	A17: and00 port map(Aa => Sx,
						Ba => SA(1),
						Ya => So(1));
	
	A18: and00 port map(Aa => Sx,
						Ba => SA(2),
						Ya => So(2));
	
	A19: and00 port map(Aa => Sx,
						Ba => SA(3),
						Ya => So(3));
	
	A20: and00 port map(Aa => Sx,
						Ba => SA(4),
						Ya => So(4));
	
	A21: and00 port map(Aa => Sx,
						Ba => SA(5),
						Ya => So(5));
	
	A22: and00 port map(Aa => Sx,
						Ba => SA(6),
						Ya => So(6));
	
	A23: and00 port map(Aa => Sx,
						Ba => SA(7),
						Ya => So(7));
	
	A24: xnor00 port map(Axn => SC(6),
						Bxn => SC(7),
						Yxn => Sx);
	
	A25: xor00 port map(Ax => SC(6),
						Bx => SC(7),
						Yx => LED);

end adder8bit0;