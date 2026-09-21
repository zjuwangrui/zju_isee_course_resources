//功能：优先编码器，4输入三输出。
module pr_encoder(
  input [3:0] D,
  output reg [1:0] out,
  output reg v
);
  always @(*) begin
    if( D == 4'b0000 ) begin
      out = 2'b00;
      v = 1'b0;
    end
    else if( D[3] == 1 ) begin
      out = 2'b11;
      v = 1'b1;
    end
    else if( D[2] == 1 ) begin
      out = 2'b10;
      v = 1'b1;
    end
    else if( D[1] == 1 ) begin
      out = 2'b01;
      v = 1'b1;
    end
    else if( D[0] == 1 ) begin
      out = 2'b00;
      v = 1'b1;
    end
    else begin
      out = 2'b00;
      v = 1'b0;
    end
  end
endmodule
