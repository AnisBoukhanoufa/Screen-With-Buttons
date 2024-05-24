/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "../Inc/Models/screen_model.h"
#include "../Inc/screen/screen.h"
//#include "../Inc/config/rtc_config.h"
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
RTC_HandleTypeDef hrtc;

SPI_HandleTypeDef hspi2;
DMA_HandleTypeDef hdma_spi2_tx;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_SPI2_Init(void);
static void MX_RTC_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
volatile unsigned int *DWT_CYCCNT   = (volatile unsigned int *)0xE0001004; //address of the register
volatile unsigned int *DWT_CONTROL  = (volatile unsigned int *)0xE0001000; //address of the register
volatile unsigned int *DWT_LAR      = (volatile unsigned int *)0xE0001FB0; //address of the register
volatile unsigned int *SCB_DEMCR    = (volatile unsigned int *)0xE000EDFC; //address of the register

	 int Vo=177;
	 float Io=0.98;
	 int P=300;
	 int Q=247;
	 int S=300;
	 int Freq=50;

//	 Date_Time fromRtc;
//	 extern Date_Time date_time;



	 void change_RTC_Time(Date_Time newDateTime){

		 RTC_TimeTypeDef sTime = {0};
		 RTC_DateTypeDef sDate = {0};
		  sTime.Hours = newDateTime.hour;
		  sTime.Minutes=newDateTime.minute;
		  sDate.Month = newDateTime.month;
		  sDate.Date = newDateTime.day;
		  sDate.Year = newDateTime.year;

		   HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) ;
		   HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) ;

	 }

	 void set_Time(){
	  RTC_TimeTypeDef sTime = {0};
	  RTC_DateTypeDef sDate = {0};

	   sTime.Hours = 0x12;
	   sTime.Minutes = 0x24;
	   sTime.Seconds = 0x0;
	   sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	   sTime.StoreOperation = RTC_STOREOPERATION_RESET;
	   if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
	   {
	     Error_Handler();
	   }
	   sDate.WeekDay = RTC_WEEKDAY_MONDAY;
	   sDate.Month = RTC_MONTH_JANUARY;
	   sDate.Date = 0x20;
	   sDate.Year = 0x24;

	   if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
	   {
	     Error_Handler();
	   }

	  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1,0x32F2);
}


void get_Time(void) {


	 RTC_TimeTypeDef sTime;
	 RTC_DateTypeDef sDate;
    // Get current time
    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);

    // Get current date
    HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

    if(date_time.minute!=sTime.Minutes){
    date_time.day=sDate.Date;
    date_time.month=sDate.Month;
    date_time.year=sDate.Year;
    date_time.minute=sTime.Minutes;
    date_time.hour=sTime.Hours;
//    Date_Page_Set_Value(date_time);
    Page_View();
    }

    // Display or use the time and date
}
//int  j=0;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

//HAL_SPI_Transmit_DMA(hspi, pData, Size)
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
  MX_SPI2_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */
  *SCB_DEMCR |= 0x01000000;
  *DWT_LAR = 0xC5ACCE55; // enable access
  *DWT_CYCCNT = 0; // reset the counter
  *DWT_CONTROL |= 1 ; // enable the counter
  void RTC_Init();
  Init_Screen();
if(HAL_RTCEx_BKUPRead(&hrtc,RTC_BKP_DR1)!=0x32F2)
{
	set_Time();
}


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
	  if(HAL_GPIO_ReadPin(UP_GPIO_Port, UP_Pin))
	  	  {
	  		  Page_Controller(SCREEN_UP_CONTROLLER);
	  		  while(HAL_GPIO_ReadPin(UP_GPIO_Port, UP_Pin));
	  	  }
	  	  if(HAL_GPIO_ReadPin(DOWN_GPIO_Port, DOWN_Pin))
	  	  	  {
	  	  	  Page_Controller(SCREEN_DOWN_CONTROLLER);
	  	  	  while(HAL_GPIO_ReadPin(DOWN_GPIO_Port, DOWN_Pin));
	  	  	  }

	  	  if(HAL_GPIO_ReadPin(SELECT_GPIO_Port, SELECT_Pin))
	  	  	  {
	  		  Page_Controller(SCREEN_SELECT_CONTROLLER);
	  		  while(HAL_GPIO_ReadPin(SELECT_GPIO_Port, SELECT_Pin));
	  	  	  }
	  	if(HAL_GPIO_ReadPin(HOME_GPIO_Port, HOME_Pin))
	  		  	  	  {
	  		current_page = SCREEN_HOME_PAGE;
	  		Page_View();
	  		  		  while(HAL_GPIO_ReadPin(HOME_GPIO_Port, HOME_Pin));
	  		  	  	  }
	  	  	  if(HAL_GPIO_ReadPin(LEFT_GPIO_Port, LEFT_Pin))
	  	  	  	  {
	  	  		  Page_Controller(SCREEN_LEFT_CONTROLLER);
	  	  		 while(HAL_GPIO_ReadPin(LEFT_GPIO_Port, LEFT_Pin));
	  	  	  	  }
	  	  	  if(HAL_GPIO_ReadPin(RIGHT_GPIO_Port, RIGHT_Pin))
	  	  	  	  {
	  	  		  Page_Controller(SCREEN_RIGHT_CONTROLLER);
	  	  		 while(HAL_GPIO_ReadPin(RIGHT_GPIO_Port, RIGHT_Pin));
	  	  	  	  }
//	  	  	HAL_Delay(100);
	  	  	  get_Time();




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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */


  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */

  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */

  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date
   /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, screen_cs_Pin|screen_res_Pin|screen_dc_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : screen_cs_Pin screen_res_Pin screen_dc_Pin */
  GPIO_InitStruct.Pin = screen_cs_Pin|screen_res_Pin|screen_dc_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : HOME_Pin SELECT_Pin LEFT_Pin RIGHT_Pin
                           DOWN_Pin UP_Pin */
  GPIO_InitStruct.Pin = HOME_Pin|SELECT_Pin|LEFT_Pin|RIGHT_Pin
                          |DOWN_Pin|UP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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

#ifdef  USE_FULL_ASSERT
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
