/*
 * Uart.h
 *
 * Created: 6/29/2022 9:32:57 AM
 *  Author: mahdy
 */ 


#ifndef UART_H_
#define UART_H_


/*********************************_INCLUDES_*********************************/

#include "UartCfg.h"
#include "Reg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Dio.h"

/*********************************_MACROS_*********************************/

/*********************************_PROTOTYPE_*********************************/

void M_Uart_Init(u32);
void M_Uart_Send(u8);
void M_Uart_SendString(u8*);
u8   M_Uart_Receive();



#endif /* UART_H_ */