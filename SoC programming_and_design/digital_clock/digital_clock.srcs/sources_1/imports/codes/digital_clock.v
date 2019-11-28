module digital_clock(
input	wire			resetn,
input	wire			clk,		// 25MHz

output	wire	[31:0]	segdata,
output	wire	[31:0]	textdata_a,
output	wire	[31:0]	textdata_b,
output	wire	[31:0]	textdata_c,
output	wire	[31:0]	textdata_d,
output	wire	[31:0]	textdata_e,
output	wire	[31:0]	textdata_f,
output	wire	[31:0]	textdata_g,
output	wire	[31:0]	textdata_h
);

wire	[3:0]	cnt_sec1;
wire	[3:0]	cnt_sec10;
wire	[3:0]	cnt_min1;
wire	[3:0]	cnt_min10;
wire	[3:0]	cnt_hour1;
wire	[3:0]	cnt_hour10;

reg		[7:0]	sec1;
reg		[7:0]	sec10;
reg		[7:0]	min1;
reg		[7:0]	min10;
reg		[7:0]	hour1;
reg		[7:0]	hour10;


//assign segdata = // Coding here!					// hh-mm-ss
assign segdata = {cnt_hour10, cnt_hour1, 4'd10, cnt_min10, cnt_min1, 4'd10, cnt_sec10, cnt_sec1};
assign textdata_a =  32'h44_69_67_69;				// Digi
assign textdata_b =  32'h74_61_6C_20;				// tal
assign textdata_c =  32'h43_6C_6F_63;				// Cloc
assign textdata_d =  32'h6B_20_20_20;				// k
//assign textdata_e =  // Coding here!				// hh:m
always @(cnt_sec1 or cnt_sec10 or cnt_min1 or cnt_min10 or cnt_hour1 or cnt_hour10)
begin
	case(cnt_sec1)
		4'd1 : sec1 = 8'h31;
		4'd2 : sec1 = 8'h32;
		4'd3 : sec1 = 8'h33;
		4'd4 : sec1 = 8'h34;
		4'd5 : sec1 = 8'h35;
		4'd6 : sec1 = 8'h36;
		4'd7 : sec1 = 8'h37;
		4'd8 : sec1 = 8'h38;
		4'd9 : sec1 = 8'h39;
		default : sec1 = 8'h30;
	endcase
	case(cnt_sec10)
		4'd1 : sec10 = 8'h31;
		4'd2 : sec10 = 8'h32;
		4'd3 : sec10 = 8'h33;
		4'd4 : sec10 = 8'h34;
		4'd5 : sec10 = 8'h35;
		default : sec10 = 8'h30;
	endcase
	case(cnt_min1)
		4'd1 : min1 = 8'h31;
		4'd2 : min1 = 8'h32;
		4'd3 : min1 = 8'h33;
		4'd4 : min1 = 8'h34;
		4'd5 : min1 = 8'h35;
		4'd6 : min1 = 8'h36;
		4'd7 : min1 = 8'h37;
		4'd8 : min1 = 8'h38;
		4'd9 : min1 = 8'h39;
		default : min1 = 8'h30;
	endcase
	case(cnt_min10)
		4'd1 : min10 = 8'h31;
		4'd2 : min10 = 8'h32;
		4'd3 : min10 = 8'h33;
		4'd4 : min10 = 8'h34;
		4'd5 : min10 = 8'h35;
		default : min10 = 8'h30;
	endcase
	case(cnt_hour1)
		4'd1 : hour1 = 8'h31;
		4'd2 : hour1 = 8'h32;
		4'd3 : hour1 = 8'h33;
		4'd4 : hour1 = 8'h34;
		4'd5 : hour1 = 8'h35;
		4'd6 : hour1 = 8'h36;
		4'd7 : hour1 = 8'h37;
		4'd8 : hour1 = 8'h38;
		4'd9 : hour1 = 8'h39;
		default : hour1 = 8'h30;
	endcase
	case(cnt_hour10)
		4'd1 : hour10 = 8'h31;
		4'd2 : hour10 = 8'h32;
		default : hour10 = 8'h30;
	endcase
end
assign textdata_e = {hour10, hour1, 8'h3a, min10};
assign textdata_f = {min1, 8'h3a, sec10, sec1};
	
//assign textdata_f =  // Coding here!				// m:ss
assign textdata_g =  32'h20_20_20_20;
assign textdata_h =  32'h20_20_20_20;


clk_divider	clk_divider_u0(	.resetn(resetn),
							.clk(clk),

							.cnt_sec1(cnt_sec1),
							.cnt_sec10(cnt_sec10),
							.cnt_min1(cnt_min1),
							.cnt_min10(cnt_min10),
							.cnt_hour1(cnt_hour1),
							.cnt_hour10(cnt_hour10)	);


endmodule

