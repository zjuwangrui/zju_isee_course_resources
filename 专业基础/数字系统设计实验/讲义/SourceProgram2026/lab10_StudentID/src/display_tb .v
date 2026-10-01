`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: zju
// Engineer:qmj
////////////////////////////////////////////////////////////////////////////////

module display_tb_v;
   parameter DELY=10; 
	// Inputs
	reg clk;
	reg scan;
	reg [3:0]d0,d1,d2,d3;
	// Outputs
	wire a;
	wire b;
	wire c;
	wire d;
	wire e;
	wire f;
	wire g;
	wire [3:0] pos;
	// Instantiate the Unit Under Test (UUT)
	

	display  display_inst(
		.clk(clk), 
		.scan(scan),
		.d0(d0),
		.d1(d1),
		.d2(d2),
		.d3(d3),
		.a(a), 
		.b(b), 
		.c(c), 
		.d(d), 
		.e(e), 
		.f(f), 
		.g(g), 
		.pos(pos));

	initial begin
		// Initialize Inputs
		clk = 0;
		scan = 0;
		#(DELY*2.5+1) d0 =0;d1= 1;d2=2;d3=3;
		repeat (12)
		  begin 
		   #(DELY*3)  scan=1;
		   #DELY  scan=0;
		  end
		  d0 =4;d1= 5;d2=6;d3=7;
		  repeat (12)
		  begin 
		   #(DELY*3)  scan=1;
		   #DELY  scan=0;
		  end
		   d0 =8;d1= 9;d2=10;d3=11;
		  repeat (12)
		  begin 
		   #(DELY*3)  scan=1;
		   #DELY  scan=0;
		  end
		
		#(DELY) $stop;
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

