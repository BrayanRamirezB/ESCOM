#-- Lattice Semiconductor Corporation Ltd.
#-- Synplify OEM project file

#device options
set_option -technology MACHXO2
set_option -part LCMXO2_7000HE
set_option -package TG144C
set_option -speed_grade -5

#compilation/mapping options
set_option -symbolic_fsm_compiler true
set_option -resource_sharing true

#use verilog 2001 standard option
set_option -vlog_std v2001

#map options
set_option -frequency 100
set_option -maxfan 1000
set_option -auto_constrain_io 0
set_option -disable_io_insertion false
set_option -retiming false; set_option -pipe true
set_option -force_gsr false
set_option -compiler_compatible 0
set_option -dup false

set_option -default_enum_encoding default

#simulation options


#timing analysis options



#automatic place and route (vendor) options
set_option -write_apr_constraint 1

#synplifyPro options
set_option -fix_gated_and_generated_clocks 1
set_option -update_models_cp 0
set_option -resolve_multiple_driver 0


set_option -seqshift_no_replicate 0

#-- add_file options
add_file -vhdl {C:/lscc/diamond/3.12/cae_library/synthesis/vhdl/machxo2.vhd}
add_file -vhdl -lib "work" {C:/Users/Mau/Documents/Arqui/practicas/TercelParcial/05-pipeline00/pipeline0/source/div00.vhd}
add_file -vhdl -lib "work" {C:/Users/Mau/Documents/Arqui/practicas/TercelParcial/05-pipeline00/pipeline0/source/osc00.vhd}
add_file -vhdl -lib "work" {C:/Users/Mau/Documents/Arqui/practicas/TercelParcial/05-pipeline00/pipeline0/source/oscint00.vhd}
add_file -vhdl -lib "work" {C:/Users/Mau/Documents/Arqui/practicas/TercelParcial/05-pipeline00/pipeline0/source/packageOsc00.vhd}
add_file -vhdl -lib "work" {C:/Users/Mau/Documents/Arqui/practicas/TercelParcial/05-pipeline00/pc00.vhdl}
add_file -vhdl -lib "work" {C:/Users/Mau/Documents/Arqui/practicas/TercelParcial/05-pipeline00/memEBR00.vhd}
add_file -vhdl -lib "work" {C:/Users/Mau/Documents/Arqui/practicas/TercelParcial/05-pipeline00/fi00.vhdl}
add_file -vhdl -lib "work" {C:/Users/Mau/Documents/Arqui/practicas/TercelParcial/05-pipeline00/di00.vhdl}
add_file -vhdl -lib "work" {C:/Users/Mau/Documents/Arqui/practicas/TercelParcial/05-pipeline00/co00.vhdl}
add_file -vhdl -lib "work" {C:/Users/Mau/Documents/Arqui/practicas/TercelParcial/05-pipeline00/fo00.vhdl}
add_file -vhdl -lib "work" {C:/Users/Mau/Documents/Arqui/practicas/TercelParcial/05-pipeline00/eo00.vhdl}
add_file -vhdl -lib "work" {C:/Users/Mau/Documents/Arqui/practicas/TercelParcial/05-pipeline00/wr00.vhdl}
add_file -vhdl -lib "work" {C:/Users/Mau/Documents/Arqui/practicas/TercelParcial/05-pipeline00/fsmpipe02.vhdl}
add_file -vhdl -lib "work" {C:/Users/Mau/Documents/Arqui/practicas/TercelParcial/05-pipeline00/packagepipeline00.vhdl}
add_file -vhdl -lib "work" {C:/Users/Mau/Documents/Arqui/practicas/TercelParcial/05-pipeline00/pipeline00.vhdl}

#-- top module name
set_option -top_module pipeline00

#-- set result format/file last
project -result_file {C:/Users/Mau/Documents/Arqui/practicas/TercelParcial/05-pipeline00/pipeline0/pipeline00_pipeline0.edi}

#-- error message log file
project -log_file {pipeline00_pipeline0.srf}

#-- set any command lines input by customer


#-- run Synplify with 'arrange HDL file'
project -run hdl_info_gen -fileorder
project -run
