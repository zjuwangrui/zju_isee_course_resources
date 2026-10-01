//脉宽变化电路
module PWM(
    input wire in,
    input wire clk,
    output wire out
);
    reg q;
    always @(posedge clk) begin
        q <= in;
    end
    assign out = (~q) & in;

endmodule