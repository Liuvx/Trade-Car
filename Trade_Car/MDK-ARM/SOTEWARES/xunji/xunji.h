#ifndef __XUNJI_H
#define __XUNJI_H

#include "main.h"
#include "beep.h"
#include "control.h"
#include "HMI.h"
#include "SU03T.h"
#define Read_R4 HAL_GPIO_ReadPin(R4_GPIO_Port, R4_Pin)
#define Read_R3 HAL_GPIO_ReadPin(R3_GPIO_Port, R4_Pin)
#define Read_R2 HAL_GPIO_ReadPin(R2_GPIO_Port, R2_Pin)
#define Read_R1 HAL_GPIO_ReadPin(R1_GPIO_Port, R1_Pin)
// #define Read_M HAL_GPIO_ReadPin(M_GPIO_Port, M_Pin)
#define Read_L1 HAL_GPIO_ReadPin(L1_GPIO_Port, L1_Pin)
#define Read_L2 HAL_GPIO_ReadPin(L2_GPIO_Port, L2_Pin)
#define Read_L3 HAL_GPIO_ReadPin(L3_GPIO_Port, L3_Pin)
#define Read_L4 HAL_GPIO_ReadPin(L4_GPIO_Port, L4_Pin)

extern int Xunji_State;
extern int Stop_Num;
extern int Car_Back_number;
extern int target_val_1;
extern int target_val_2;
extern int target_val_3;
extern int road;
extern int Left_Num;
extern int Right_Num;
extern int su_03_stop;
extern int MEI_Num;
extern int NAN_Num;
extern int JIU_Num;
extern int bizhang_num;
extern int bizhang_num_2;
extern int bizhang_num_3;

uint16_t Read_Huidu(void);
void Xunji(int car_state);
#endif
