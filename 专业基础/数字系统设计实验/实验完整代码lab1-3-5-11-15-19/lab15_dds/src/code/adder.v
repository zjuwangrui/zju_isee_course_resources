module adder
#(parameter n = 8
)
(
    input [n-1:0] a,
    input [n-1:0] b,
    input ci,
    output co,
    output [n-1:0] sum
);
    assign {co, sum} = a + b + ci;
endmodule