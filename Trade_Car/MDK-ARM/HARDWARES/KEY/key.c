#include "key.h"
#include "beep.h"
#include "stm32f4xx_it.h"
extern int Key_Num;
int Read_Key(void) // 输入模式
{
    int Key_Num;
    if (Read_Key1 == 0)
    {
        HAL_Delay(20);
        while (Read_Key1 == 0)
            HAL_Delay(20);
        Key_Num = 1;
    }
    else if (Read_Key2 == 0)
    {
        HAL_Delay(20);
        while (Read_Key2 == 0)
            HAL_Delay(20);
        Key_Num = 2;
    }
    else if (Read_Key3 == 0)
    {
        HAL_Delay(20);
        while (Read_Key3 == 0)
            HAL_Delay(20);
        Key_Num = 3;
    }
    else if (Read_Key4 == 0)
    {
        HAL_Delay(20);
        while (Read_Key4 == 0)
            HAL_Delay(20);
        Key_Num = 4;
    }
    else
        Key_Num = 0;
    return Key_Num;
}
