/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#define screen_cs_Pin GPIO_PIN_12
#define screen_cs_GPIO_Port GPIOB
#define screen_res_Pin GPIO_PIN_13
#define screen_res_GPIO_Port GPIOB
#define screen_dc_Pin GPIO_PIN_14
#define screen_dc_GPIO_Port GPIOB
#define HOME_Pin GPIO_PIN_0
#define HOME_GPIO_Port GPIOD
#define SELECT_Pin GPIO_PIN_3
#define SELECT_GPIO_Port GPIOD
#define LEFT_Pin GPIO_PIN_4
#define LEFT_GPIO_Port GPIOD
#define RIGHT_Pin GPIO_PIN_5
#define RIGHT_GPIO_Port GPIOD
#define DOWN_Pin GPIO_PIN_6
#define DOWN_GPIO_Port GPIOD
#define UP_Pin GPIO_PIN_7
#define UP_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
