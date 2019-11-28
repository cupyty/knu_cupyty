module test_push(
input	wire	resetn,
input	wire	clk,
input	wire 	[2:0]	PB,
output	reg		[31:0]	data,
output	wire	INTR
);

reg	[2:0]	pb_1d;
reg	[2:0]	pb_2d;
reg [2:0]	curr_intr;
reg [2:0]	next_intr;
integer i;

assign INTR = curr_intr[2] & curr_intr[1] & curr_intr[0];

always @(curr_intr or pb_1d or pb_2d) begin
	for(i = 0; i<3; i=i+1) begin
		if(pb_2d[i] && (!pb_1d[i]))
			next_intr[i] <= 1'b0;
		else if(!(pb_2d[i]) && pb_1d[i])
			next_intr[i] <= 1'b1;
		else
			next_intr[i] <= curr_intr[i];
	end
	data <= {29'd0, curr_intr};
end
	

always @(posedge clk or negedge resetn) begin
	if(!resetn) begin
		curr_intr <= 3'b111;
		pb_1d <= 3'b111;
		pb_2d <= 3'b111;
	end
	else begin
		curr_intr <= next_intr;
		pb_1d <= PB;
		pb_2d <= pb_1d;
	end
end

endmodule


	if(!resetn) begin
		INTR <= 1'b1;
		data <= 32'h0000_0000;
		pb_2d <= 3'b000;
	end
	else begin
		for(i=0; i<3; i=i+1) begin
			if((PB[i]==0) && (pb_1d[i]==1))
				pb_2d[i] <= 1'b1;
			else
				pb_2d[i] <= 1'b0;
		end
		if(pb_2d[0]==1 || pb_2d[1] ==1 || pb_2d[2] ==1) begin
			INTR <= 1'b0;
		end
		else begin
			INTR <= 1'b1;
		end
	end
	data <={28'h0000_000,1'b0,pb_2d[2:0]};
end
		
		
		//if((!PB[0]) || (!PB[1]) || (!PB[2]) || (!PB[3])) begin
		//	INTR <= 1'b1;
		//	data <= {28'h0000_000,(~PB[3]),(~PB[2]),(~PB[1]),(~PB[0])};
		//end
		//else begin
		//	INTR <= 1'b0;
		//	data <= 32'h0000_0000;
		//end
	//end
//end

endmodule

		


	

		
	  