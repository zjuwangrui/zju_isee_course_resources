module data_process(
    input area,
    input [15:0] din,
    output [15:0] dout
);
    assign dout = area ? (~din+1) : din;
endmodule