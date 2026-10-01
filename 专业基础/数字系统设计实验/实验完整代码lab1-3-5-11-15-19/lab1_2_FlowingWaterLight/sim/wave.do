onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /FlowingWateLight_tb/FlowingWateLight_inst/div_inst/clk
add wave -noupdate /FlowingWateLight_tb/FlowingWateLight_inst/div_inst/en
add wave -noupdate -radix octal /FlowingWateLight_tb/FlowingWateLight_inst/div_inst/r
add wave -noupdate -radix binary /FlowingWateLight_tb/FlowingWateLight_inst/div_inst/co
add wave -noupdate -radix binary /FlowingWateLight_tb/FlowingWateLight_inst/div_inst/q
add wave -noupdate /FlowingWateLight_tb/clk
add wave -noupdate /FlowingWateLight_tb/reset
add wave -noupdate /FlowingWateLight_tb/direction
add wave -noupdate /FlowingWateLight_tb/led
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {0 ps} 0}
quietly wave cursor active 0
configure wave -namecolwidth 370
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ps
update
WaveRestoreZoom {33145 ps} {575993 ps}
