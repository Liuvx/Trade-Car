#include "my_uart.h"
#include "usart.h"
#include "stdio.h"
#include "string.h"
#include "stdarg.h"
// #include "control.h"
uint8_t USART1_RX_Data;
uint8_t USART1_TX_BUF[USART1_MAX_SEND_LEN];
uint16_t USART1_RX_BUF[USART1_MAX_Receive_LEN];
uint16_t USART1_RX_STA;

uint8_t USART3_RX_Data;
uint8_t USART3_TX_BUF[USART3_MAX_SEND_LEN];
uint16_t USART3_RX_BUF[USART3_MAX_Receive_LEN];
uint16_t USART3_RX_STA;

uint8_t USART2_RX_Data;
uint8_t USART2_TX_BUF[USART2_MAX_SEND_LEN];
uint16_t USART2_RX_BUF[USART2_MAX_Receive_LEN];
uint16_t USART2_RX_STA;

// 串口中断函数
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1) // 蓝牙串口
    {
        // LED_text;
        if ((USART1_RX_STA & 0x8000) == 0) // 接收未完成
        {
            if ((USART1_RX_STA & 0x4000)) // 接收到了0xfe
            {
                if (USART1_RX_Data != 0x0c)
                {
                    USART1_RX_STA &= 0x3fff;
                    USART1_RX_BUF[USART1_RX_STA++] = 0x0c;
                    USART1_RX_BUF[USART1_RX_STA++] = USART1_RX_Data; // 防止数据中出现0xfe到时丢失数据
                }
                else
                {
                    // HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
                    USART1_RX_STA |= 0x8000; // 接收完成
                }
            }
            else
            {
                if (USART1_RX_Data == 0x0b)
                {
                    USART1_RX_STA |= 0x4000; // 接受到了0xfe
                }
                else
                {
                    USART1_RX_BUF[USART1_RX_STA & 0x3fff] = USART1_RX_Data;
                    USART1_RX_STA++;
                    if (USART1_RX_STA > (USART1_MAX_Receive_LEN - 1)) // 超出数据长度
                    {
                        USART1_RX_STA = 0;
                    }
                }
            }
            // u3_printf("%c",USART1_RX_BUF[0]);
        }
        HAL_UART_Receive_IT(&huart1, &USART1_RX_Data, 1);
    }
    if (huart->Instance == USART2) // 串口屏串口
    {
        
        if ((USART2_RX_STA & 0x8000) == 0) // 接收未完成
        {
            if ((USART2_RX_STA & 0x4000)) // 接收到了0xfe
            {
                if (USART2_RX_Data != 0x0c)
                {
                    USART2_RX_STA &= 0x3fff;
                    USART2_RX_BUF[USART2_RX_STA++] = 0x0c;
                    USART2_RX_BUF[USART2_RX_STA++] = USART2_RX_Data; // 防止数据中出现0xfe到时丢失数据
                }
                else
                {
                    // HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
                    USART2_RX_STA |= 0x8000; // 接收完成
                }
            }
            else
            {
                if (USART2_RX_Data == 0x0b)
                {
                    USART2_RX_STA |= 0x4000; // 接受到了0xfe
                }
                else
                {
                    USART2_RX_BUF[USART2_RX_STA & 0x3fff] = USART2_RX_Data;
                    USART2_RX_STA++;
                    if (USART2_RX_STA > (USART2_MAX_Receive_LEN - 1)) // 超出数据长度
                    {
                        USART2_RX_STA = 0;
                    }
                }
            }
            // u3_printf("%c",USART3_RX_BUF[0]);
        }
        HAL_UART_Receive_IT(&huart2, &USART2_RX_Data, 1);
    }
    if (huart->Instance == USART3) // SU-03串口
    {
       
        if ((USART3_RX_STA & 0x8000) == 0) // 接收未完成
        {
            if ((USART3_RX_STA & 0x4000)) // 接收到了0xfe
            {
                if (USART3_RX_Data != 0x0c)
                {
                    USART3_RX_STA &= 0x3fff;
                    USART3_RX_BUF[USART3_RX_STA++] = 0x0c;
                    USART3_RX_BUF[USART3_RX_STA++] = USART3_RX_Data; // 防止数据中出现0xfe到时丢失数据
                }
                else
                {
                    // HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
                    USART3_RX_STA |= 0x8000; // 接收完成
                }
            }
            else
            {
                if (USART3_RX_Data == 0x0b)
                {
                    USART3_RX_STA |= 0x4000; // 接受到了0xfe
                }
                else
                {
                    USART3_RX_BUF[USART3_RX_STA & 0x3fff] = USART3_RX_Data;
                    USART3_RX_STA++;
                    if (USART3_RX_STA > (USART3_MAX_Receive_LEN - 1)) // 超出数据长度
                    {
                        USART3_RX_STA = 0;
                    }
                }
            }
            // u3_printf("%c",USART3_RX_BUF[0]);
        }
        HAL_UART_Receive_IT(&huart3, &USART3_RX_Data, 1);
    }
}
// 串口1的printf直接使用printf即可
void u3_printf(char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vsprintf((char *)USART3_TX_BUF, fmt, ap);
    va_end(ap);
    HAL_UART_Transmit(&huart3, USART3_TX_BUF, strlen((const char *)USART3_TX_BUF), HAL_MAX_DELAY);
}
void u2_printf(char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vsprintf((char *)USART2_TX_BUF, fmt, ap);
    va_end(ap);
    HAL_UART_Transmit(&huart2, USART2_TX_BUF, strlen((const char *)USART2_TX_BUF), HAL_MAX_DELAY);
}
