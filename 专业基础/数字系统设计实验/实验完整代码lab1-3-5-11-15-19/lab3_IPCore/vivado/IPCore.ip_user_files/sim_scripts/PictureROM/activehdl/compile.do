transcript off
onbreak {quit -force}
onerror {quit -force}
transcript on

vlib work
vmap -link {D:/constructing_projects/FPGA_projects/FPGA_design_course/lab3_IPCore/vivado/IPCore.cache/compile_simlib/activehdl}
vlib activehdl/dist_mem_gen_v8_0_13
vlib activehdl/xil_defaultlib

vlog -work dist_mem_gen_v8_0_13  -v2k5 -l dist_mem_gen_v8_0_13 -l xil_defaultlib \
"../../../ipstatic/simulation/dist_mem_gen_v8_0.v" \

vlog -work xil_defaultlib  -v2k5 -l dist_mem_gen_v8_0_13 -l xil_defaultlib \
"../../../../IPCore.gen/sources_1/ip/PictureROM/sim/PictureROM.v" \


vlog -work xil_defaultlib \
"glbl.v"

