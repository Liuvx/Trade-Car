#ifndef __HMI_H
#define __HMI_H

#include "my_uart.h"
#include "SU03T.h"

extern int target_val_1;
extern int target_val_2;
extern int target_val_3;
extern int Xunji_State;
extern int Left_Num;
extern int Right_Num;
extern int coins;
extern int coin_need;
extern int pay_open;

void Read_Hand(void);
void HMI_Start(void);
void HMI_Pay(void);
void Coin_Count(void);
void HMI_Back(void);
void HMI_print(int NUM);
void HMI_get(void);
void HMI_print_achieve(int NUM);

#endif
