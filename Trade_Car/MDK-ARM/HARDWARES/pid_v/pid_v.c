#include "pid_v.h"
#define PID_OUT_MAX 4000
#define PID_OUT_MIN -4000
// ��1
// ����һ���ṹ�����ͱ���
tPid pidMotor1Speed;
tPid pidMotor2Speed;
tPid pidMotor3Speed;
tPid pidMotor4Speed;

extern short Encoder1Count;
extern short Encoder2Count;
extern float mileage_motor1_all;
extern float mileage_motor2_all;

void PID_init()
{
    pidMotor1Speed.actual_val = 0.0;
    pidMotor1Speed.target_val = 0;
    pidMotor1Speed.err = 0.0;
    pidMotor1Speed.err_last = 0.0;
    pidMotor1Speed.err_sum = 0.0;
    pidMotor1Speed.Kp = 30;
    pidMotor1Speed.Ki = 15;
    pidMotor1Speed.Kd = 2;

    pidMotor2Speed.actual_val = 0.0;
    pidMotor2Speed.target_val = 0;
    pidMotor2Speed.err = 0.0;
    pidMotor2Speed.err_last = 0.0;
    pidMotor2Speed.err_sum = 0.0;
    pidMotor2Speed.Kp = 30;
    pidMotor2Speed.Ki = 15;
    pidMotor2Speed.Kd = 2;
}

float PID_realize(tPid *pid, float actual_val)
{
    pid->actual_val = actual_val;                   // ������ʵֵ
    pid->err = (pid->target_val) - pid->actual_val; ////��ǰ���=Ŀ��ֵ-��ʵֵ
                                                    //     if (pid->err >-5 && pid->err < 5)
                                                    //     pid->err = 0;
    pid->err_sum += pid->err;                       // ����ۼ�ֵ = ��ǰ����ۼ�
    if ((pid->err_sum > PID_OUT_MAX / pid->Ki) && (pid->target_val != 0))
        pid->err_sum = PID_OUT_MAX / pid->Ki;
    if ((pid->err_sum < PID_OUT_MIN / pid->Ki) && (pid->target_val != 0))
        pid->err_sum = PID_OUT_MIN / pid->Ki; // �����޷�*/

    // ʹ��PID���� ��� = Kp*��ǰ���  +  Ki*����ۼ�ֵ + Kd*(��ǰ���-�ϴ����)
    pid->actual_val = pid->Kp * pid->err + pid->Ki * pid->err_sum + pid->Kd * (pid->err - pid->err_last);
    // �����ϴ����: �����ֵ���ϴ����
    pid->err_last = pid->err;
    if (actual_val > PID_OUT_MAX)
        actual_val = PID_OUT_MAX;
    if (actual_val < PID_OUT_MIN)
        actual_val = PID_OUT_MIN;
    //	if(pid->target_val==0)
    //		pid->actual_val=0;
    return pid->actual_val;
}

void motor1PidSetSpeed(float Motor1SetSpeed)
{
    // �ı���PID������Ŀ���ٶ�
    pidMotor1Speed.target_val = Motor1SetSpeed;
}
void motor2PidSetSpeed(float Motor2SetSpeed)
{
    pidMotor2Speed.target_val = Motor2SetSpeed;
}
void motor3PidSetSpeed(float Motor3SetSpeed)
{
    pidMotor3Speed.target_val = Motor3SetSpeed;
}
void motor4PidSetSpeed(float Motor4SetSpeed)
{
    pidMotor4Speed.target_val = Motor4SetSpeed;
}
