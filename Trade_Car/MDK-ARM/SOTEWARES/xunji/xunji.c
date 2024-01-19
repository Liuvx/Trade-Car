#include "xunji.h"
#include <string.h>
#include "stdio.h"

uint16_t Read_Huidu(void)
{
    uint16_t temp = 0;
    if (HAL_GPIO_ReadPin(L4_GPIO_Port, L4_Pin) == GPIO_PIN_RESET)
    {
        temp |= 0x80;
    }
    if (HAL_GPIO_ReadPin(L3_GPIO_Port, L3_Pin) == GPIO_PIN_RESET)
    {
        temp |= 0x40;
    }
    if (HAL_GPIO_ReadPin(L2_GPIO_Port, L2_Pin) == GPIO_PIN_RESET)
    {
        temp |= 0x20;
    }
    if (HAL_GPIO_ReadPin(L1_GPIO_Port, L1_Pin) == GPIO_PIN_RESET)
    {
        temp |= 0x10;
    }

    if (HAL_GPIO_ReadPin(R1_GPIO_Port, R1_Pin) == GPIO_PIN_RESET)
    {
        temp |= 0x08;
    }
    if (HAL_GPIO_ReadPin(R2_GPIO_Port, R2_Pin) == GPIO_PIN_RESET)
    {
        temp |= 0x04;
    }
    if (HAL_GPIO_ReadPin(R3_GPIO_Port, R3_Pin) == GPIO_PIN_RESET)
    {
        temp |= 0x02;
    }
    if (HAL_GPIO_ReadPin(R4_GPIO_Port, R4_Pin) == GPIO_PIN_RESET)
    {
        temp |= 0x01;
    }
    return temp;
}

