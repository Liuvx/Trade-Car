#include "motor.h"

void Motor_L_Set(int Motor_L) // 左电机控制
{
    if (Motor_L < 0)
    {
        L2FRESET;
        L1FSET;
    }
    if (Motor_L > 0)
    {
        L2FSET;
        L1FRESET;
    }
    if (Motor_L == 0)
    {
        L2FRESET;
        L1FRESET;
    }

    if (Motor_L < 0)
    {
        if (Motor_L < -7000)
            Motor_L = -7000;
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, -Motor_L);
    }
    if (Motor_L > 0)
    {
        if (Motor_L > 7000)
            Motor_L = 7000;
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, Motor_L);
    }
}
void Motor_R_Set(int Motor_R) // 右电机控制
{
    if (Motor_R > 0)
    {
        R2FRESET;
        R1FSET;
    }
    if (Motor_R < 0)
    {
        R2FSET;
        R1FRESET;
    }
    if (Motor_R == 0)
    {
        R2FRESET;
        R1FRESET;
    }

    if (Motor_R < 0)
    {
        if (Motor_R < -7000)
            Motor_R = -7000;
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, -Motor_R);
    }
    if (Motor_R > 0)
    {
        if (Motor_R > 7000)
            Motor_R = 7000;
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, Motor_R);
    }
}
