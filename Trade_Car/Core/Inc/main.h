/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
#define LED_text HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin)
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define HAND_Pin GPIO_PIN_2
#define HAND_GPIO_Port GPIOF
#define KEY1_Pin GPIO_PIN_3
#define KEY1_GPIO_Port GPIOF
#define KEY2_Pin GPIO_PIN_4
#define KEY2_GPIO_Port GPIOF
#define KEY3_Pin GPIO_PIN_5
#define KEY3_GPIO_Port GPIOF
#define KEY4_Pin GPIO_PIN_6
#define KEY4_GPIO_Port GPIOF
#define OLED_SDA_Pin GPIO_PIN_8
#define OLED_SDA_GPIO_Port GPIOF
#define OLED_SCL_Pin GPIO_PIN_9
#define OLED_SCL_GPIO_Port GPIOF
#define INT_6050_Pin GPIO_PIN_3
#define INT_6050_GPIO_Port GPIOC
#define SCL_6050_Pin GPIO_PIN_13
#define SCL_6050_GPIO_Port GPIOF
#define SDA_6050_Pin GPIO_PIN_14
#define SDA_6050_GPIO_Port GPIOF
#define MB4_Pin GPIO_PIN_10
#define MB4_GPIO_Port GPIOE
#define MA4_Pin GPIO_PIN_12
#define MA4_GPIO_Port GPIOE
#define MB3_Pin GPIO_PIN_15
#define MB3_GPIO_Port GPIOE
#define R2_Pin GPIO_PIN_12
#define R2_GPIO_Port GPIOB
#define R1_Pin GPIO_PIN_13
#define R1_GPIO_Port GPIOB
#define SR04IN_Pin GPIO_PIN_14
#define SR04IN_GPIO_Port GPIOB
#define SR04OUT_Pin GPIO_PIN_15
#define SR04OUT_GPIO_Port GPIOB
#define L1_Pin GPIO_PIN_8
#define L1_GPIO_Port GPIOD
#define L2_Pin GPIO_PIN_9
#define L2_GPIO_Port GPIOD
#define L3_Pin GPIO_PIN_10
#define L3_GPIO_Port GPIOD
#define L4_Pin GPIO_PIN_11
#define L4_GPIO_Port GPIOD
#define R3_Pin GPIO_PIN_14
#define R3_GPIO_Port GPIOD
#define R4_Pin GPIO_PIN_15
#define R4_GPIO_Port GPIOD
#define MA3_Pin GPIO_PIN_4
#define MA3_GPIO_Port GPIOG
#define BEEP_Pin GPIO_PIN_10
#define BEEP_GPIO_Port GPIOG

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
