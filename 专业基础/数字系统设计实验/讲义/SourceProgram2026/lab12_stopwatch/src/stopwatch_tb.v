`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: zju
// Engineer:qmj

////////////////////////////////////////////////////////////////////////////////

module stopwatch_tb;
   parameter DELY=10; 
	// Inputs
	reg clk;
	reg ButtonIn;
	reg reset;
	// Outputs
	wire a;
	wire b;
	wire c;
	wire d;
	wire e;
	wire f;
	wire g;
	wire dp;
	wire [3:0] pos;
	// Instantiate the Unit Under Test (UUT)
	stopwatch #(.sim(1'b1)) uut (
		.clk(clk), 
		.ButtonIn(ButtonIn), 
		.a(a), 
		.b(b), 
		.c(c), 
		.d(d), 
		.e(e), 
		.f(f), 
		.g(g), 
		.dp(dp), 
		.pos(pos), 
		.reset(reset)	);

	always #(DELY/2) clk=~clk;
	initial begin
		// Initialize Inputs
		clk = 0;
		ButtonIn = 0;
		reset = 0;
		#(DELY*0.5+1) reset = 1;
		#(DELY)       reset = 0;
		//start
		#(DELY*20)  ButtonIn = 1;
		#(DELY*500) ButtonIn = 0;
                #(DELY*15000)  ButtonIn = 1;//stop
		#(DELY*500) ButtonIn = 0;
		#(DELY*1000) ButtonIn = 1;//reset
		#(DELY*500) ButtonIn = 0;
		#(DELY*100) $stop;
	end
	reg[6:0] num; 
    always @(*)
       case({a,b,c,d,e,f,g})
           7'b0000001:num=48;//"0" ASCII Code 
           7'b1001111:num=49;//"1" ASCII Code 
           7'b0010010:num=50;
           7'b0000110:num=51;
           7'b1001100:num=52;
           7'b0100100:num=53;
           7'b0100000:num=54;
           7'b0001111:num=55;
           7'b0000000:num=56;
           7'b0000100:num=57;//"9" ASCII Code 
           default:num=63;		 //"?" ASCII Code
       endcase
       wire[6:0] num0,num1, num2,num3;
       
       assign    num0=~pos[0]? num:7'd0;
       assign    num1=~pos[1]? num:7'd0;
       assign    num2=~pos[2]? num:7'd0;
       assign    num3=~pos[3]? num:7'd0;  
       
  	
endmodule

