`timescale 1ns/1ns

module tb_decode;
    // 1. 定义测试信号
    reg [2:0] din;      // 3位输入
    wire [7:0] out;     // 8位输出
    
    // 2. 实例化被测模块
    decode uut (
        .din(din),
        .out(out)
    );
    
    // 3. 生成测试激励
    initial begin
        // 3.1 初始化并开始记录波形
        din = 3'b000;
        $dumpfile("prj/vcd/decode.vcd");
        $dumpvars(0, tb_decode);
        
        $display("=== 3-8译码器仿真开始 ===");
        $display("时间  din  out(二进制)  out(十六进制)");
        display_signal();
        
        // 3.2 测试所有8种输入组合
        #10 din = 3'b000;  // 测试0
        display_signal();
        
        #10 din = 3'b001;  // 测试1
        display_signal();
        
        #10 din = 3'b010;  // 测试2
        display_signal();
        
        #10 din = 3'b011;  // 测试3
        display_signal();
        
        #10 din = 3'b100;  // 测试4
        display_signal();
        
        #10 din = 3'b101;  // 测试5
        display_signal();
        
        #10 din = 3'b110;  // 测试6
        display_signal();
        
        #10 din = 3'b111;  // 测试7（default）
        display_signal();
        
        // 3.3 额外测试：快速切换
        $display("\n=== 快速切换测试 ===");
        #5 din = 3'b010;
        #5 din = 3'b101;
        #5 din = 3'b000;
        
        // 3.4 结束仿真
        #10;
        $display("\n=== 仿真结束 ===");
        $finish;
    end
    
    // 辅助任务：显示当前信号值
    task display_signal;
        begin
            $display("%4d  %b    %b        %h", 
                    $time, din, out, out);
        end
    endtask
    
endmodule