module debouncer
    #(
        parameter  sim = 1
    )
    (
        input clk,
        input reset,//异步复位
        input in,//按键输入
        output out //调理后的按键输出信号
    );
wire timer_clr, timer_done, pluse1kHz;

counter #(
        .n(sim?32:100000), 
        .counter_bits(sim?5:17))
frency_division(
    .clk(clk),
    .reset(1'b0),
    .en(1'b1),
    .co(pluse1kHz),
    .q()
);

controller c0(
    .clk(clk),
    .reset(reset),
    .in(in),
    .timer_done(timer_done),
    .timer_clr(timer_clr),
    .out(out)
);

counter #(
    .n            	(10  ),
    .counter_bits 	(4  ))
timer(
    .clk   	(clk    ),
    .reset 	(timer_clr  ),
    .en    	(pluse1kHz     ),
    .q     	(      ),
    .co    	(timer_done     )
);


endmodule