void Xunji(int Huidu_State)
{

    if (Xunji_State) // 如果是寻迹模式的话
    {

        switch (Huidu_State)
        {
        case 0: // 全白线
                // while()
                // printf("0\r\n");

            if (road == 3) // 返回起点全靠这里
            {
                if (Stop_Num == 1)
                {
                    // Car_Back_Little(200);
                    if (Car_Back_number == 1) // 掉头后再次寻迹，直到再次检测到白线停止
                    {
                        road = 1;
                        HMI_Start();
                        Car_Stop();
                        Stop_Num = 0;
                        Left_Num = 0;
                        Right_Num = 0;
                        su_03_stop = 0;
                        Car_Back_number = 0;
													bizhang_num = 0;
												bizhang_num_2 = 0;
													bizhang_num_3 = 0;
                        Xunji_State = 0; // 关闭寻迹模式
                    }
                    if (Car_Back_number == 0) // 当第二次全部检测到白线时开始掉头
                    {

                        Car_Back_number = 1;
                    }
                }
                if (Stop_Num == 0) // 第一次检测到白线，再前走一段距离防止误触发
                {
                    Car_Go_Little(200);
                    Stop_Num = 1;
                }
            }
            else
                Car_Go(0);

            break;

        case 1: // 0000 0001
            Car_Right_Big();
            Stop_Num = 0;
            break;
        case 2:
            Car_Right_Med();
            Stop_Num = 0;
            break;
        case 3:
            Car_Right_Big();
            Stop_Num = 0;
            break;
        case 4:
            Car_Right_Small();
            Stop_Num = 0;
            break;
        case 6:
            Car_Right_Small();
            Stop_Num = 0;
            break;
        /*case 7: // 右转
            // printf("7\r\n");
            switch (Right_Num) // 第一次检测到7时
            {
            case 0:
                switch (road)
                {
                case 2:
                    switch (target_val_1)
                    {
                    case 1:
                        Car_Go_Set();
                        Car_Road_Right_xunji(1000);
                        ++Right_Num;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 3:
                    switch (target_val_1)
                    {
                    case 2:
                        Car_Go(0);
                        break;
                    case 3:
                        Car_Go_Set();
                        Car_Road_Right_xunji(1000);
                        ++Right_Num;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                }
                break;

            default:
                Car_Go(0);
                break;
            }
            Stop_Num = 0;
            break;*/
        case 8:
            Car_Go(0);
            Stop_Num = 0;
            break;
        case 12:
            Car_Right_Small();
            Stop_Num = 0;
            break;
        case 14:
            Car_Right_Med();
            Stop_Num = 0;
            break;
        case 15:
            // printf("15\r\n");
            switch (Right_Num) // 第一次检测到15时
            {
            case 0:
                switch (road)
                {
                case 2:
                    switch (target_val_1)
                    {
                    case 1:
                        Car_Go_Set();
                        Car_Road_Right_xunji(1000);
                        ++Right_Num;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 3:
                    switch (target_val_1)
                    {
                    case 2:
                        Car_Go(0);
                        break;
                    case 3:
                        Car_Go_Set();
                        Car_Road_Right_xunji(1000);
                        ++Right_Num;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 5:
                    switch (target_val_2)
                    {
                    case 3:
                        Car_Go_Set();
                        Car_Road_Right_xunji(1000);
                        ++Right_Num;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 6:
                    switch (target_val_3)
                    {
                    case 1:
                        Car_Go_Set();
                        Car_Road_Right_xunji(1000);
                        ++Right_Num;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 7:
                    switch (target_val_3)
                    {
                    case 3:
                        Car_Go_Set();
                        Car_Road_Right_xunji(1000);
                        ++Right_Num;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                default:
                    break;
                }
            default:
                Car_Go(0);
                break;
            }
            Stop_Num = 0;
            break;
        case 16:
            Car_Go(0);
            Stop_Num = 0;
            break;
        case 23:
            Car_Right_Big();
            Stop_Num = 0;
            break;
        case 24:
            Car_Go(0);
            Stop_Num = 0;
            break;
        case 28:
            Car_Right_Small();
            Stop_Num = 0;
            break;
        case 30:
            Car_Right_Med();
            Stop_Num = 0;
            break;
        case 31: // 右转
                 // printf("31\r\n");

            switch (Right_Num) // 第一次检测到31时
            {
            case 0:
                switch (road)
                {
                case 2:
                    switch (target_val_1)
                    {
                    case 1:
                        Car_Go_Set();
                        Car_Road_Right_xunji(1000);
                        ++Right_Num;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 3:
                    switch (target_val_1)
                    {
                    case 2:
                        Car_Go(0);
                        break;
                    case 3:
                        Car_Go_Set();
                        Car_Road_Right_xunji(1000);
                        ++Right_Num;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 5:
                    switch (target_val_2)
                    {
                    case 3:
                        Car_Go_Set();
                        Car_Road_Right_xunji(1000);
                        ++Right_Num;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 6:
                    switch (target_val_3)
                    {
                    case 1:
                        Car_Go_Set();
                        Car_Road_Right_xunji(1000);
                        ++Right_Num;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 7:
                    switch (target_val_3)
                    {
                    case 3:
                        Car_Go_Set();
                        Car_Road_Right_xunji(1000);
                        ++Right_Num;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                default:
                    break;
                }
            default:
                Car_Go(0);
                break;
            }
            Stop_Num = 0;
            break;
        case 32:
            Car_Left_Small();
            Stop_Num = 0;
            break;
        case 48:
            Car_Left_Small();
            Stop_Num = 0;
            break;

        case 64:
            Car_Left_Med();
            Stop_Num = 0;
            break;
        case 80:
            Car_Left_Med();
            Stop_Num = 0;
            break;
        case 96:
            Car_Left_Med();
            Stop_Num = 0;
            break;
        case 112:
            Car_Left_Med();
            Stop_Num = 0;
            break;
        case 128:
            Car_Left_Big();
            Stop_Num = 0;
            break;
        case 192:
            Car_Left_Big();
            Stop_Num = 0;
            break;
        case 224:             // 左转
                              // printf("224\r\n");
            switch (Left_Num) // 第一次检测到224时
            {
            case 0:
                switch (road)
                {
                case 2:
                    switch (target_val_1)
                    {
                    case 3:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 3:
                    switch (target_val_1)
                    {
                    case 1:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 4:
                    switch (target_val_2)
                    {
										case 1:
                    case 3:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 5:
                    switch (target_val_3)
                    {
                    case 2:
                    case 3:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 6:
                    switch (target_val_3)
                    {

                    case 3:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 7:
                    switch (target_val_3)
                    {

                    case 1:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                }
                break;

            default:
                Car_Go(0);
                break;
            }
            Stop_Num = 0;
            break;
        case 240:
            switch (Left_Num) // 第一次检测到224时
            {
            case 0:
                switch (road)
                {
                case 2:
                    switch (target_val_1)
                    {
                    case 3:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 3:
                    switch (target_val_1)
                    {
                    case 1:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 4:
                    switch (target_val_2)
                    {
										case 1:
                    case 3:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 5:
                    switch (target_val_3)
                    {
                    case 2:
                    case 3:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 6:
                    switch (target_val_3)
                    {

                    case 3:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 7:
                    switch (target_val_3)
                    {

                    case 1:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                }
                break;

            default:
                Car_Go(0);
                break;
            }
            Stop_Num = 0;
            break;
        case 241:
            Car_Left_Big();
            Stop_Num = 0;
            break;
        case 248:
            // printf("248\r\n");
            switch (Left_Num) // 第一次检测到248时
            {
            case 0:
                switch (road)
                {
                case 2:
                    switch (target_val_1)
                    {
                    case 3:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 3:
                    switch (target_val_1)
                    {
                    case 1:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 4:
                    switch (target_val_2)
                    {
										case 1:
                    case 3:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 5:
                    switch (target_val_3)
                    {
                    case 2:
                    case 3:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 6:
                    switch (target_val_3)
                    {

                    case 3:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                case 7:
                    switch (target_val_3)
                    {

                    case 1:
                        Car_Go_Set();
                        Car_Road_Left_xunji(1000);
                        Left_Num++;
                        break;
                    default:
                        Car_Go(0);
                        break;
                    }
                    break;
                }
                break;

            default:
                Car_Go(0);
                break;
            }
            Stop_Num = 0;
            break;
        case 255:
            // printf("255\r\n");
            switch (road)
            {

            case 1: // 第一个路口
                Car_Go_Set();
                switch (target_val_1)
                {
                case 1:
                    Car_Road_Left_xunji(1100);
                    road = 2;
                    break;
                case 2:
                    Car_Go_Little(200);
                    road = 2;
                    break;
                case 3:
                    Car_Road_Right_xunji(1100);
                    road = 2;
                    break;
                default:
                    break;
                }
                break;
            case 2: // 第二个路口,第一次到达目的地
                Car_Stop();
                switch (target_val_1) // 已到达输出给串口屏
                {
                case 1:
                    HMI_print_achieve(1);
                    MEI_Num = MEI_Num + 1;
                    SU03T_arrive(1);
                    break;
                case 2:
                    HMI_print_achieve(2);
                    NAN_Num = NAN_Num + 1;
                    SU03T_arrive(2);
                    break;
                case 3:
                    HMI_print_achieve(3);
                    JIU_Num = JIU_Num + 1;
                    SU03T_arrive(3);
                    break;
                default:
                    break;
                }
                if (target_val_2 != 0)
                {
                    SU03T_Next_GO();
                }
                else
                    SU03T_back();
                while (!su_03_stop)
                {
                    SU03T_Go(); // 等待语音返回
                }
                su_03_stop = 0;
                // HAL_Delay(1000);
                switch (target_val_2) // 前往第二个地点输出给串口屏
                {
                case 0:
                    HMI_Back();
                    break;
                case 1:
                    HMI_print(1);
                    SU03T_GO_meizhou();
                    break;
                case 2:
                    HMI_print(2);
                    SU03T_GO_nanri();
                    break;
                case 3:
                    HMI_print(3);
                    SU03T_GO_jiuli();
                    break;
                default:
                    break;
                }
                Car_Go_Set();
                Car_Road_Left_xunji(2000); // 掉头
                Stop_Num = 1;
                road = 3;
                break;
            case 3: // 第三个路口，判断是否有第二个目标
                Car_Go_Set();
                switch (target_val_1)
                {
                case 1: // 第一个目标是湄洲岛
                    switch (target_val_2)
                    {
                    case 0: // 没有第二个目标，返回起点
                        Car_Road_Right_xunji(1100);
                        road = 10;
                        break;
                    case 1: // 重复,没有1
                        break;
                    case 2: // 从湄洲岛前往南日岛
                        Car_Road_Left_xunji(1100);
                        Left_Num = 0;
                        Right_Num = 0;
                        road = 4;
                        break;
                    case 3: // 从湄洲岛前往九鲤湖
                        SU03T_Pass_nanri();
                        Car_Go_Little(200);
                        Left_Num = 0;
                        Right_Num = 0;
                        road = 4;
                        break;
                    default:
                        break;
                    }
                    break;
                case 2: // 第一个目标是南日岛
                    switch (target_val_2)
                    {
                    case 0: // 没有第二个目标，返回起点
                        // Car_Road_Right_xunji(1000);
                        Car_Go_Little(200);
                        road = 10;
                        break;
                    case 1: // 南日岛到湄洲岛
                        Car_Road_Right_xunji(1100);
                        Left_Num = 0;
                        Right_Num = 0;
                        road = 4;
                        break;
                    case 2: // 重复
                        break;
                    case 3: // 从南日岛前往九鲤湖
                        Car_Road_Left_xunji(1100);
                        Left_Num = 0;
                        Right_Num = 0;
                        road = 4;
                        break;
                    default:
                        break;
                    }
                    break;
                case 3: // 第一个目标是九鲤湖
                    switch (target_val_2)
                    {
                    case 0: // 没有第二个目标，返回起点
                        Car_Road_Left_xunji(1100);
                        road = 10;
                        break;
                    case 1: // 从九鲤湖前往湄洲岛
                        Car_Go_Little(200);
                        Left_Num = 0;
                        Right_Num = 0;
                        road = 4;
                        break;
                    case 2: // 从九鲤湖前往南日岛
                        Car_Road_Right_xunji(1100);
												SU03T_Pass_nanri();
                        Left_Num = 0;
                        Right_Num = 0;
                        road = 4;
                        break;

                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }
                break;
            case 4: // 第四个路口 第二次到达目的地
                Car_Stop();
                switch (target_val_2) // 已到达输出给串口屏
                {
                case 1:
                    HMI_print_achieve(1);
                    MEI_Num = MEI_Num + 1;
                    SU03T_arrive(1);
                    break;
                case 2:
                    HMI_print_achieve(2);
                    NAN_Num = NAN_Num + 1;
                    SU03T_arrive(2);
                    break;
                case 3:
                    HMI_print_achieve(3);
                    JIU_Num = JIU_Num + 1;
                    SU03T_arrive(3);
                    break;
                default:
                    break;
                }
                if (target_val_3 != 0)
                {
                    SU03T_Next_GO();
                }
                else
                    SU03T_back();
                while (!su_03_stop)
                {
                    SU03T_Go(); // 等待语音返回
                }
                su_03_stop = 0;
                switch (target_val_3) // 前往第三个地点输出给串口屏
                {
                case 0:
                    HMI_Back();
                    break;
                case 1:
                    HMI_print(1);
                    SU03T_GO_meizhou();
                    break;
                case 2:
                    HMI_print(2);
                    SU03T_GO_nanri();
                    break;
                case 3:
                    HMI_print(3);
                    SU03T_GO_jiuli();
                    break;
                default:
                    break;
                }
                Car_Go_Set();
                Car_Road_Left_xunji(2000); // 掉头
                Stop_Num = 1;
                road = 5;
                break;
            case 5: // 第五个路口，第二次返回起点，第三次开始
                Car_Go_Set();
                switch (target_val_2)
                {
                case 1: // 第二个目标是湄洲岛
                    switch (target_val_3)
                    {
                    case 0: // 没有第三个目标，返回起点
                        Car_Road_Right_xunji(1100);
                        road = 10;
                        break;
                    case 2: // 从湄洲岛前往南日岛
                        Car_Road_Left_xunji(1100);
                        Left_Num = 0;
                        Right_Num = 0;
                        road = 6;
                        break;
                    case 3: // 从湄洲岛前往九鲤湖
                        SU03T_Pass_nanri();
                        Car_Go_Little(200);
                        Left_Num = 0;
                        Right_Num = 0;
                        road = 6;
                        break;
                    default:
                        break;
                    }
                    break;
                case 2: // 第二个目标是南日岛
                    switch (target_val_3)
                    {
                    case 0: // 没有第三个目标，返回起点
                            // Car_Road_Right_xunji(1000);
                        Car_Go_Little(200);
                        road = 10;
                        break;
                    case 1: // 南日岛到湄洲岛
                        Car_Road_Right_xunji(1100);
                        Left_Num = 0;
                        Right_Num = 0;
                        road = 6;
                        break;
                    case 2: // 重复
                        break;
                    case 3: // 从南日岛前往九鲤湖
                        Car_Road_Left_xunji(1100);
                        Left_Num = 0;
                        Right_Num = 0;
                        road = 6;
                        break;
                    default:
                        break;
                    }
                    break;
                case 3: // 第二个目标是九鲤湖
                    switch (target_val_3)
                    {
                    case 0: // 没有第三个目标，返回起点
                        Car_Road_Left_xunji(1100);
                        road = 10;
                        break;
                    case 1: // 从九鲤湖前往湄洲岛
                        Car_Go_Little(200);
                        Left_Num = 0;
                        Right_Num = 0;
                        road = 6;
                        break;
                    case 2: // 从九鲤湖前往南日岛
                        Car_Road_Right_xunji(1100);
                        Left_Num = 0;
                        Right_Num = 0;
                        road = 6;
                        break;
                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }
                break;
            case 6: // 第三次到达目的地
                Car_Stop();
                switch (target_val_3) // 已到达输出给串口屏
                {
                case 1:
                    HMI_print_achieve(1);
                    MEI_Num = MEI_Num + 1;
                    SU03T_arrive(1);
                    break;
                case 2:
                    HMI_print_achieve(2);
                    NAN_Num = NAN_Num + 1;
                    SU03T_arrive(2);
                    break;
                case 3:
                    HMI_print_achieve(3);
                    JIU_Num = JIU_Num + 1;
                    SU03T_arrive(3);
                    break;
                default:
                    break;
                }
                SU03T_back();
                while (!su_03_stop)
                {
                    SU03T_Go(); // 等待语音返回
                }
                su_03_stop = 0;
                HMI_Back();
                Car_Go_Set();
                Car_Road_Left_xunji(2000); // 掉头
                Stop_Num = 1;
                road = 7;
                break;
            case 7:
                Car_Go_Set();
                switch (target_val_3)
                {
                case 1:
                    Car_Road_Right_xunji(1100);
                    road = 10;
                    break;
                case 2:
                    Car_Go_Set();
                    road = 10;
                    break;
                case 3:
                    Car_Road_Left_xunji(1100);
                    road = 10;
                    break;
                default:
                    break;
                }

                break;
            case 10: // 起点掉头
                Car_Go_Set();
                Car_Road_Left_xunji(2000); // 掉头
                road = 1;
                Left_Num = 0;
                Right_Num = 0;
                Stop_Num = 0;
                su_03_stop = 0;
                Car_Back_number = 0;
                target_val_1 = 0;
                target_val_2 = 0;
                target_val_3 = 0;
						bizhang_num = 0;
												bizhang_num_2 = 0;
													bizhang_num_3 = 0;
                Car_Stop();
                HMI_Start();
                Xunji_State = 0;
                break;
            default:
                break;
            }
            break;
        default:
            Car_Go(0);
            Stop_Num = 0;
            break;
        }
        // printf("%d\r\n", Huidu_State);
        // printf("Rnum = %d,Lnum = %d,road = %d,Tar = %d\r\n", Right_Num, Left_Num, road, target_val_1);
    }
}
