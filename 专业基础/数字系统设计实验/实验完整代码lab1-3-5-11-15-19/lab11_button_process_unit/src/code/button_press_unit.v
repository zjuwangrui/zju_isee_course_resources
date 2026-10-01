module button_press_unit
    #(parameter sim = 1)
(
    input  clk,
    input  reset,
    input  button_in,
    output  button_out
);
    // output declaration of module syncer
    wire synch_out;
    
    syncer u_syncer(
        .asynch_in 	(button_in  ),
        .clk       	(clk        ),
        .synch_out 	(synch_out  )
    );
    
    // output declaration of module debouncer
    wire out;
    
    debouncer #(
        .sim(sim))
    u_debouncer(
        .clk   	(clk    ),
        .reset 	(reset  ),
        .in    	(synch_out     ),
        .out   	(out    )
    );
    
    // output declaration of module PWM
    
    PWM u_PWM(
        .in  	(out   ),
        .clk 	(clk  ),
        .out 	(button_out  )
    );
    
endmodule
