/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "blue.h"
#include "stdio.h"
#include <string.h>
#include "xunji.h"
#include "menu.h"
#include "oled.h"
#include "beep.h"
#include "key.h"
#include "my_uart.h"
#include "HMI.h"
#include "SU03T.h"
#include "SR04.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
extern short Encoder1Count; // 左电机编码器�???
extern short Encoder2Count; // 右电机编码器�???
extern int Start_Speed;     // 起始速度
extern uint8_t Usart1_ReadBuf[255];
extern uint8_t Usart1_ReadCount;
extern int speed; // 摇杆发�?��?�度�???
extern int SET1;  // 个位
extern int SET2;  // 十位
extern int SET3;  // 百位
extern int SET4;  // 千位
extern int target_val_2_read;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int Xunji_State = 0;     // 寻迹�??关，1为开始寻迹，0为关闭寻�??
int Stop_Num = 0;        // �??测是否到白线上，在白线上�??1
int Car_Back_number = 0; // 返回使能
int target_val_1 = 0;    // 1为最左，2为中间，3为最右
int target_val_2 = 0;    // 1为最左，2为中间，3为最右
int target_val_3 = 0;    // 1为最左，2为中间，3为最右
int Huidu_State = 0;     // 灰度传感器读取的值
int road = 1;            // 判断路过几个路口
int Left_Num = 0;        // 路口左转的次数
int Right_Num = 0;       // 路口右转的次数
int su_03_stop = 0;      // 语音控制是否回程
int SR04_Start = 0;
int SR04_End = 0;
double disa = 0.00;
int SR04_Open = 0;
int coins = 0;
int coin_need = 0;
int pay_open = 0;
int MEI_Num = 0;
int NAN_Num = 0;
int JIU_Num = 0;
int bizhang_num = 0;
int bizhang_num_2 = 0;
int bizhang_num_3 = 0;
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_TIM8_Init();
  MX_TIM14_Init();
  MX_TIM2_Init();
  MX_TIM4_Init();
  MX_TIM13_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start(&htim8, TIM_CHANNEL_ALL);   // 2路编码器使能
  OLED_Init();                                      // oled初始化
  PID_init();                                       // PID参数初始化
  HAL_UART_Receive_IT(&huart1, &USART1_RX_Data, 1); // 打开蓝牙接收中断
  HAL_UART_Receive_IT(&huart2, &USART2_RX_Data, 1); // 串口接受
  HAL_UART_Receive_IT(&huart3, &USART3_RX_Data, 1); // SU-03T
  HMI_Start();                                      // 串口屏回到开始界面
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);         // 定时器1 通道1 PWM输出
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);         // 定时器1 通道2 PWM输出
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);         // 定时器1 通道3 PWM输出
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);         // 定时器1 通道4 PWM输出

  HAL_TIM_Base_Start_IT(&htim13); // 定时器13的定时功能开定时1us
  HAL_TIM_Base_Start_IT(&htim14); // 定时器14的定时功能开定时1ms

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    SU03T_get();
    HMI_get(); // 获取去往地点
    Read_Hand();
    Xunji(Huidu_State); // 进行寻迹
    // printf("coins = %d\r\n", coin_need);
    //	printf("mainprintf Rightnum = %d\r\n",Right_Num);
    //  printf("%c%c%c%c%c%c", 0xAA, 0x55, 0x01, 0X2C, 0x55, 0xAA);
    //  HAL_Delay(500);
    if (SR04_Open == 1) // 距离获得
    {
      disa = SR04_Getdistance();
      SR04_Open = 0;
    }
    if (disa < 4) // 避障
    {
      if (Xunji_State == 1)
      {
				if(road == 2)
				{
				if(target_val_1 == 1)
				{
					Car_Road_Right(1100);
					Car_Go_Little(1500);
					Car_Road_Left(1200);
					Car_Go_Little(3450);
					Car_Road_Left(1100);
					Car_Go_Little(1300);
					Car_Road_Right(1050);
					Car_Go_Little(1500);
					Car_Road_Right(1050);//写死
					Right_Num++;
				}
					if(target_val_1 == 3)
						
					{
						if(bizhang_num == 0)
						{
							Car_Road_Right(1100);
							Car_Go_Little(1500);
							Car_Road_Left(1200);
							Car_Go_Little(3450);
							Car_Road_Left(1100);
							Car_Go_Little(1300);//1800
							Car_Road_Right(1050);
							Car_Stop();
							road = 3;
							HMI_print_achieve(3);
							JIU_Num = JIU_Num + 1;
							SU03T_arrive(3);
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
									Car_Go_Little(1000);
									Car_Road_Left(2000);
									bizhang_num = 1;
							}
					}
				}
				if(road == 3)
				{
					if(target_val_1 == 3)
					{
						Car_Road_Right(1100);
						Car_Go_Little(1500);
						Car_Road_Left(1100);
						Car_Go_Little(3400);
						Car_Road_Left(1100);
						Car_Go_Little(1500);//1800
						Car_Road_Right(1050);
						HAL_Delay(20);
						Car_Go_Little(1100);
						Car_Road_Right(1050);
						Right_Num++;
					}
					else
					{
						Car_Road_Right(1100);
						Car_Go_Little(1500);
						Car_Road_Left(1200);
						Car_Go_Little(3200);
						Car_Road_Left(1100);
						Car_Go_Little(1200);//1800
						Car_Road_Right(1050);
					}
				}
						if(road == 4)
				{
						if(target_val_2 == 1)
					{
						Car_Road_Right(1100);
						Car_Go_Little(1500);
						Car_Road_Left(1200);
						Car_Go_Little(3450);
						Car_Road_Left(1100);
						Car_Go_Little(1300);
						Car_Road_Right(1050);
						Car_Go_Little(1500);
						Car_Road_Right(1050);//写死
						Right_Num++;
					}
					if(target_val_2 == 3)
					{
						if(bizhang_num_2 == 0)
						{
						Car_Road_Right(1100);
						Car_Go_Little(1500);
						Car_Road_Left(1200);
						Car_Go_Little(3450);
						Car_Road_Left(1100);
						Car_Go_Little(1300);
						Car_Road_Right(1050);//第一次避障
						Car_Stop();
						road = 5;
						HMI_print_achieve(3);
            JIU_Num = JIU_Num + 1;
            SU03T_arrive(3);
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
								 switch (target_val_3) // 前往第二个地点输出给串口屏
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
                 Car_Go_Little(1000);
                Car_Road_Left(2000);
								bizhang_num_2 = 1;
						}
					}
				}
				if(road == 5)
				{
					
					if(target_val_2 == 3)
					{
						Car_Road_Right(1100);
						Car_Go_Little(1500);
						Car_Road_Left(1100);
						Car_Go_Little(3400);
						Car_Road_Left(1100);
						Car_Go_Little(1500);
						Car_Road_Right(1050);
						HAL_Delay(20);
						Car_Go_Little(1100);
						Car_Road_Right(1050);//写死
						Right_Num++;
					}
					else
					{
						Car_Road_Right(1100);
						Car_Go_Little(1500);
						Car_Road_Left(1200);
						Car_Go_Little(3200);
						Car_Road_Left(1100);
						Car_Go_Little(1200);
						Car_Road_Right(1050);
					}
				}
						if(road == 6)
				{
					if(target_val_3 == 1)
					{
						Car_Road_Right(1100);
						Car_Go_Little(1500);
						Car_Road_Left(1200);
						Car_Go_Little(3450);
						Car_Road_Left(1100);
						Car_Go_Little(1300);
						Car_Road_Right(1050);
						Car_Go_Little(1500);
						Car_Road_Right(1050);//写死
						Right_Num++;
					}	
					if(target_val_3 == 3)
					{
						if(bizhang_num_3 == 0)
						{
							Car_Road_Right(1100);
							Car_Go_Little(1500);
							Car_Road_Left(1200);
							Car_Go_Little(3200);
							Car_Road_Left(1100);
							Car_Go_Little(1300);
							Car_Road_Right(1050);
							Car_Stop();
							road = 7;
							HMI_print_achieve(3);
							JIU_Num = JIU_Num + 1;
							SU03T_arrive(3);
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
									 switch (target_val_3) // 前往第二个地点输出给串口屏
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
									Car_Go_Little(1000);
									Car_Road_Left(2000);
									bizhang_num_3 = 1;
							}
					
					}
				
				}
				if(road == 7)
				{
					
					if(target_val_3 == 3)
					{
						Car_Road_Right(1100);
						Car_Go_Little(1500);
						Car_Road_Left(1100);
						Car_Go_Little(3400);
						Car_Road_Left(1100);
						Car_Go_Little(1500);//1800
						Car_Road_Right(1050);
						HAL_Delay(20);
						 Car_Go_Little(1100);
						Car_Road_Right(1050);
						Right_Num++;
					}
					else
					{
						Car_Road_Right(1100);
						Car_Go_Little(1500);
						Car_Road_Left(1200);
						Car_Go_Little(3200);
						Car_Road_Left(1100);
						Car_Go_Little(1250);//1800
						Car_Road_Right(1050);
					}
				}
      }
    
	}
