#ifndef __CONTROL_H
#define __CONTROL_H
#define MAX_SPEED_UP 40
#include "pid_v.h"
#include "xunji.h"

void Car_Go(int AD);
void Car_Back(int AD);
void Car_Right(int AD);
void Car_Right_Inplace(void);
void Car_Right_Small(void);
void Car_Right_Med(void);
void Car_Right_Big(void);
void Car_Left_Inplace(void);
void Car_Left_Big(void);
void Car_Left_Med(void);
void Car_Left_Small(void);
void Car_Left(int AD);
void Car_Stop(void);
void Car_Road_Left(int nms);
void Car_Road_Left_xunji(int nms);
void Car_Road_Right(int nms);
void Car_Road_Right_xunji(int nms);
void Car_Go_Little(int nms);
void Car_Back_Little(int nms);
void Car_Go_Set(void); // 直走

#endif
