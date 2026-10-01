`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: zju
// Engineer:qmj
//
// Create Date:   15:54:51 07/31/2012
// Design Name:   timer
// Module Name:   E:/solution/lab30/DESIGN1/ise/timer_tb.v
// Project Name:  TimerTop
//
// Verilog Test Fixture created by ISE for module: timer
////////////////////////////////////////////////////////////////////////////////

module timer_tb_v;

	// Inputs
	reg clk;
	reg r;
	reg en;

	// Outputs
	wire done;

	// Instantiate the Unit Under Test (UUT)
	timer  #(.n(12),.counter_bits(4)) uut(
		.clk(clk), 
		.r(r), 
		.en(en), 
		.done(done));
   //clk
   always #5 clk=~clk;
	
	//  r
	initial begin
	   clk = 0;
		r = 0;
		#16  r = 1;
		#10  r = 0; 	end
  	//  en
	initial begin
	   en = 0;
	   #5;
     repeat (16)  begin 
	     #(10*3)  en=1;
	     # 10  en=0; end
    
     #10 $stop;
 end
  
endmodule

