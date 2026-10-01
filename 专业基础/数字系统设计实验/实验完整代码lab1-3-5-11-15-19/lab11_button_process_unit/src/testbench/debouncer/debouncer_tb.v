`timescale 1ns / 1ps

module debouncer_tb();

    // 参数定义
    localparam CLK_FREQ = 100_000_000;  // 100MHz
    localparam CLK_PERIOD = 10;         // 10ns
    localparam DEBOUNCE_TIME_MS = 10;   // 消抖时间10ms
    localparam DEBOUNCE_CYCLES = CLK_FREQ / 1000 * DEBOUNCE_TIME_MS;  // 1,000,000 周期
    
    // 信号定义
    reg clk;
    reg reset;
    reg in;
    wire out;
    
    // 实例化待测模块（仿真模式）
    debouncer #(
        .sim(1)  // 仿真模式，使用较小的计数器值
    ) u_debouncer (
        .clk(clk),
        .reset(reset),
        .in(in),
        .out(out)
    );
    
    // 生成时钟
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end
    
    // 任务：模拟按键按下（带抖动）
    task press_key_with_jitter;
        input real press_duration_ms;  // 按下持续时间
        input real jitter_duration_ms; // 抖动持续时间
        input real stable_time_ms;     // 稳定时间
        
        reg [7:0] jitter_count;
        real jitter_interval;
        integer i;
        
        begin
            // 初始状态：按键未按下
            in = 1;  // 假设高电平表示未按下
            #(stable_time_ms * 1000000);  // 等待稳定
            
            $display("%t: Key press started", $time);
            
            // === 第一阶段：按下时的抖动 ===
            jitter_count = $urandom_range(5, 15);  // 随机5-15次抖动
            jitter_interval = jitter_duration_ms / jitter_count;
            
            for (i = 0; i < jitter_count; i++) begin
                in = ~in;  // 翻转电平模拟抖动
                #(jitter_interval * 1000000);
            end
            
            // === 第二阶段：稳定按下 ===
            in = 0;  // 低电平表示按下
            $display("%t: Key stable pressed", $time);
            #(press_duration_ms * 1000000);
            
            // === 第三阶段：释放时的抖动 ===
            $display("%t: Key release started", $time);
            jitter_count = $urandom_range(5, 15);
            jitter_interval = jitter_duration_ms / jitter_count;
            
            for (i = 0; i < jitter_count; i++) begin
                in = ~in;
                #(jitter_interval * 1000000);
            end
            
            // === 第四阶段：稳定释放 ===
            in = 1;
            $display("%t: Key stable released", $time);
            #(stable_time_ms * 1000000);
        end
    endtask
    
    // 任务：简单按键（无抖动，用于对比）
    task simple_key_press;
        input real duration_ms;
        begin
            in = 0;
            #(duration_ms * 1000000);
            in = 1;
        end
    endtask
    
    // 任务：短按（小于消抖时间）
    task short_press;
        input real duration_ms;
        begin
            in = 0;
            #(duration_ms * 1000000);
            in = 1;
        end
    endtask
    
    // 主测试流程
    initial begin
        $display("========================================");
        $display("    Debouncer Testbench Started");
        $display("    Clock: 100MHz");
        $display("    Debounce time: 10ms (in hardware)");
        $display("    Sim mode: ON (faster simulation)");
        $display("========================================\n");
        
        // 初始化
        reset = 1;
        in = 1;  // 未按下状态
        
        // 释放复位
        #(CLK_PERIOD * 5);
        reset = 0;
        #(CLK_PERIOD * 10);
        
        // ============================================
        // 测试1：带抖动的正常按键（10ms抖动）
        // ============================================
        $display("\n[Test 1] Normal key press with 10ms jitter");
        $display("----------------------------------------");
        press_key_with_jitter(100,  // 按下持续100ms
                              10,   // 抖动10ms
                              20);  // 测试间等待20ms
        
        #(20_000_000);  // 等待20ms
        
        // ============================================
        // 测试2：短按（小于消抖时间，应该被过滤）
        // ============================================
        $display("\n[Test 2] Short press (5ms < debounce time)");
        $display("----------------------------------------");
        $display("Expected: No output pulse");
        short_press(5);  // 按下5ms后释放
        #(50_000_000);
        
        // ============================================
        // 测试3：快速连续按键（模拟连击）
        // ============================================
        $display("\n[Test 3] Rapid consecutive presses");
        $display("----------------------------------------");
        repeat(3) begin
            press_key_with_jitter(50, 10, 10);
            #(10_000_000);
        end
        #(50_000_000);
        
        // ============================================
        // 测试4：带长抖动的按键（20ms抖动）
        // ============================================
        $display("\n[Test 4] Key press with 20ms jitter");
        $display("----------------------------------------");
        press_key_with_jitter(100, 20, 20);
        #(50_000_000);
        
        // ============================================
        // 测试5：复位功能测试
        // ============================================
        $display("\n[Test 5] Reset test during key press");
        $display("----------------------------------------");
        in = 0;  // 按下按键
        #(5_000_000);
        reset = 1;  // 复位
        #(CLK_PERIOD * 5);
        reset = 0;
        #(10_000_000);
        in = 1;  // 释放
        #(20_000_000);
        
        // ============================================
        // 测试6：极短毛刺测试
        // ============================================
        $display("\n[Test 6] Short glitch test");
        $display("----------------------------------------");
        in = 1;
        #(1_000_000);
        in = 0;  // 1us 毛刺
        #(1_000);
        in = 1;
        #(10_000_000);
        
        in = 0;
        #(100_000);  // 100us 毛刺
        in = 1;
        #(10_000_000);
        
        $display("\n========================================");
        $display("    All tests completed!");
        $display("========================================");
        
        #(10_000_000);
        $finish;
    end
    
    // 实时监控输出变化
    always @(posedge out or negedge out) begin
        if (out)
            $display("%t: [OUTPUT] Key pressed (out=1)", $time);
        else
            $display("%t: [OUTPUT] Key released (out=0)", $time);
    end
    
    // 监控按键输入状态
    always @(posedge in or negedge in) begin
        if (in)
            $display("%t: [INPUT] Key released", $time);
        else
            $display("%t: [INPUT] Key pressed", $time);
    end
    
    // 监控定时器清除和完成信号（用于调试）
    // 注：这些信号在顶层没有引出，需要修改模块或通过层次化引用
    
    // 波形输出
    initial begin
        $dumpfile("prj/vcd/debouncer.vcd");
        $dumpvars(0, debouncer_tb);
    end
    
    // 仿真时间限制（防止无限仿真）
    initial begin
        #(1_000_000_000);  // 1秒
        $display("ERROR: Simulation timeout!");
        $finish();
    end
    
endmodule