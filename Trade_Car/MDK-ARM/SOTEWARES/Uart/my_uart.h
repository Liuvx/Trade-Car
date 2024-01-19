#ifndef __MY_UART_H__
#define __MY_UART_H__
#include "main.h"
#define USART1_MAX_SEND_LEN 100
#define USART1_MAX_Receive_LEN 100

#define USART3_MAX_SEND_LEN 100
#define USART3_MAX_Receive_LEN 100

#define USART2_MAX_SEND_LEN 100
#define USART2_MAX_Receive_LEN 100

extern uint8_t USART1_TX_BUF[USART1_MAX_SEND_LEN];
extern uint16_t USART1_RX_BUF[USART1_MAX_Receive_LEN];
extern uint8_t USART1_RX_Data;
extern uint16_t USART1_RX_STA;

extern uint8_t USART3_TX_BUF[USART3_MAX_SEND_LEN];
extern uint16_t USART3_RX_BUF[USART3_MAX_Receive_LEN];
extern uint8_t USART3_RX_Data;
extern uint16_t USART3_RX_STA;

extern uint8_t USART2_TX_BUF[USART2_MAX_SEND_LEN];
extern uint16_t USART2_RX_BUF[USART2_MAX_Receive_LEN];
extern uint8_t USART2_RX_Data;
extern uint16_t USART2_RX_STA;

void u3_printf(char *fmt, ...);
void u2_printf(char *fmt, ...);

#endif
