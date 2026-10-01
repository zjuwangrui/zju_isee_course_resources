`timescale 1ns/1ps

module tb_FlowingWaterLight;

    // ==================== 信号定义 ====================
    reg clk;           // 时钟信号
    reg reset;         // 复位信号
    reg direction;     // 方向控制
    wire [7:0] led;    // LED输出
    
    // ==================== 实例化DUT ====================
    FlowingWaterLight #(.sim(1)) dut (  // 设置sim=1，快速仿真
        .clk(clk),
        .reset(reset),
        .direction(direction),
        .led(led)
    );
    
    // ==================== 时钟生成 ====================
    always #10 clk = ~clk;  // 50MHz时钟，周期20ns
    
    // ==================== 测试流程 ====================
    initial begin
        // ---------- 初始化 ----------
        $dumpfile("prj/vcd/FlowingWaterLight.vcd");
        $dumpvars(0, tb_FlowingWaterLight);
        clk = 0;
        reset = 1;      // 复位有效
        direction = 0;  // 初始左移
        $display("========== 测试开始 ==========");
        $display("时间\t方向\tLED输出\t\t说明");
        
        // ---------- 复位阶段 ----------
        #20;            // 等待2个时钟周期
        reset = 0;      // 释放复位
        $display("%4dns\t左移\t%b\t复位释放", $time, led);
        
        // ---------- 测试左移 (direction=0) ----------
        $display("\n--- 测试左移模式 ---");
        direction = 0;  // 左移
        #200;           // 观察多个周期
        
        // ---------- 测试右移 (direction=1) ----------
        $display("\n--- 测试右移模式 ---");
        direction = 1;  // 右移
        reset = 0;
        #200;           // 观察多个周期
        
        // ---------- 测试复位功能 ----------
        $display("\n--- 测试复位功能 ---");
        reset = 1;      // 复位有效
        #50;
        $display("%4dns\t-\t%b\t复位有效", $time, led);
        
        reset = 0;      // 释放复位
        #50;
        $display("%4dns\t右移\t%b\t复位释放", $time, led);
        
        // ---------- 测试模式切换 ----------
        $display("\n--- 测试动态切换方向 ---");
        direction = 0;  // 左移
        #100;
        
        direction = 1;  // 切换为右移
        #100;
        
        direction = 0;  // 再切换回左移
        #100;
        
        // ---------- 测试完成 ----------
        $display("\n========== 测试完成 ==========");
        $finish;
    end
    
    // ==================== 监视器 ====================
    // 监视LED变化（只在LED改变时打印）
    reg [7:0] prev_led;
    initial prev_led = 0;
    
    always @(posedge clk) begin
        if (led !== prev_led) begin
            $display("%4dns\t%s\t%b\tLED变化", 
                    $time, 
                    direction ? "右移" : "左移",
                    led);
            prev_led = led;
        end
    end
    
    // ==================== 测试结束检查 ====================
    // 自动检查测试是否太长
    initial begin
        #2000;  // 设置超时时间
        $display("\n❌ 错误：测试超时！");
        $finish;
    end
    
endmodule