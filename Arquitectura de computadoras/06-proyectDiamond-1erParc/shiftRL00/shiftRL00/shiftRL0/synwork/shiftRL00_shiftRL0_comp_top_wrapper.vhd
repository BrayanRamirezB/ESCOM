--
-- Synopsys
-- Vhdl wrapper for top level design, written on Thu Oct 21 15:20:29 2021
--
library ieee;
use ieee.std_logic_1164.all;
library work;
use work.packageshiftrl00.all;

entity wrapper_for_shiftRL is
   port (
      clk0 : in std_logic;
      cdiv0 : in std_logic_vector(4 downto 0);
      en0 : in std_logic_vector(7 downto 0);
      control0 : in std_logic_vector(2 downto 0);
      in0 : in std_logic_vector(7 downto 0);
      out0 : out std_logic_vector(7 downto 0)
   );
end wrapper_for_shiftRL;

architecture shiftrl0 of wrapper_for_shiftRL is

component shiftRL
 port (
   clk0 : inout std_logic;
   cdiv0 : in std_logic_vector (4 downto 0);
   en0 : in std_logic_vector (7 downto 0);
   control0 : in std_logic_vector (2 downto 0);
   in0 : in std_logic_vector (7 downto 0);
   out0 : out std_logic_vector (7 downto 0)
 );
end component;

signal tmp_clk0 : std_logic;
signal tmp_cdiv0 : std_logic_vector (4 downto 0);
signal tmp_en0 : std_logic_vector (7 downto 0);
signal tmp_control0 : std_logic_vector (2 downto 0);
signal tmp_in0 : std_logic_vector (7 downto 0);
signal tmp_out0 : std_logic_vector (7 downto 0);

begin

tmp_clk0 <= clk0;

tmp_cdiv0 <= cdiv0;

tmp_en0 <= en0;

tmp_control0 <= control0;

tmp_in0 <= in0;

out0 <= tmp_out0;



u1:   shiftRL port map (
		clk0 => tmp_clk0,
		cdiv0 => tmp_cdiv0,
		en0 => tmp_en0,
		control0 => tmp_control0,
		in0 => tmp_in0,
		out0 => tmp_out0
       );
end shiftrl0;
