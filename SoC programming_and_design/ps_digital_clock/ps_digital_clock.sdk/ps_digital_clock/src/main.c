#include "xil_types.h"
#include "xparameters.h"
#include "xiicps.h"
#include "seven_seg.h"
#include "textlcd.h"


#define	IIC_SLAVE_ADDR	0x51
#define	IIC_SCLK_RATE	100000


void	WriteTLCDReg(char *pRegVal, int val);
char	bin2ascii(char bin);
int		ReadRTC(XIicPs Iic, u8 *SendBuffer, u8 *RecvBuffer);


int main(void)
{
	XIicPs	Iic;			/**< Instance of the IIC Device */
	int 	IicStatus;
	u8		*SendBuffer;	/**< Buffer for Transmitting Data */
	u8		RecvBuffer[3];	/**< Buffer for Receiving Data */

	int		SegReg;
	char	TlcdReg_upline[16];
	char	TlcdReg_downline[16];

	int		i;
	int		wait;


	sprintf(TlcdReg_upline, "Digital Clock   ");

	while(TRUE)
	{
		IicStatus = ReadRTC(Iic, SendBuffer, RecvBuffer);

		if (IicStatus != XST_SUCCESS)
		{
			return XST_FAILURE;
		}

		// Coding here!
		int temp=0;
		SegReg = ((temp|RecvBuffer[2])<<24)|((temp|RecvBuffer[1])<<12)|(temp|RecvBuffer[0])|0x00A00A00;
		SEVEN_SEG_mWriteReg(XPAR_SEVEN_SEG_0_S00_AXI_BASEADDR, SEVEN_SEG_S00_AXI_SLV_REG0_OFFSET, SegReg);


		WriteTLCDReg(TlcdReg_downline, SegReg);
		for(i = 0; i < 4; i++)
		{
			// Coding here!
			//temp = (temp|TlcdReg_upline[i])|(temp<<8|TlcdReg_upline[i+1])|(temp<<8|TlcdReg_upline[i+2])|(temp<<8|TlcdReg_upline[i+3]);
			TEXTLCD_mWriteReg(XPAR_TEXTLCD_0_S00_AXI_BASEADDR, TEXTLCD_S00_AXI_SLV_REG0_OFFSET+4*i, *(int *)(TlcdReg_upline+4*i));
			//temp=(temp|TlcdReg_downline[i])|(temp<<8|TlcdReg_downline[i+1])|(temp<<8|TlcdReg_downline[i+2])|(temp<<8|TlcdReg_downline[i+3]);
			TEXTLCD_mWriteReg(XPAR_TEXTLCD_0_S00_AXI_BASEADDR, TEXTLCD_S00_AXI_SLV_REG4_OFFSET+4*i,*(int *)(TlcdReg_downline+4*i));
		}

		for(wait = 0; wait < 1200; wait++);
	}
}

void WriteTLCDReg(char *pRegVal, int val)
{
	int		i = 0;
	char	temp;

	for(i = 0; i < 8; i++)
	{
		// Coding here!
		temp = bin2ascii((val>>(28-4*i))&0x0F);
		pRegVal[i] = temp;
		pRegVal[i+8] = 0x20;
	}
}

char bin2ascii(char bin)
{
	////////////////////
	return (0x30|bin);
	////////////////////
}

int ReadRTC(XIicPs Iic, u8 *SendBuffer, u8 *RecvBuffer)
{
	int				Status;
	XIicPs_Config	*Config;

	Config = XIicPs_LookupConfig(XPAR_XIICPS_0_DEVICE_ID);
	if (Config == NULL)
	{
		return XST_FAILURE;
	}

	Status = XIicPs_CfgInitialize(&Iic, Config, Config->BaseAddress);
	if (Status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	XIicPs_SetSClk(&Iic, IIC_SCLK_RATE);

	*SendBuffer		= 0x02;
	RecvBuffer[0]	= 0x00;
	RecvBuffer[1]	= 0x00;
	RecvBuffer[2]	= 0x00;

	Status = XIicPs_MasterSendPolled(&Iic, SendBuffer, 1, IIC_SLAVE_ADDR);
	if(Status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	while(XIicPs_BusIsBusy(&Iic))
	{
		/* NOP */
	}

	Status = XIicPs_MasterRecvPolled(&Iic, RecvBuffer, 3, IIC_SLAVE_ADDR);
	if (Status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}
