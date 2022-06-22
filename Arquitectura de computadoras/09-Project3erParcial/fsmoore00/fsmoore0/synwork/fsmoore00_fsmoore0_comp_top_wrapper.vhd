--
-- Synopsys
-- Vhdl wrapper for top level design, written on Wed Jun  1 22:45:20 2022
--
library ieee;
use ieee.std_logic_1164.all;
library work;
use work.packagefsm00.all;

entity wrapper_for_fsmoore00 is
   port (
      clk0 : in std_logic;
      cdiv0 : in std_logic_vector(4 downto 0);
      en0 : in std_logic;
      address0 : in std_logic_vector(4 downto 0);
      inxfsm0 : in std_logic_vector(5 downto 0);
      outfsm0 : out std_logic_vector(2 downto 0)
   );
end wrapper_for_fsmoore00;

architecture fsmoore0 of wrapper_for_fsmoore00 is

component fsmoore00
 port (
   clk0 : inout std_logic;
   cdiv0 : in std_logic_vector (4 downto 0);
   en0 : in std_logic;
   address0 : inout std_logic_vector (4 downto 0);
   inxfsm0 : inout std_logic_vector (5 downto 0);
   outfsm0 : out std_logic_vector (2 downto 0)
 );
end component;

signal tmp_clk0 : std_logic;
signal tmp_cdiv0 : std_logic_vector (4 downto 0);
signal tmp_en0 : std_logic;
signal tmp_address0 : std_logic_vector (4 downto 0);
signal tmp_inxfsm0 : std_logic_vector (5 downto 0);
signal tmp_outfsm0 : std_logic_vector (2 downto 0);

begin

tmp_clk0 <= clk0;

tmp_cdiv0 <= cdiv0;

tmp_en0 <= en0;

tmp_address0 <= address0;

tmp_inxfsm0 <= inxfsm0;

outfsm0 <= tmp_outfsm0;



u1:   fsmoore00 port map (
		clk0 => tmp_clk0,
		cdiv0 => tmp_cdiv0,
		en0 => tmp_en0,
		address0 => tmp_address0,
		inxfsm0 => tmp_inxfsm0,
		outfsm0 => tmp_outfsm0
       );
end fsmoore0;
