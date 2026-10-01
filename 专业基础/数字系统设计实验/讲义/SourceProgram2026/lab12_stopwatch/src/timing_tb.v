`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: zju
// Engineer:qmj
////////////////////////////////////////////////////////////////////////////////

module timing_tb;

	// Inputs
	reg clk;
	reg en;
    reg r;
	// Outputs
	wire [3:0] q0;
        wire [7:0] qs;
	wire [3:0] qm;	
	// Instantiate the Unit Under Test (UUT)
	 timing  uut (
		.clk(clk),
        .r(r), 
		.en(en), 
		
        .q0(q0),
		.qs(qs),
		.qm(qm));

	//clk
   always #50 clk=~clk;
	
	//  clr
	initial 
	 begin
	   clk = 0;r=0;en = 0;
       #(51) r=1;
  	   #(100)r=0 ;
       repeat (620)  begin 
	     #(100*3)  en=1;
	     # 100  en=0; end
         #1000 $stop;
  end
      
endmodule

