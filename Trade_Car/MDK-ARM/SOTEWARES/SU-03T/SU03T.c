#include "SU03T.h"

void SU03T_Pay(void) // 需要支付
{
    u3_printf("%c%c%c%c%c%c", 0xAA, 0x55, 0x09, 0X2C, 0x55, 0xAA);
}
void SU03T_get(void) // SU03语音接受
{
    if ((USART3_RX_STA & 0x8000))
    {
        LED_text;
        if (USART3_RX_BUF[0] == 0x58)
        {
            if (target_val_1 != 0)
            {
                if (target_val_2 == 0)
                {
                    target_val_2 = USART3_RX_BUF[1] - 48;
                    Coin_Count();
                    Xunji_State = 0;
                    Car_Stop();
                    HAL_Delay(10);
                    HMI_Pay();
                    // SU03T_Pay();

                    // coin_need = 2;
                }
                else if (target_val_3 == 0)
                {
                    target_val_3 = USART3_RX_BUF[1] - 48;
                    Coin_Count();
                    Xunji_State = 0;
                    Car_Stop();
                    HAL_Delay(10);
                    // SU03T_Pay();
                    HMI_Pay();
                    // coin_need = 3;
                }
            }
        }
        USART3_RX_STA = 0;
    }
}
void SU03T_Go(void)
{
    Car_Stop();
    if ((USART3_RX_STA & 0x8000))
    {
        LED_text;
        if (USART3_RX_BUF[0] == 0x58) // x
        {
            if (USART3_RX_BUF[1] == 0x47) // G
            {

                su_03_stop = 1;
            }
        }
        USART3_RX_STA = 0;
    }
}
void SU03T_arrive(int val) // AA 55 XX XX 55 AA,到达目的地
{
    switch (val)
    {
    case 1:
        u3_printf("%c%c%c%c%c%c", 0xAA, 0x55, 0x0A, 0X2C, 0x55, 0xAA);
        HAL_Delay(28000);
        break;
    case 2:
        u3_printf("%c%c%c%c%c%c", 0xAA, 0x55, 0x0B, 0X2C, 0x55, 0xAA);
		HAL_Delay(20000);
        break;
    case 3:
        u3_printf("%c%c%c%c%c%c", 0xAA, 0x55, 0x0C, 0X2C, 0x55, 0xAA);
		HAL_Delay(30000);
        break;
    default:
        break;
    }
}
void SU03T_back(void)
{
    u3_printf("%c%c%c%c%c%c", 0xAA, 0x55, 0x01, 0X2C, 0x55, 0xAA);
}
void SU03T_Next_GO(void) // 前往下一个地点
{
    u3_printf("%c%c%c%c%c%c", 0xAA, 0x55, 0x02, 0X2C, 0x55, 0xAA);
}
void SU03T_Stop(void)
{
    if ((USART3_RX_STA & 0x8000))
    {
        LED_text;
        if (USART3_RX_BUF[0] == 0x53) // S
        {
            if (USART3_RX_BUF[0] == 0x33)
            {
                Car_Stop();
                Xunji_State = 0;
                u3_printf("%c%c%c%c%c%c", 0xAA, 0x55, 0x03, 0X2C, 0x55, 0xAA);
            }
        }
        USART3_RX_STA = 0;
    }
}
void SU03T_GO_meizhou(void) // 语言播报前往湄洲岛
{
    u3_printf("%c%c%c%c%c%c", 0xAA, 0x55, 0x05, 0X2C, 0x55, 0xAA);
}
void SU03T_GO_nanri(void) // 语言播报前往南日岛
{
    u3_printf("%c%c%c%c%c%c", 0xAA, 0x55, 0x06, 0X2C, 0x55, 0xAA);
}
void SU03T_GO_jiuli(void) // 语言播报前往九鲤湖
{
    u3_printf("%c%c%c%c%c%c", 0xAA, 0x55, 0x07, 0X2C, 0x55, 0xAA);
}
void SU03T_Pass_nanri(void) // 语言播报经过南日岛
{
    u3_printf("%c%c%c%c%c%c", 0xAA, 0x55, 0x08, 0X2C, 0x55, 0xAA);
}
