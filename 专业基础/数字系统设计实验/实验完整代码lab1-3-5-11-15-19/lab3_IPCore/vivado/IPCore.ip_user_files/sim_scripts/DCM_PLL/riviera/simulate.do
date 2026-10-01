transcript off
onbreak {quit -force}
onerror {quit -force}
transcript on

asim +access +r +m+DCM_PLL  -L xpm -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip -O5 xil_defaultlib.DCM_PLL xil_defaultlib.glbl

do {DCM_PLL.udo}

run 1000ns

endsim

quit -force
