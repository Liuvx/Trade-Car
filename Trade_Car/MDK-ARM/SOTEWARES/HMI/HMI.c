#include "HMI.h"
int target_val_1_read = 0;
int target_val_2_read = 0;
int target_val_3_read = 0;

void HMI_Start(void)
{
    // target_val_1 = 0;
    u2_printf("page page0\xff\xff\xff");
}
void HMI_Back(void)
{
    // target_val_1 = 0;
    u2_printf("page page1\xff\xff\xff");
}
void HMI_Pay(void)
{
    // target_val_1 = 0;
    u2_printf("page page3\xff\xff\xff");
}
void HMI_print(int NUM)
{
    u2_printf("page x%d\xff\xff\xff", NUM);
}
void HMI_print_achieve(int NUM)
{
    u2_printf("page x%d_s\xff\xff\xff", NUM);
}
void Coin_Count(void)
{
    if (target_val_3 != 0)
    {
      switch(target_val_3)
			{
				case 1:
					coin_need=coin_need + 3;
				break;
				case 2:
					coin_need=coin_need + 2;
				break;
				case 3:
					coin_need=coin_need + 3;
				break;
				default:
					break;
    }
	}
    else if (target_val_2 != 0)
    {
        switch(target_val_2)
			{
				case 1:
					coin_need=coin_need + 3;
				break;
				case 2:
					coin_need=coin_need + 2;
				break;
				case 3:
					coin_need=coin_need + 3;
				break;
				default:
					break;
    }
	}
    else if (target_val_1 != 0)
    {
			switch(target_val_1)
			{
				case 1:
					coin_need = 3;
				break;
				case 2:
					coin_need = 2;
				break;
				case 3:
					coin_need = 3;
				break;
				default:
					break;
			}
        
    }
    u2_printf("coin=%d\xff\xff\xff", coin_need);
}
void HMI_get(void)
{
    if ((USART2_RX_STA & 0x8000))
    {
        LED_text;
        if (USART2_RX_BUF[0] == 0x58) // 出发地点接受
        {
            target_val_1 = USART2_RX_BUF[1] - 48;
            target_val_2 = USART2_RX_BUF[2] - 48;
            target_val_3 = USART2_RX_BUF[3] - 48;
            coin_need = USART2_RX_BUF[4] - 48;
        }
        if (USART2_RX_BUF[0] == 0x51) // 清0
        {
            if (USART2_RX_BUF[1] == 0x30)
            {
                coins = 0;
                coin_need = 0;
                target_val_1 = 0;
                target_val_2 = 0;
                target_val_3 = 0;
            }
            if (USART2_RX_BUF[1] == 0x31) // 进入支付界面
            {
                pay_open = 1;
                SU03T_Pay();
            }
        }

        USART2_RX_STA = 0;
    }
}
void Read_Hand(void) // 判断是否挥手,仅在停车且串口屏上显示投币时可使用
{
    if (Xunji_State == 0)
    {
        if (pay_open == 1)
        {
            if (HAL_GPIO_ReadPin(HAND_GPIO_Port, HAND_Pin) == 0)
            {
							
                coins = coins + 1;
                LED_text;
                u2_printf("coin_now=%d\xff\xff\xff", coins);
							HAL_Delay(1000);
                
            }
        }
    }
}
