--
-- Synopsys
-- Vhdl wrapper for top level design, written on Sat Mar 19 23:05:31 2022
--
library ieee;
use ieee.std_logic_1164.all;
library work;
use work.packageshiftrrl00.all;

entity wrapper_for_shiftrRL00 is
   port (
      clk0 : in std_logic;
      cdiv0 : in std_logic_vector(4 downto 0);
      en0 : in std_logic;
      in0 : in std_logic_vector(7 downto 0);
      out0 : in std_logic_vector(7 downto 0)
   );
end wrapper_for_shiftrRL00;

architecture shiftrrl0 of wrapper_for_shiftrRL00 is

component shiftrRL00
 port (
   clk0 : inout std_logic;
   cdiv0 : in std_logic_vector (4 downto 0);
   en0 : in std_logic;
   in0 : in std_logic_vector (7 downto 0);
   out0 : inout std_logic_vector (7 downto 0)
 );
end component;

signal tmp_clk0 : std_logic;
signal tmp_cdiv0 : std_logic_vector (4 downto 0);
signal tmp_en0 : std_logic;
signal tmp_in0 : std_logic_vector (7 downto 0);
signal tmp_out0 : std_logic_vector (7 downto 0);

begin

tmp_clk0 <= clk0;

tmp_cdiv0 <= cdiv0;

tmp_en0 <= en0;

tmp_in0 <= in0;

tmp_out0 <= out0;



u1:   shiftrRL00 port map (
		clk0 => tmp_clk0,
		cdiv0 => tmp_cdiv0,
		en0 => tmp_en0,
		in0 => tmp_in0,
		out0 => tmp_out0
       );
end shiftrrl0;
