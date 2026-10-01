module DDS(
    input clk,
    input reset,
    input [21:0] K,
    input sampling_pulse,
    output [15:0] sample,
    output reg new_sample_ready
);
    // output declaration of module adder
    
    wire [n-1:0] sum;
    parameter n = 22;
    adder #(
        .n 	(n  ))
    u_adder(
        .a   	(K    ),
        .b   	(raw_addr    ),
        .ci  	(1'b0   ),
        .co  	(   ),
        .sum 	(sum  )
    );
    
    // output declaration of module DFF
    wire [n-1:0] raw_addr;
    
    DFF #(
        .n 	(n  ))
    u_DFF_addr(
        .clk 	(clk  ),
        .R   	(reset    ),
        .EN  	(sampling_pulse   ),
        .D   	(sum    ),
        .Q   	(raw_addr    )
    );
    
    // output declaration of module DFF
    wire area;
    
    DFF #(
        .n 	(1  ))
    u_DFF_area(
        .clk 	(clk  ),
        .R   	(1'b0    ),
        .EN  	(1'b1   ),
        .D   	(raw_addr[21]    ),
        .Q   	(area    )
    );
    
    // output declaration of module addr_process
    wire [10:0] rom_addr;
    
    addr_process u_addr_process(
        .raw_addr 	(raw_addr[20:10]  ),
        .rom_addr 	(rom_addr  )
    );
    
    // output declaration of module sine_rom
    wire [15:0] raw_data;
    
    sine_rom u_sine_rom(
        .clk  	(clk   ),
        .addr 	(rom_addr  ),
        .dout 	(raw_data  )
    );
    
    // output declaration of module data_process
    wire [15:0] data;
    
    data_process u_data_process(
        .area 	(area  ),
        .din  	(raw_data   ),
        .dout 	(data  )
    );
    
    // output declaration of module DFF
    
    
    DFF #(
        .n 	(16  ))
    u_DFF_sample(
        .clk 	(clk  ),
        .R   	(1'b0    ),
        .EN  	(sampling_pulse   ),
        .D   	(data    ),
        .Q   	(sample    )
    );
    
    // output declaration of module DFF
    
    DFF #(
        .n 	(1  ))
    u_DFF(
        .clk 	(clk  ),
        .R   	(1'b0    ),
        .EN  	(1'b1   ),
        .D   	(sampling_pulse    ),
        .Q   	(new_sample_ready    )
    );
    
endmodule