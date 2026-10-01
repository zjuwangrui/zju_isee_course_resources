`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: zju
// Engineer:qmj
//
// Create Date:   14:28:15 08/05/2012
// Design Name:   stopwatch
// Module Name:   E:/lab16_new_201208/ise/stopwatch_tb.v
// Project Name:  stopwatch
// Verilog Test Fixture created by ISE for module: stopwatch
////////////////////////////////////////////////////////////////////////////////

module StudentID_tb_v;
   parameter DELY=10; 
	// Inputs
	reg clk;
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
	StudentID #(.sim(1'b1)) StudentID_inst(
		.clk(clk), 
		.reset(reset), 
		.a(a), 
		.b(b), 
		.c(c), 
		.d(d), 
		.e(e), 
		.f(f), 
		.g(g), 
		.dp(dp), 
		.pos(pos));

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 1;
		#(DELY*2.5+1) reset = 0;
		#(DELY*2000) $stop;
	end
		always #(DELY/2) clk=~clk;
   
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
           7'b1111111:num=0;
           default:num=63;		 //"?" ASCII Code
       endcase
       wire[6:0] num0,num1, num2,num3;
       
       assign    num0=(pos==4'b1110)? num:7'd0;
       assign    num1=(pos==4'b1101)? num:7'd0;
       assign    num2=(pos==4'b1011)? num:7'd0;
       assign    num3=(pos==4'b0111)? num:7'd0;  
     
endmodule

