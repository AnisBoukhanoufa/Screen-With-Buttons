///*
// * rtc_config.c
// *
// *  Created on: May 19, 2024
// *      Author: anis
// */
//#include "config/rtc_config.h"
//#include "../../Inc/screen/screen.h"
//
//RTC_HandleTypeDef hrtc;
//
//static void MX_RTC_Init(void);
//
//void RTC_Init()
//{
//	MX_RTC_Init();
//	set_Time();
//}
//
//
//void set_Time()
//{
//	  RTC_TimeTypeDef sTime = {0};
//	  RTC_DateTypeDef sDate = {0};
//	   sTime.Hours = 0x15;
//	   sTime.Minutes = 0x44;
//	   sTime.Seconds = 0x10;
//	   sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
//	   sTime.StoreOperation = RTC_STOREOPERATION_RESET;
//	   if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
//	   {
//	     Error_Handler();
//	   }
//	   sDate.WeekDay = RTC_WEEKDAY_MONDAY;
//	   sDate.Month = RTC_MONTH_JANUARY;
//	   sDate.Date = 0x1;
//	   sDate.Year = 0x24;
//
//	   if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
//	    {
//	      Error_Handler();
//	    }
//	    /* USER CODE BEGIN RTC_Init 2 */
//	  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x123456);
//
//	}
//void get_Time(Date_Time *date_time)
//{
//	  RTC_TimeTypeDef gTime = {0};
//	  RTC_DateTypeDef gDate = {0};
//
//	  HAL_RTC_GetTime(&hrtc, &gTime, RTC_FORMAT_BIN);
//	  HAL_RTC_GetDate(&hrtc, &gDate, RTC_FORMAT_BIN);
//	  date_time->minute=gTime.Minutes;
//	  date_time->hour=gTime.Hours;
//	  date_time->day=gDate.Date;
//	  date_time->month=gDate.Month;
//	  date_time->year=gDate.Year;
//}
//static void MX_RTC_Init(void)
//{
//
//  /* USER CODE BEGIN RTC_Init 0 */
//
//  /* USER CODE END RTC_Init 0 */
//
//
//
//  /* USER CODE BEGIN RTC_Init 1 */
//
//  /* USER CODE END RTC_Init 1 */
//
//  /** Initialize RTC Only
//  */
//  hrtc.Instance = RTC;
//  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
//  hrtc.Init.AsynchPrediv = 127;
//  hrtc.Init.SynchPrediv = 255;
//  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
//  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
//  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
//  if (HAL_RTC_Init(&hrtc) != HAL_OK)
//  {
//    Error_Handler();
//  }
//
//  /* USER CODE BEGIN Check_RTC_BKUP */
//
//  /* USER CODE END Check_RTC_BKUP */
//
//  /** Initialize RTC and set the Time and Date
//  */
//
//  /* USER CODE END RTC_Init 2 */
//
//}
