//同步器
module syncer(
    input asynch_in,
    input clk,
    output synch_out
);
    reg q1;
    reg q2;

    always @(posedge clk) begin
        q1 <= asynch_in;
        q2 <= q1;
    end

    assign synch_out = q2;
endmodule