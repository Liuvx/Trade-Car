#include "SR04.H"

double SR04_Getdistance(void) // 超声波
{

    double distance = 0.00;
    SR04_Start = 0;
    SR04_End = 0;
    SR04_Count = 0;
    HAL_GPIO_WritePin(SR04OUT_GPIO_Port, SR04OUT_Pin, GPIO_PIN_SET); // 写1
    HAL_Delay(1);
    HAL_GPIO_WritePin(SR04OUT_GPIO_Port, SR04OUT_Pin, GPIO_PIN_RESET); // 写0
    while (!Read_SR04)
    {
    }
    SR04_Count = 0;
    while (Read_SR04)
    {
    }
    SR04_End = SR04_Count;
    distance = SR04_End * 0.17;
    return distance;
}
