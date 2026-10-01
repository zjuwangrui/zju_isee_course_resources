`timescale 1ns / 10ps

module button_press_tb;
  reg clk,ButtonIn,reset;
  wire ButtonOut;
  parameter delay=10;
//  
   initial begin
      clk = 0;	reset = 1;	ButtonIn = 0;
      #(delay*3+1) reset=0;
      #(delay*100 )   
       repeat (25) 
         begin
           #(delay*5) ButtonIn=0;
           #(delay*5) ButtonIn=1;
         end
       #(delay*900) 
         repeat (25)
            begin
            #(delay*5) ButtonIn=1;
            #(delay*5) ButtonIn=0;
          end
       #(delay*1200) 
          repeat (25) 
         begin
           #(delay*5) ButtonIn=0;
           #(delay*5) ButtonIn=1;
         end
       #(delay*900) 
         repeat (25)
            begin
            #(delay*5) ButtonIn=1;
            #(delay*5) ButtonIn=0;
          end
       #(delay*100) 
       $finish();;
      end
 //     
    always #(delay/2) clk=~clk;
 //

initial begin
  $dumpfile("prj/vcd/button_press_unit_tb.vcd");
  $dumpvars(0, button_press_tb);
end
button_press_unit #(.sim(1))  button_unit(
  .clk(clk),
  .reset(reset),
  .button_in(ButtonIn),
  .button_out(ButtonOut)
   );

endmodule
