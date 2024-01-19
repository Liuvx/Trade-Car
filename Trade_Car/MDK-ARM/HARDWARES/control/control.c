#include "control.h"
#include "stdio.h"
extern uint32_t Car_State;
extern uint32_t Stop_Immediately;
extern int Car_Back_number;
// int Motor1_Turn = 0;
// int Motor2_Turn = 0;
int Start_Speed = 10;
int Turn_Speed = 2;
int Turn_Med_Speed = 4;
int Turn_Big_Speed = 6;
int Sets = 1300; // ms
// extern uint32_t MAX_SPEED_UP;
void Car_Stop(void)
{

    pidMotor1Speed.target_val = 0;
    pidMotor2Speed.target_val = 0;

    pidMotor1Speed.err_sum = 0;
    pidMotor2Speed.err_sum = 0;
    // HAL_Delay(20);
}

void Car_Go(int AD)
{
    pidMotor1Speed.target_val = Start_Speed + AD;
    pidMotor2Speed.target_val = Start_Speed + AD;

    // motorPidSetSpeed(15, 15);
}
void Car_Back(int AD)
{
    pidMotor1Speed.target_val = -Start_Speed + AD;
    pidMotor2Speed.target_val = -Start_Speed + AD;

    // motorPidSetSpeed(0, 0);
    // motorPidSetSpeed(-15, -15);
}
void Car_Left_Small(void)
{
    // pidMotor1Speed.target_val = Start_Speed+AD - Turn_Big_Speed;
    pidMotor1Speed.target_val = Start_Speed;

    pidMotor2Speed.target_val = Start_Speed + Turn_Speed;
}
void Car_Left_Med(void)
{
    // pidMotor1Speed.target_val = Start_Speed+AD - Turn_Big_Speed;
    pidMotor1Speed.target_val = Start_Speed;
    pidMotor2Speed.target_val = Start_Speed + Turn_Med_Speed;
}
void Car_Left_Big(void)
{
    // pidMotor1Speed.target_val = Start_Speed+AD - Turn_Big_Speed;
    pidMotor1Speed.target_val = Start_Speed;
    pidMotor2Speed.target_val = Start_Speed + Turn_Big_Speed;
}
void Car_Left(int AD)
{
    // pidMotor1Speed.target_val = Start_Speed+AD - Turn_Speed;
    pidMotor1Speed.target_val = -(Start_Speed + AD);
    pidMotor2Speed.target_val = (Start_Speed + AD);
}
void Car_Left_Inplace(void)
{
    pidMotor1Speed.target_val = -Start_Speed;
    pidMotor2Speed.target_val = +Start_Speed;
    // motorPidSetSpeed(0, 0);
    // motorPidSetSpeed(-15, 15);
}
void Car_Right_Small(void)
{
    pidMotor1Speed.target_val = Start_Speed + Turn_Speed;
    pidMotor2Speed.target_val = Start_Speed;
}
void Car_Right_Med(void)
{
    pidMotor1Speed.target_val = Start_Speed + Turn_Med_Speed;
    pidMotor2Speed.target_val = Start_Speed;
}
void Car_Right_Big(void)
{

    pidMotor1Speed.target_val = Start_Speed + Turn_Big_Speed;
    pidMotor2Speed.target_val = Start_Speed;
}
void Car_Right(int AD)
{
    pidMotor1Speed.target_val = Start_Speed + AD;
    // pidMotor2Speed.target_val = Start_Speed+AD - Turn_Speed;
    pidMotor2Speed.target_val = -(Start_Speed + AD);
}
void Car_Right_Inplace(void)
{
    pidMotor1Speed.target_val = +Start_Speed;
    pidMotor2Speed.target_val = -Start_Speed;
    // motorPidSetSpeed(0, 0);
    // motorPidSetSpeed(15, -15);
}
void Car_Road_Left(int nms)
{
   // printf("Car_Road_Left\r\n");
    pidMotor1Speed.target_val = -Start_Speed;
    pidMotor2Speed.target_val = +Start_Speed;

    HAL_Delay(nms);

    Car_Stop();
    HAL_Delay(20);
}
void Car_Road_Left_xunji(int nms)
{
    //printf("Car_Road_Left\r\n");
    pidMotor1Speed.target_val = -Start_Speed;
    pidMotor2Speed.target_val = +Start_Speed;

    HAL_Delay(nms);
   
    Car_Stop();
    HAL_Delay(20);
}
void Car_Road_Right(int nms) // 路口右转
{
   // printf("Car_Road_Right\r\n");
    pidMotor1Speed.target_val = +Start_Speed;
    pidMotor2Speed.target_val = -Start_Speed;
    HAL_Delay(nms);

    Car_Stop();
    HAL_Delay(20);
}
void Car_Road_Right_xunji(int nms) // 路口右转
{
    //printf("Car_Road_Right\r\n");
    pidMotor1Speed.target_val = +Start_Speed;
    pidMotor2Speed.target_val = -Start_Speed;
    HAL_Delay(nms-200);
   
    Car_Stop();
    HAL_Delay(20);
}
void Car_Go_Little(int nms) // 直走
{
    //printf("Car_Go_Little、\r\n");
    pidMotor1Speed.target_val = Start_Speed;
    pidMotor2Speed.target_val = Start_Speed;
    HAL_Delay(nms);
    Car_Stop();
    HAL_Delay(10);
}
void Car_Back_Little(int nms)
{
    pidMotor1Speed.target_val = -Start_Speed;
    pidMotor2Speed.target_val = -Start_Speed;
    HAL_Delay(nms);
    Car_Stop();
    HAL_Delay(10);
}
void Car_Go_Set(void) // 直走
{
   // printf("Car_Go_Little、\r\n");
    pidMotor1Speed.target_val = Start_Speed;
    pidMotor2Speed.target_val = Start_Speed;
    HAL_Delay(Sets);
    Car_Stop();
    HAL_Delay(10);
}
