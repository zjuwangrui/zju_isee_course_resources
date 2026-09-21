// 优先编码器测试平台
`timescale 1ns/1ps  // 时间单位/精度

module pr_encoder_tb();

  // 测试信号声明
  reg [3:0] in_tb;        // 测试输入
  wire [1:0] out_tb;      // 测试输出
  wire v_tb;              // 有效标志输出
  
  // 实例化被测试模块
  pr_encoder pr_encoder_instance (
    .D(in_tb),
    .out(out_tb),
    .v(v_tb)
  );
  
  // 测试过程
  initial begin
    // 显示测试开始信息
    $display("开始测试优先编码器");
    // 测试用例1：无输入
    in_tb = 4'b0000;
    #10;
    
    // 测试用例2：最高位优先
    in_tb = 4'b1000;  // in[3] = 1
    #10;
    
    in_tb = 4'b1100;  // 多个1，应输出in[3]的编码
    #10;
    
    // 测试用例3：次高位优先
    in_tb = 4'b0100;  // in[2] = 1
    #10;
    
    in_tb = 4'b0110;  // 应输出in[2]的编码
    #10;
    
    // 测试用例4：第三位优先
    in_tb = 4'b0010;  // in[1] = 1
    #10;
    
    in_tb = 4'b0011;  // 应输出in[1]的编码
    #10;
    
    // 测试用例5：最低位优先
    in_tb = 4'b0001;  // in[0] = 1
    #10;
    
    // 测试用例6：随机测试
    in_tb = 4'b1010;
    #10;
    
    in_tb = 4'b0101;
    #10;
    
    in_tb = 4'b1111;  // 全1，应输出in[3]的编码
    #10;
    
    // 测试结束
    #10;
    $display("========================================");
    $display("测试完成");
    $display("========================================");
    $finish();
  end
  
  // 生成波形文件（用于波形查看）
  initial begin
    $dumpfile("prj/vcd/pr_encoder_tb.vcd");  // 波形文件名
    $dumpvars(0, pr_encoder_tb);      // 记录所有变量
  end

endmodule