//	 if (Read_Key() == 1)
//	 {
//		 SU03T_arrive(3);
//	 }
    if (Read_Key() == 4)
    {

      if (coin_need <= coins)
      {
        pay_open = 0;
        switch (road)
        {
        case 1:
          switch (target_val_1)
          {
          case 1:
            HMI_print(1);
            SU03T_GO_meizhou();
            Xunji_State = 1;
            break;
          case 2:
            HMI_print(2);
            SU03T_GO_nanri();
            Xunji_State = 1;
            break;
          case 3:
            HMI_print(3);
            SU03T_GO_jiuli();
            Xunji_State = 1;
            break;
          default:
            break;
          }
          break;
        case 2:
          switch (target_val_1)
          {
          case 1:
            HMI_print(1);
            Xunji_State = 1;
            break;
          case 2:
            HMI_print(2);
            Xunji_State = 1;
            break;
          case 3:
            HMI_print(3);
            Xunji_State = 1;
            break;
          default:
            break;
          }
          break;
        case 3:
          switch (target_val_2)
          {
          case 1:
            HMI_print(1);
            SU03T_GO_meizhou();
            Xunji_State = 1;
            break;
          case 2:
            HMI_print(2);
            SU03T_GO_nanri();
            Xunji_State = 1;
            break;
          case 3:
            HMI_print(3);
            SU03T_GO_jiuli();
            Xunji_State = 1;
            break;
          default:
            break;
          }
          break;
        case 4:
          switch (target_val_2)
          {
          case 1:
            HMI_print(1);
            Xunji_State = 1;
            break;
          case 2:
            HMI_print(2);
            Xunji_State = 1;
            break;
          case 3:
            HMI_print(3);
            Xunji_State = 1;
            break;
          default:
            break;
          }
          break;
        case 5:

        case 6:
          switch (target_val_3)
          {
          case 1:
            HMI_print(1);
            SU03T_GO_meizhou();
            Xunji_State = 1;
            break;
          case 2:
            HMI_print(2);
            SU03T_GO_nanri();
            Xunji_State = 1;
            break;
          case 3:
            HMI_print(3);
            SU03T_GO_jiuli();
            Xunji_State = 1;
            break;
          default:
            break;
          }
        default:
          // Xunji_State = 1;
          break;
        }
      }
      else
        LED_text; // 语音播报钱不够
    }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
   */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
