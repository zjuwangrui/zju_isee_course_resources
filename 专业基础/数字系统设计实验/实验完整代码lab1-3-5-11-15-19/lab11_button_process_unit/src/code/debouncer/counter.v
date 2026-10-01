module counter #(
    parameter n, //mod number
    parameter counter_bits  //number of bits needed to count to n
)(
    input clk,
    input reset,
    input en,
    output reg [counter_bits-1:0] q,
    output co
);
    assign co = (q == n-1) && en; //carry generates when q equals to n-1 and en signal is true
    always @(posedge clk) begin
        if (reset) q <= 0; //if reset is true, then reset q to 0
        else if (en) begin
            if (q == n-1) q <= 0; //if q equals to n-1, then reset q to 0
            else q <= q + 1;
        end
    end
endmodule