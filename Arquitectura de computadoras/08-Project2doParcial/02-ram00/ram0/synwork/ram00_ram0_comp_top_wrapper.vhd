--
-- Synopsys
-- Vhdl wrapper for top level design, written on Wed May 11 21:06:32 2022
--
library ieee;
use ieee.std_logic_1164.all;
library work;
use work.packageram00.all;

entity wrapper_for_ram00 is
   port (
      clk0 : in std_logic;
      cdiv0 : in std_logic_vector(4 downto 0);
      re0 : in std_logic;
      rw0 : in std_logic;
      inkey0 : in std_logic_vector(3 downto 0);
      contW0 : in std_logic_vector(5 downto 0);
      contR0 : in std_logic_vector(5 downto 0);
      outword0 : out std_logic_vector(6 downto 0);
      outr0 : in std_logic_vector(3 downto 0);
      outtransist0 : out std_logic_vector(3 downto 0)
   );
end wrapper_for_ram00;

architecture ram0 of wrapper_for_ram00 is

component ram00
 port (
   clk0 : inout std_logic;
   cdiv0 : in std_logic_vector (4 downto 0);
   re0 : in std_logic;
   rw0 : in std_logic;
   inkey0 : in std_logic_vector (3 downto 0);
   contW0 : inout std_logic_vector (5 downto 0);
   contR0 : inout std_logic_vector (5 downto 0);
   outword0 : out std_logic_vector (6 downto 0);
   outr0 : inout std_logic_vector (3 downto 0);
   outtransist0 : out std_logic_vector (3 downto 0)
 );
end component;

signal tmp_clk0 : std_logic;
signal tmp_cdiv0 : std_logic_vector (4 downto 0);
signal tmp_re0 : std_logic;
signal tmp_rw0 : std_logic;
signal tmp_inkey0 : std_logic_vector (3 downto 0);
signal tmp_contW0 : std_logic_vector (5 downto 0);
signal tmp_contR0 : std_logic_vector (5 downto 0);
signal tmp_outword0 : std_logic_vector (6 downto 0);
signal tmp_outr0 : std_logic_vector (3 downto 0);
signal tmp_outtransist0 : std_logic_vector (3 downto 0);

begin

tmp_clk0 <= clk0;

tmp_cdiv0 <= cdiv0;

tmp_re0 <= re0;

tmp_rw0 <= rw0;

tmp_inkey0 <= inkey0;

tmp_contW0 <= contW0;

tmp_contR0 <= contR0;

outword0 <= tmp_outword0;

tmp_outr0 <= outr0;

outtransist0 <= tmp_outtransist0;



u1:   ram00 port map (
		clk0 => tmp_clk0,
		cdiv0 => tmp_cdiv0,
		re0 => tmp_re0,
		rw0 => tmp_rw0,
		inkey0 => tmp_inkey0,
		contW0 => tmp_contW0,
		contR0 => tmp_contR0,
		outword0 => tmp_outword0,
		outr0 => tmp_outr0,
		outtransist0 => tmp_outtransist0
       );
end ram0;
