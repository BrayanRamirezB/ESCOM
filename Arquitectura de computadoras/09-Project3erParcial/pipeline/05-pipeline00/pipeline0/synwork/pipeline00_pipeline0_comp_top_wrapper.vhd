--
-- Synopsys
-- Vhdl wrapper for top level design, written on Thu Jun  9 21:21:54 2022
--
library ieee;
use ieee.std_logic_1164.all;
library work;
use work.packagepipeline00.all;

entity wrapper_for_pipeline00 is
   port (
      clk0 : in std_logic;
      cdiv0 : in std_logic_vector(4 downto 0);
      en0 : in std_logic;
      in0 : in std_logic_vector(7 downto 0);
      out0 : out std_logic_vector(7 downto 0);
      outFlag00 : in std_logic;
      outFlag10 : in std_logic;
      outFlag20 : in std_logic;
      outFlag30 : in std_logic;
      outFlag40 : in std_logic;
      outFlag50 : in std_logic;
      outr00 : out std_logic;
      outr10 : out std_logic;
      outr20 : out std_logic;
      outr30 : out std_logic;
      outr40 : out std_logic;
      outr50 : out std_logic;
      statezz0 : in std_logic_vector(2 downto 0)
   );
end wrapper_for_pipeline00;

architecture pipeline0 of wrapper_for_pipeline00 is

component pipeline00
 port (
   clk0 : inout std_logic;
   cdiv0 : in std_logic_vector (4 downto 0);
   en0 : in std_logic;
   in0 : in std_logic_vector (7 downto 0);
   out0 : out std_logic_vector (7 downto 0);
   outFlag00 : inout std_logic;
   outFlag10 : inout std_logic;
   outFlag20 : inout std_logic;
   outFlag30 : inout std_logic;
   outFlag40 : inout std_logic;
   outFlag50 : inout std_logic;
   outr00 : out std_logic;
   outr10 : out std_logic;
   outr20 : out std_logic;
   outr30 : out std_logic;
   outr40 : out std_logic;
   outr50 : out std_logic;
   statezz0 : inout std_logic_vector (2 downto 0)
 );
end component;

signal tmp_clk0 : std_logic;
signal tmp_cdiv0 : std_logic_vector (4 downto 0);
signal tmp_en0 : std_logic;
signal tmp_in0 : std_logic_vector (7 downto 0);
signal tmp_out0 : std_logic_vector (7 downto 0);
signal tmp_outFlag00 : std_logic;
signal tmp_outFlag10 : std_logic;
signal tmp_outFlag20 : std_logic;
signal tmp_outFlag30 : std_logic;
signal tmp_outFlag40 : std_logic;
signal tmp_outFlag50 : std_logic;
signal tmp_outr00 : std_logic;
signal tmp_outr10 : std_logic;
signal tmp_outr20 : std_logic;
signal tmp_outr30 : std_logic;
signal tmp_outr40 : std_logic;
signal tmp_outr50 : std_logic;
signal tmp_statezz0 : std_logic_vector (2 downto 0);

begin

tmp_clk0 <= clk0;

tmp_cdiv0 <= cdiv0;

tmp_en0 <= en0;

tmp_in0 <= in0;

out0 <= tmp_out0;

tmp_outFlag00 <= outFlag00;

tmp_outFlag10 <= outFlag10;

tmp_outFlag20 <= outFlag20;

tmp_outFlag30 <= outFlag30;

tmp_outFlag40 <= outFlag40;

tmp_outFlag50 <= outFlag50;

outr00 <= tmp_outr00;

outr10 <= tmp_outr10;

outr20 <= tmp_outr20;

outr30 <= tmp_outr30;

outr40 <= tmp_outr40;

outr50 <= tmp_outr50;

tmp_statezz0 <= statezz0;



u1:   pipeline00 port map (
		clk0 => tmp_clk0,
		cdiv0 => tmp_cdiv0,
		en0 => tmp_en0,
		in0 => tmp_in0,
		out0 => tmp_out0,
		outFlag00 => tmp_outFlag00,
		outFlag10 => tmp_outFlag10,
		outFlag20 => tmp_outFlag20,
		outFlag30 => tmp_outFlag30,
		outFlag40 => tmp_outFlag40,
		outFlag50 => tmp_outFlag50,
		outr00 => tmp_outr00,
		outr10 => tmp_outr10,
		outr20 => tmp_outr20,
		outr30 => tmp_outr30,
		outr40 => tmp_outr40,
		outr50 => tmp_outr50,
		statezz0 => tmp_statezz0
       );
end pipeline0;
