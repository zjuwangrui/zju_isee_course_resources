module addr_process(
    input [10:0] raw_addr,
    output reg [10:0] rom_addr
);
    always @(*) begin
        if(raw_addr[10] == 0) begin
            rom_addr = raw_addr[9:0]; // Direct mapping for addresses 0 to 1023
        end else if(raw_addr == 11'd1024) begin // Special case for address 1024
            rom_addr = 11'd1023; // Map to 1023
        end else begin
            rom_addr = ~raw_addr[9:0] + 1; // Two's complement for addresses above 1024
        end
    end
endmodule