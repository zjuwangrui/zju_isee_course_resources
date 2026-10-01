`timescale 1ns / 1ps

module tb_counter_up_dn;
    // 1. 定义测试信号
    reg clk;           // 时钟
    reg en;            // 使能
    reg u_d;           // 方向控制：1=加，0=减
    reg r;             // 复位
    wire [1:0] q;      // 计数器输出（2位）
    
    // 2. 实例化被测计数器（2位宽）
    counter_up_dn #(.counter_bits(2)) uut (
        .clk(clk),
        .en(en),
        .u_d(u_d),
        .r(r),
        .q(q)
    );
    
    // 3. 生成时钟信号（周期20ns，频率50MHz）
    initial begin
        clk = 0;
        forever #10 clk = ~clk;  // 每10ns翻转一次
    end
    
    // 4. 显示信号值辅助任务
    task display_state;
        begin
            $display("时间=%t, clk=%b, en=%b, u_d=%b, r=%b, q=%d", 
                     $time, clk, en, u_d, r, q);
        end
    endtask
    
    // 5. 主测试序列
    initial begin
        // 5.1 初始化并开始记录波形
        en = 1'b0;
        u_d = 1'b1;  // 默认加法模式
        r = 1'b1;    // 复位有效
        $dumpfile("counter_up_dn_wave.vcd");
        $dumpvars(0, tb_counter_up_dn);
        
        $display("=== 可逆计数器仿真开始 ===");
        $display("u_d=1:加法模式, u_d=0:减法模式");
        display_state();
        
        // 5.2 测试1：复位功能（20ns后释放）
        #20 r = 1'b0;  // 释放复位
        display_state();
        
        // 5.3 测试2：加法计数测试（使能有效，加法模式）
        $display("\n--- 测试2：加法计数 ---");
        en = 1'b1;      // 使能有效
        u_d = 1'b1;     // 加法模式
        #100;           // 等待5个时钟周期（应该计数5次：0→1→2→3→4→5）
        display_state();
        
        // 5.4 测试3：使能无效测试（计数器应保持）
        $display("\n--- 测试3：使能无效测试 ---");
        en = 1'b0;      // 使能无效
        #40;            // 等待2个时钟周期
        display_state();
        
        // 5.5 测试4：减法计数测试
        $display("\n--- 测试4：减法计数 ---");
        en = 1'b1;      // 使能有效
        u_d = 1'b0;     // 减法模式
        #80;            // 等待4个时钟周期（应该减4次：5→4→3→2→1）
        display_state();
        
        // 5.6 测试5：边界测试（减到0后继续减，应该回绕）
        $display("\n--- 测试5：边界回绕测试 ---");
        // 先减到0
        #40;            // 1→0（2位计数器，0-1=3）
        display_state();
        // 继续减（应该回绕到3）
        #20;
        display_state();
        
        // 5.7 测试6：再次复位
        $display("\n--- 测试6：运行中复位 ---");
        r = 1'b1;       // 复位有效
        #20;
        display_state();
        
        // 5.8 测试7：快速模式切换
        $display("\n--- 测试7：快速模式切换 ---");
        r = 1'b0;
        u_d = 1'b1;     // 加法
        #20;
        u_d = 1'b0;     // 减法
        #20;
        u_d = 1'b1;     // 加法
        #20;
        display_state();
        
        // 5.9 结束仿真
        #20;
        $display("\n=== 仿真结束 ===");
        $finish;
    end
    
    // 6. 可选：每个时钟沿显示状态（用于详细调试）
    // always @(posedge clk) begin
    //     $display("时钟沿 @%t, q=%d", $time, q);
    // end
    
endmodule