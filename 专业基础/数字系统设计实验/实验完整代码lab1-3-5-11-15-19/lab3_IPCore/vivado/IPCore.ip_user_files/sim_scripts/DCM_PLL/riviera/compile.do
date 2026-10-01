transcript off
onbreak {quit -force}
onerror {quit -force}
transcript on

vlib work
vmap -link {D:/constructing_projects/FPGA_projects/FPGA_design_course/lab3_IPCore/vivado/IPCore.cache/compile_simlib/riviera}
vlib riviera/xpm
vlib riviera/xil_defaultlib

vlog -work xpm  -incr "+incdir+../../../ipstatic" -l xpm -l xil_defaultlib \
"D:/program/Xilinx/Vivado/2023.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \

vcom -work xpm -93  -incr \
"D:/program/Xilinx/Vivado/2023.1/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work xil_defaultlib  -incr -v2k5 "+incdir+../../../ipstatic" -l xpm -l xil_defaultlib \
"../../../../IPCore.gen/sources_1/ip/DCM_PLL/DCM_PLL_clk_wiz.v" \
"../../../../IPCore.gen/sources_1/ip/DCM_PLL/DCM_PLL.v" \

vlog -work xil_defaultlib \
"glbl.v"

