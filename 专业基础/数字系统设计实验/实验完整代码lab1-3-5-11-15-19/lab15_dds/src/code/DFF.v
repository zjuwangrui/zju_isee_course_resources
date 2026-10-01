module DFF
#(parameter n =1
)
(
    input clk,
    input R,
    input EN,
    input [n-1:0] D,
    output reg [n-1:0] Q
);
    always @(posedge clk) begin
        if (R) begin
            Q <= 0;
        end else if (EN) begin
            Q <= D;
        end
    end
endmodule