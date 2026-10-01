module controller(
    input clk,
    inout reset,//异步复位
    input in,//按键输入
    input timer_done,//定时完成信号
    output timer_clr,//开始定时信号
    output reg out //调理后的按键输出信号
);
    reg state, next_state;
    parameter HIGH = 2'b00, LOW = 2'b01, WAIT_HIGH = 2'b10, WAIT_LOW = 2'b11;
    always @(*) begin
        case(state)
            HIGH: next_state = in ? HIGH : WAIT_LOW;
            LOW: next_state = in ? WAIT_HIGH : LOW;
            WAIT_HIGH: next_state = timer_done ? HIGH : WAIT_HIGH;
            WAIT_LOW: next_state = timer_done ? LOW : WAIT_LOW;
        endcase
    end
    always @(posedge clk or posedge reset) begin
        if (reset) state <= LOW;
        else state <= next_state;
    end
    assign timer_clr = (state == HIGH || state == LOW) ? 1 : 0;
    assign out = (state == LOW) ? 0 : 1;
endmodule