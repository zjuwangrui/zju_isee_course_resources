`timescale 1ns/1ns  // 时间单位/时间精度

module counter_tb;
    //定义参数
    parameter n = 2;           // 计数器的最大值
    parameter counter_bits = 1; // 计数器位宽
    // 1. 定义测试信号
    reg clk;      // 时钟信号
    reg rst;      // 复位信号
    reg en;       // 使能信号
    wire [counter_bits-1:0] q; // 计数器输出（1位）
    wire co;      // 进位输出
    
    // 2. 实例化被测计数器
    counter_n #(.n(n), .counter_bits(counter_bits)) uut (
        .clk(clk),
        .en(en),
        .r(rst),
        .q(q),
        .co(co)
    );
    
    // 3. 生成时钟信号（周期20ns，频率50MHz）
    initial begin
        clk = 0;
        forever #10 clk = ~clk;  // 每10ns翻转一次，周期20ns
    end
    
    // 4. 生成测试激励
    initial begin
        // 4.1 初始化信号并开始记录波形
        rst = 1'b1;  // 复位有效
        en = 1'b0;   // 使能无效
        $dumpfile("prj/vcd/counter_n.vcd");  // 指定VCD文件名
        $dumpvars(0, counter_tb);       // 记录所有信号，0表示记录所有层次
        
        // 4.2 显示仿真开始信息
        $display("=== 计数器仿真开始 ===");
        $display("时间  rst  en   q  co");
        
        // 4.3 测试序列
        
        // 测试1：复位测试（20ns）
        #20 rst = 1'b0;  // 释放复位
        $display("%4d   %b    %b   %b  %b", $time, rst, en, q, co);
        
        // 测试2：使能有效，正常计数（100ns）
        en = 1'b1;  // 使能有效
        #100;       // 计数5个完整周期（n=2，每个周期2个时钟）
        $display("%4d   %b    %b   %b  %b", $time, rst, en, q, co);
        
        // 测试3：使能无效，保持当前值（40ns）
        en = 1'b0;  // 使能无效
        #40;
        $display("%4d   %b    %b   %b  %b", $time, rst, en, q, co);
        
        // 测试4：再次使能，继续计数（80ns）
        en = 1'b1;
        #80;
        $display("%4d   %b    %b   %b  %b", $time, rst, en, q, co);
        
        // 测试5：测试复位功能（20ns）
        rst = 1'b1;  // 再次复位
        #20;
        $display("%4d   %b    %b   %b  %b", $time, rst, en, q, co);
        
        // 5. 结束仿真
        $display("\n=== 仿真结束 ===");
        $finish;  // 结束仿真
    end
    
    // 6. 可选：监视器，自动显示信号变化
    // initial begin
    //     $monitor("时间=%t, rst=%b, en=%b, q=%b, co=%b", 
    //              $time, rst, en, q, co);
    // end
    
endmodule
