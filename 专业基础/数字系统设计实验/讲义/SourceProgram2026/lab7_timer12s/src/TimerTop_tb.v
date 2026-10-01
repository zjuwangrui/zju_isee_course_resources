`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: zju
// Engineer:qmj
//
// Create Date:   14:24:58 07/31/2012
// Design Name:   TimerTop
// Module Name:   E:/lab30/ise/TimerTop_tb.v
// Project Name:  TimerTop
// Verilog Test Fixture created by ISE for module: TimerTop
//
// Dependencies:

////////////////////////////////////////////////////////////////////////////////

module TimerTop_tb_v;

	// Inputs
	reg clk;
	reg reset;
	reg start;

	// Outputs
	wire LED1;
	wire LED0;

	// Instantiate the Unit Under Test (UUT)
	TimerTop #(.sim(1'b1)) uut (
		.clk(clk), 
		.reset(reset), 
		.start(start), 
		.LED1(LED1), 
		.LED0(LED0)	);
  //clk
	always #5 clk=~clk;
  // Inputs
	initial begin
		// Initialize Inputs
	        clk = 0;
	        reset = 0;
		start = 0;
		#6  reset = 1;
		#10 reset = 0;
		#200 start = 1;
		#20  start = 0;
		#4000 reset= 1;
		#20 reset = 0;
		#100 $stop;
        
		// Add stimulus here

	end
      
endmodule

