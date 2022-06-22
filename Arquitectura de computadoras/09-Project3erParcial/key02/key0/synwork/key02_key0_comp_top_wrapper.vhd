--
-- Synopsys
-- Vhdl wrapper for top level design, written on Sat May 28 22:56:24 2022
--
library ieee;
use ieee.std_logic_1164.all;
library work;
use work.packagekey0200.all;

entity wrapper_for_key02 is
   port (
      clk0 : in std_logic;
      cdiv0 : in std_logic_vector(4 downto 0);
      en0 : in std_logic;
      outr0 : in std_logic_vector(3 downto 0);
      inkey0 : in std_logic_vector(3 downto 0);
      out32lc0 : in std_logic_vector(31 downto 0);
      outr70 : in std_logic_vector(3 downto 0);
      out7seg0 : out std_logic_vector(6 downto 0)
   );
end wrapper_for_key02;

architecture key0 of wrapper_for_key02 is

component key02
 port (
   clk0 : inout std_logic;
   cdiv0 : in std_logic_vector (4 downto 0);
   en0 : in std_logic;
   outr0 : inout std_logic_vector (3 downto 0);
   inkey0 : in std_logic_vector (3 downto 0);
   out32lc0 : inout std_logic_vector (31 downto 0);
   outr70 : inout std_logic_vector (3 downto 0);
   out7seg0 : out std_logic_vector (6 downto 0)
 );
end component;

signal tmp_clk0 : std_logic;
signal tmp_cdiv0 : std_logic_vector (4 downto 0);
signal tmp_en0 : std_logic;
signal tmp_outr0 : std_logic_vector (3 downto 0);
signal tmp_inkey0 : std_logic_vector (3 downto 0);
signal tmp_out32lc0 : std_logic_vector (31 downto 0);
signal tmp_outr70 : std_logic_vector (3 downto 0);
signal tmp_out7seg0 : std_logic_vector (6 downto 0);

begin

tmp_clk0 <= clk0;

tmp_cdiv0 <= cdiv0;

tmp_en0 <= en0;

tmp_outr0 <= outr0;

tmp_inkey0 <= inkey0;

tmp_out32lc0 <= out32lc0;

tmp_outr70 <= outr70;

out7seg0 <= tmp_out7seg0;



u1:   key02 port map (
		clk0 => tmp_clk0,
		cdiv0 => tmp_cdiv0,
		en0 => tmp_en0,
		outr0 => tmp_outr0,
		inkey0 => tmp_inkey0,
		out32lc0 => tmp_out32lc0,
		outr70 => tmp_outr70,
		out7seg0 => tmp_out7seg0
       );
end key0;
