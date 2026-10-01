`timescale 1ns / 1ps

module counter_tb();

    // 参数配置
    localparam MOD_N = 10;           // 模10计数器
    localparam COUNTER_BITS = 4;     // 需要4位二进制表示0-9
    
    // 信号定义
    reg clk;
    reg reset;
    reg en;
    wire [COUNTER_BITS-1:0] q;
    wire co;
    
    // 实例化计数器
    counter #(
        .n(MOD_N),
        .counter_bits(COUNTER_BITS)
    ) u_counter (
        .clk(clk),
        .reset(reset),
        .en(en),
        .q(q),
        .co(co)
    );
    
    // 时钟生成：周期20ns (50MHz)
    always begin
        clk = 0;
        #10;
        clk = 1;
        #10;
    end
    
    // 测试激励
    initial begin
        // 初始化
        reset = 1;
        en = 0;
        
        // 释放复位
        #30;
        reset = 0;
        #10;
        
        // 测试1：使能计数器
        $display("\n=== Test 1: Normal counting ===");
        en = 1;
        
        // 等待计数到9并产生进位
        #400;  // 计数10个周期 (0->9)
        
        // 测试2：计数过程中复位
        $display("\n=== Test 2: Reset during counting ===");
        #20;
        reset = 1;
        #30;
        reset = 0;
        
        // 继续计数
        #200;
        
        // 测试3：禁用使能
        $display("\n=== Test 3: Disable enable signal ===");
        en = 0;
        #100;
        
        // 测试4：重新使能
        $display("\n=== Test 4: Re-enable counting ===");
        en = 1;
        #200;
        
        // 测试5：测试不同的模数（需要重新实例化或修改参数）
        $display("\n=== Test 5: Test completed ===");
        #50;
        
        $finish;
    end
    
    
    // 波形输出（可选）
    initial begin
        $dumpfile("prj/vcd/counter.vcd");
        $dumpvars(0, counter_tb);
    end
    
    // 断言：检查进位信号行为
    always @(posedge clk) begin
        // 当q等于n-1且en有效时，co应该为1
        if (q == MOD_N-1 && en && !reset)
            assert (co == 1) else
                $error("ERROR: co should be 1 when q=%d and en=1", q);
        
        // 其他情况co应该为0
        if ((q != MOD_N-1 || !en) && !reset)
            assert (co == 0) else
                $error("ERROR: co should be 0 when q=%d and en=%b", q, en);
    end
    
endmodule