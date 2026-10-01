//////////////////////////////////////////////////////////////
// Company:zju 
// Engineer:qmj 
/////////////////////////////////////////////////////////////
module counter_n(clk,en,r,q,co);
  parameter  n=2; //参数n表示计数的模   
  parameter  counter_bits=1;//参数counter_bits表示计数的位数 
  input   clk,en,r ;
  output  co;
  output [counter_bits-1:0]  q;
  reg [counter_bits-1:0]  q=0;
  assign  co=(q==(n-1)) && en;//进位
  always @(posedge clk) 
  begin
      if(r) q=0;
	  else if(en)  //en=1,计数en=0,保持
	          begin	 
                if(q==(n-1))  q=0 ;
                else q=q+1;		 
              end
  end
endmodule
