#ifndef __PID_V_H
#define __PID_V_H
// #include "main.h"
#include "motor.h"

typedef struct
{
  float target_val; // Ŀ��ֵ
  float actual_val; // ʵ��ֵ
  float err;        // ��ǰƫ��
  float err_last;   // �ϴ�ƫ��
  float err_sum;    // ����ۼ�ֵ
  float Kp, Ki, Kd; // ���������֣�΢��ϵ��

} tPid;

extern tPid pidMotor1Speed;
extern tPid pidMotor2Speed;
extern tPid pidMotor3Speed;
extern tPid pidMotor4Speed;
extern tPid Xunji_pid_Group;
extern tPid Motor1_Distance;
extern tPid Motor2_Distance;

void PID_init(void);
float PID_realize(tPid *pid, float actual_val);
void motor1PidSetSpeed(float Motor1SetSpeed);
void motor2PidSetSpeed(float Motor2SetSpeed);
void motor3PidSetSpeed(float Motor3SetSpeed);
void motor4PidSetSpeed(float Motor4SetSpeed);

#endif
