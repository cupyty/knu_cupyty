`timescale 1ns/1ps

module tb_bcd_counter();

reg [4:0] i;

reg clk;
reg rst_n;

wire [3:0] q;
parameter PERIOD_100MHZ = 10;
always begin
    #(PERIOD_100MHZ/2);
    clk <=~clk;
end

bcd_counter bcd_counter_u0(.clk(clk), .rst_n(rst_n), .q(q));

initial begin
    i = 5'd0;
    clk = 1'b0;
    rst_n = 1'b0;
    #(PERIOD_100MHZ*2);
    rst_n = 1'b1;
    
    for(i = 5'd0; i<5'd30; i=i+5'd1) begin
        #PERIOD_100MHZ;
    end
    
    $stop;
end
endmodule
