/*
 * Uart.c
 *
 * Created: 6/29/2022 9:33:17 AM
 *  Author: mahdy
 */ 

#include "Uart.h"

void M_Uart_Init(u32 Local_u32_BaudRate)
{
	u16 Local_u16_UBRR= ( F_OSC / ((u32) 16 * Local_u32_BaudRate )) - 1;
	
	M_Dio_PinMode(_PD0, INPUT);
	M_Dio_PinMode(_PD1, OUTPUT);
	// To select baudrate
	UBRR0 = Local_u16_UBRR;
	//To set Asynchronous mode, Disable parity check, Select 8bit mode character, Set clock parity
	UCSR0C = 0x06;
	
	//To Enable Transmitter And Receiver Mode 
	UCSR0B = 0x18;
}
void M_Uart_Send(u8  Local_u8_Data)
{
	UDR0 = Local_u8_Data;
	while(  GetBit(UCSR0A, 6) == 0 );
}

void M_Uart_SendString(u8 *Local_u8_DataString)
{
	u8 Local_u8_StrSize = sizeof(Local_u8_DataString)/ sizeof(Local_u8_DataString[0]);
	u8 Local_u8_Cnt = 0;
	for(Local_u8_Cnt = 0; Local_u8_Cnt < Local_u8_StrSize; Local_u8_Cnt++)
	{
		M_Uart_Send(Local_u8_DataString[Local_u8_Cnt]);
	}
	//M_Uart_Send('\r');
	M_Uart_Send('\n');
}

u8   M_Uart_Receive()
{
	while(  GetBit(UCSR0A, 7) == 0 );
	return UDR0;
}