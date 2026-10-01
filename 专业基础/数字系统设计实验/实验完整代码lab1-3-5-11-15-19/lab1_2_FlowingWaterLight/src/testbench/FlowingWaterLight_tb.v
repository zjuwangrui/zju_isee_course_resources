`timescale 1ns/100ps
//////////////////////////////////////////////////////////////////////////////////
// Company:zju 
// Engineer:qmj 
//////////////////////////////////////////////////////////////////////////////////
module FlowingWaterLight_tb;
parameter DELY=10;
reg	clk, reset, direction;
wire [7:0] 	led;
//顶层模块实例，传递sim参数1
FlowingWaterLight #(.sim(1)) FlowingWateLight_inst(
    .clk(clk),.reset(reset),.direction(direction),.led (led));
//产生时钟波形	
initial begin clk = 0;	forever #5 clk = ~clk;end
///产生reset�?direction波形
initial 
  begin  
   reset = 0; direction = 1;
   #(DELY/2+1)reset = 1;
   #(DELY)reset = 0;
   #(DELY*80) direction = 0;
   #(DELY*90)$stop;
end
endmodule