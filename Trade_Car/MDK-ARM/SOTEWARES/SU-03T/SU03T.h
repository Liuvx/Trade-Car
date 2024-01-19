#ifndef __SU03T_H
#define __SU03T_H

#include "my_uart.h"
#include "control.h"

extern int target_val_1;
extern int Xunji_State;
extern int Left_Num;
extern int Right_Num;

void SU03T_Go(void);
void SU03T_get(void);
void SU03T_arrive(int val);
void SU03T_back(void);
void SU03T_Next_GO(void);
void SU03T_GO_meizhou(void);
void SU03T_GO_nanri(void);
void SU03T_GO_jiuli(void);
void SU03T_Pass_nanri(void);
void SU03T_Pay(void);
void SU03T_Stop(void);
#endif
