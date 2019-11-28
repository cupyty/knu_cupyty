module vending_machine(
input wire rst_n,       //state reset
input wire clk,
input wire coin,        //coin ==1'b1 ? 동전입력 0 : X
input wire selection,   //selection == 1'b1 ? 음료선택 O : X
input wire refund,      //refund == 1'b1 ? 환불요청 O : X

output reg beverage     //beverage ==1'b1 ? 음료출력 O : X
);

parameter IDLE = 2'b00,
            SEL = 2'b01,
            GET = 2'b10,
            
            COIN = 3'b001,
            SELECTION = 3'b010,
            REFUND = 3'b100;

reg [1:0] currentstate, nextstate;
wire [2:0] control;

assign control = {refund, selection, coin};

always @(currentstate or control)
begin
    case(currentstate)
        IDLE: begin
                if(control == COIN)
                    nextstate = SEL;
                else
                    nextstate = IDLE;
                beverage = 1'b0;
              end
        SEL : begin
                if(control == SELECTION)
                    nextstate = GET;
                else if(control == REFUND)
                    nextstate = IDLE;
                else
                    nextstate = SEL;
                 beverage = 1'b0;
              end
        GET : begin
                    nextstate = IDLE;
                    beverage = 1'b1;
              end
        default : begin
                    nextstate = IDLE;
                    beverage = 1'b0;
                  end
    endcase
end

always @(posedge clk or negedge rst_n)
begin
    if(rst_n == 1'b0)
        currentstate <= IDLE;
    else
        currentstate <= nextstate;
end

endmodule