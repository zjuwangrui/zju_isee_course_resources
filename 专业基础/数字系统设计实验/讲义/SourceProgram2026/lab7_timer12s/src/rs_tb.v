`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: zju
// Engineer:qmj
//
// Create Date:   15:24:57 07/31/2012
// Design Name:   rsff
// Module Name:   E:/solution/lab30/DESIGN1/src/rs_tb.v
// Project Name:  TimerTop
//
////////////////////////////////////////////////////////////////////////////////

module rs_tb_v;

	// Inputs
	reg clk;
	reg r;
	reg s;

	// Outputs
	wire q;

	// Instantiate the Unit Under Test (UUT)
	rsff  rsffInst(
		.clk(clk), 
		.r(r), 
		.s(s), 
		.q(q)
	);
   //clk
	always #5 clk=~clk;
	initial begin
		// Initialize Inputs
		clk = 0;
		r = 0;
		s = 0;
		#6 	r = 1;
		#10 	r = 0;	s = 1;
		#20     s = 0;
                #10     r = 1;
                #10     r = 0;
		#20     $stop;
        
		

	end
      
endmodule

