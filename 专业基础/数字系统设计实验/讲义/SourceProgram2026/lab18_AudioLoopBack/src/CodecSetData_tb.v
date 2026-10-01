`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company:zju
// Engineer: qmj
////////////////////////////////////////////////////////////////////////////////

module CodecSetData_tb;

	// Inputs
	reg clk;
	reg reset;
	reg NewCom;

	// Outputs
	wire [7:0] SubAddrL;
	wire [7:0] data;
	wire write;

	// Instantiate the Unit Under Test (UUT)
	CodecSetData uut (
		.clk(clk), 
		.reset(reset), 
		.NewCom(NewCom), 
		.SubAddrL(SubAddrL), 
		.data(data), 
		.write(write)
	);
   initial begin	clk = 0;forever #50 clk=~clk;end
	initial begin
		// Initialize Inputs
		reset = 0;
		NewCom = 0;

		// Wait 100 ns for global reset to finish
		#150 reset = 1;
      #100 reset = 0; 
      repeat (30)
		begin
      #800 NewCom=1;
      #100 NewCom=0;
      end
     #500 $stop;
   end	  
		// Add stimulus here


      
endmodule

