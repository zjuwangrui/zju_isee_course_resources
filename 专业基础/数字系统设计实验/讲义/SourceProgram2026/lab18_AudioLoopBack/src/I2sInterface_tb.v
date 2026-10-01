`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
////////////////////////////////////////////////////////////////////////////////

module IIS_tb;

	// Inputs
	reg clk;
	reg reset;
	
	reg ADC_SDATA;
	reg [23:0] LeftPlayData;
	reg [23:0] RightPlayData;

	// Outputs
	wire BCLK;
	wire LRCLK;
	wire DAC_SDATA;
	wire [23:0] LeftRecData;
	wire [23:0] RightRecData;
	wire NewFrame;
   wire MCLK;
	// Instantiate the Unit Under Test (UUT)
	I2sInterFace uut (
		.clk(clk), 
		.reset(reset), 
		.BCLK(BCLK), 
		.LRCLK(LRCLK), 
		.MCLK(MCLK), 
		.ADC_SDATA(ADC_SDATA), 
		.DAC_SDATA(DAC_SDATA), 
		.LeftPlayData(LeftPlayData), 
		.RightPlayData(RightPlayData), 
		.LeftRecData(LeftRecData), 
		.RightRecData(RightRecData), 
		.NewFrame(NewFrame)
	);
	initial begin clk = 0;forever #50 clk=~clk; end
	initial begin
		// Initialize Inputs
		reset = 0;
		ADC_SDATA = 0;
		LeftPlayData = 0;
		RightPlayData = 0;

		// Wait 100 ns for global reset to finish
		#100 reset = 1;
        #100 reset = 0;
		LeftPlayData = 24'ha5_a5a5;
		RightPlayData =24'h5a_5a5a;
		#(100*2200) $stop;
		// Add stimulus here

	end
    always @(*) 
	 ADC_SDATA=DAC_SDATA;
endmodule

