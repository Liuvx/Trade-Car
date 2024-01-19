#ifndef __SR04_H
#define __SR04_H

#include "main.h"

extern int TimerCount;
extern int SR04_Start;
extern int SR04_End;
extern int SR04_Count;

#define Read_SR04 HAL_GPIO_ReadPin(SR04IN_GPIO_Port, SR04IN_Pin)

double SR04_Getdistance(void);

#endif
