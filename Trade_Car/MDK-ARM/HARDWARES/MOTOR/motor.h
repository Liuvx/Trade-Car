#ifndef __MOTOR_H
#define __MOTOR_H
#include "main.h"
#include "tim.h"

// AIN控制左边，BIN控制右边
// motor1为左边，motor2为右边

// 前面
#define Motor_L_1_F_Port GPIOE
#define Motor_L_2_F_Port GPIOG
#define Motor_L_1_F_Pin GPIO_PIN_15
#define Motor_L_2_F_Pin GPIO_PIN_4 // 左边轮子

#define Motor_R_1_F_Port GPIOE
#define Motor_R_2_F_Port GPIOE
#define Motor_R_1_F_Pin GPIO_PIN_12
#define Motor_R_2_F_Pin GPIO_PIN_10 // 右边轮子

#define L1FRESET HAL_GPIO_WritePin(Motor_L_1_F_Port, Motor_L_1_F_Pin, GPIO_PIN_RESET)
#define L1FSET HAL_GPIO_WritePin(Motor_L_1_F_Port, Motor_L_1_F_Pin, GPIO_PIN_SET)
#define L2FRESET HAL_GPIO_WritePin(Motor_L_2_F_Port, Motor_L_2_F_Pin, GPIO_PIN_RESET) // 电机1
#define L2FSET HAL_GPIO_WritePin(Motor_L_2_F_Port, Motor_L_2_F_Pin, GPIO_PIN_SET)

#define R1FRESET HAL_GPIO_WritePin(Motor_R_1_F_Port, Motor_R_1_F_Pin, GPIO_PIN_RESET)
#define R1FSET HAL_GPIO_WritePin(Motor_R_1_F_Port, Motor_R_1_F_Pin, GPIO_PIN_SET)
#define R2FRESET HAL_GPIO_WritePin(Motor_R_2_F_Port, Motor_R_2_F_Pin, GPIO_PIN_RESET) // 电机2
#define R2FSET HAL_GPIO_WritePin(Motor_R_2_F_Port, Motor_R_2_F_Pin, GPIO_PIN_SET)
void Motor_L_Set(int Motor_L);
void Motor_R_Set(int Motor_R);
#endif
