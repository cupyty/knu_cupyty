#include "xparameters.h"
#include "xuartps_hw.h"
#include "textlcd.h"


/////////////////////////////////
//           Define            //
/////////////////////////////////
#define	TextLine1	0				// Text LCD line1 indicator
#define TextLine2	1				// Text LCD line2 indicator
#define	CR			0x0d			// Carriage Return
#define	LF			0x0a			// Line Feed
#define	SP			0x20			// Space
#define	MAX			17				// Number maximum



///////////////////////////////////
//           Prototype           //
///////////////////////////////////
void PrintChar(char *str);
void GetCmd(char *sel);
void WriteTLCDReg(unsigned int *pRegVal);
void GetTextLine(char *ReadReg, unsigned int TextLine);
void ReadTLCDReg(void);


///////////////////////////////////////////////////////////////////////////////////////
//                                 main function  				                     //
///////////////////////////////////////////////////////////////////////////////////////
int main()
{
	unsigned int	CntrlRegister;
	char			sel			=	0;
	unsigned int	RegVal[4]	=	{0, };

	// Read status register
	CntrlRegister = XUartPs_ReadReg(XPAR_PS7_UART_1_BASEADDR, XUARTPS_CR_OFFSET);

	// Enable TX and RX for the device
	XUartPs_WriteReg( XPAR_PS7_UART_1_BASEADDR, XUARTPS_CR_OFFSET,
					  ((CntrlRegister & ~XUARTPS_CR_EN_DIS_MASK) | XUARTPS_CR_TX_EN | XUARTPS_CR_RX_EN) );

	while(1)
	{
		PrintChar("=========================    M E N U    =========================" );
		PrintChar("What do you want to do?");
		PrintChar("1. Write data to Text LCD line 1 register");
		PrintChar("2. Write data to Text LCD line 2 register");
		PrintChar("3. Read data from register");
		XUartPs_SendByte(XPAR_PS7_UART_1_BASEADDR, LF);
		XUartPs_SendByte(XPAR_PS7_UART_1_BASEADDR, CR);

		GetCmd(&sel);

		switch(sel)
		{
			case ('1') :
			{
				PrintChar("Write data ( Only English, Number, space ) : " );
				WriteTLCDReg(RegVal);

				//////////////////////////////
				// Coding here!
				TEXTLCD_mWriteReg(XPAR_TEXTLCD_0_S00_AXI_BASEADDR, TEXTLCD_S00_AXI_SLV_REG0_OFFSET, RegVal[0]);
				TEXTLCD_mWriteReg(XPAR_TEXTLCD_0_S00_AXI_BASEADDR, TEXTLCD_S00_AXI_SLV_REG1_OFFSET, RegVal[1]);
				TEXTLCD_mWriteReg(XPAR_TEXTLCD_0_S00_AXI_BASEADDR, TEXTLCD_S00_AXI_SLV_REG2_OFFSET, RegVal[2]);
				TEXTLCD_mWriteReg(XPAR_TEXTLCD_0_S00_AXI_BASEADDR, TEXTLCD_S00_AXI_SLV_REG3_OFFSET, RegVal[3]);
				//////////////////////////////

				break;
			}
			case ('2') :
			{
				PrintChar("Write data ( Only English, Number, space ) : " );
				WriteTLCDReg(RegVal);

				//////////////////////////////
				// Coding here!
				TEXTLCD_mWriteReg(XPAR_TEXTLCD_0_S00_AXI_BASEADDR, TEXTLCD_S00_AXI_SLV_REG4_OFFSET, RegVal[0]);
				TEXTLCD_mWriteReg(XPAR_TEXTLCD_0_S00_AXI_BASEADDR, TEXTLCD_S00_AXI_SLV_REG5_OFFSET, RegVal[1]);
				TEXTLCD_mWriteReg(XPAR_TEXTLCD_0_S00_AXI_BASEADDR, TEXTLCD_S00_AXI_SLV_REG6_OFFSET, RegVal[2]);
				TEXTLCD_mWriteReg(XPAR_TEXTLCD_0_S00_AXI_BASEADDR, TEXTLCD_S00_AXI_SLV_REG7_OFFSET, RegVal[3]);
				//////////////////////////////

				break;
			}
			case ('3') :
			{
				ReadTLCDReg();

				break;
			}
			default : PrintChar("Select only 1 ~ 3, please!");
		}
	}

	return 0;
}


///////////////////////////////////
//         function set          //
///////////////////////////////////
void PrintChar(char *str)
{
	XUartPs_SendByte(XPAR_PS7_UART_1_BASEADDR, LF);
	XUartPs_SendByte(XPAR_PS7_UART_1_BASEADDR, CR);

	while(*str  !=  0)
	{
		XUartPs_SendByte(XPAR_PS7_UART_1_BASEADDR, *str++);
	}
}


void GetCmd(char *sel)
{
	do
	{
		*sel = XUartPs_RecvByte(XPAR_PS7_UART_1_BASEADDR);

		if ( (*sel >= '1') && (*sel <= '3') )
		{
			XUartPs_SendByte(XPAR_PS7_UART_1_BASEADDR, *sel);
		}
	}
	while( !((*sel >= '1') && (*sel <= '3')) );
}


void WriteTLCDReg(unsigned int *pRegVal)
{
	int				nReg	=	0;
	int				nOffset	=	0;
	unsigned char	Data	=	0x20;

	for(nReg = 0; nReg < 4; nReg++)
	{
		do
		{
			// Coding here!
			Data = XUartPs_RecvByte(XPAR_PS7_UART_1_BASEADDR);

			if ( ((Data >= '0') && (Data <= '9')) || ((Data >= 'a') && (Data <= 'z')) || ( (Data >= 'A') && (Data <= 'Z')) || (Data == SP) )
			{
				// Coding here!
				XUartPs_SendByte(XPAR_PS7_UART_1_BASEADDR, Data);
				*(pRegVal |= 1<<nOffset) = Data;
				// Coding here!
				
				nOffset++;
			}
			else
			{
			 	PrintChar("Please enter correctly!");
			}
		}
		while( !( nOffset == 4 ) );

		nOffset = 0;
	}
}


void GetTextLine(char *ReadReg, unsigned int TextLine)
{
	int				nReg	=	0;
	int				nOffset	=	0;
	unsigned int	temp	=	0;

	for(nReg = 0; nReg < 4; nReg++)
	{
		do
		{
			// Coding here!
			temp = TEXTLCD_mReadReg(XPAR_TEXTLCD_0_S00_AXI_BASEADDR+TextLine*16, nReg*4);
			*(ReadReg+nOffset) = (temp & (0xFF000000>>(8*nOffset)));
			// Coding here!

			nOffset++;
		}
		while( !(nOffset == 4) );

		nOffset = 0;
	}
}

void ReadTLCDReg(void)
{
	char ReadReg[MAX]={0, };

	PrintChar("------------------------------------------------------------------ ");
	PrintChar("Address 0x43C0_0000 ~ 0x43C0_000F --- ");
	GetTextLine(ReadReg, TextLine1);
	PrintChar(ReadReg);

	PrintChar("Address 0x43C0_0010 ~ 0x43C0_001F --- ");
	GetTextLine(ReadReg, TextLine2);
	PrintChar(ReadReg);
	PrintChar("------------------------------------------------------------------ ");
}

