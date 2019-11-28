module stopwatch(
input	wire	clk,
input	wire	resetn,
input	wire 	set,
output	wire 	[31:0]	timer
);

reg [31:0]	clk_cnt;
reg [7:0]	msec;
reg [7:0]	sec;
reg [7:0]	min;
assign	timer = {8'd0, min, sec, msec};
always @(posedge clk or negedge resetn) begin
	if(!resetn)
		clk_cnt <= 32'd0;
		msec <= 8'd0;
		sec <= 8'd0;
		min <= 8'd0;
	else begin
		if(set == 1'd1) begin
			if(clk_cnt == 32'd250000-1) begin
				clk_cnt <= 32'd0;
				msec <= msec + 8'd1;
				if(msec == 8'd99) begin
					sec <= sec + 1;
					msec <= 8'd0;
					if(sec == 8'd59) begin
						sec <= 8'd0;
						min <= min + 8'd1;
						if(min == 8'd59)
							min <= 8'd0;
						else
							min <= min;
					end
					else
						sec <= sec;
				end
				else
					msec <= msec;
			end
			else begin
				clk_cnt <= clk_cnt + 32'd1;
			end
		else if(set == 1'd0) begin
			clk_cnt <= clk_cnt;
			msec <= msec;
			sec <= sec;
			min <= min;
		end
		else begin
			clk_cnt <= clk_cnt;
			msec <= msec;
			sec <= sec;
			min <= min;
		end
	end
end


		