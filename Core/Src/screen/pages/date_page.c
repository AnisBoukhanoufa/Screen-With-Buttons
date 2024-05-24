#include "../../../Inc/screen/pages/date_page.h"
#include <stdio.h>
#include "../../../Inc/screen/screen.h"
#include "ssd1306.h"
#include "ssd1306_conf.h"
#include "ssd1306_fonts.h"
#define MINUTE_STEP 5



static Date_Time  private_date_time={24,01,01,01,01};


uint8_t date_time_index = 0;
static void Increase_Index(void);
static void Decrease_Index(void);
static void Change_Date_Time(int8_t step);  
static void Change_Minute(int8_t step);
static void Change_Day(int8_t step);
static void Change_Hour(int8_t step);
static void Change_Month(int8_t step);
static void Change_Year(int8_t step);
static void Date_Page_Save_Value(void);

void Date_Page_Set_Value(Date_Time date){
private_date_time = date;
}




void Date_Page_Controller(uint8_t controller){
    switch(controller){
    case   SCREEN_UP_CONTROLLER:
        Change_Date_Time(1);
        Page_View();
    break;
    case   SCREEN_DOWN_CONTROLLER:
        Change_Date_Time(-1);
        Page_View();
    break;
    case   SCREEN_LEFT_CONTROLLER:
        Decrease_Index();
        Page_View();
    break;
    case   SCREEN_RIGHT_CONTROLLER:
        Increase_Index();
        Page_View();
    break;
    case   SCREEN_SELECT_CONTROLLER:
        Date_Page_Save_Value();
        current_page=SCREEN_MENU_PAGE;
        Page_View();
    break;
    }
}

void Date_Page_View(void){

	char minute[3]={};
	char hour[3]={};
	char day[3]={};
	char month[3]={};
	char year[5]={};
	sprintf(minute,"%02d",private_date_time.minute);
	sprintf(hour,"%02d",private_date_time.hour);
	sprintf(day,"%02d",private_date_time.day);
	sprintf(month,"%02d",private_date_time.month);
	sprintf(year,"2%03d",private_date_time.year);
	ssd1306_Fill(Black);
	ssd1306_SetCursor(0,0);
	ssd1306_WriteString("   Date and Time   ", Font_7x10, Black);

	/*time label*/
	ssd1306_SetCursor(22,11);
	ssd1306_WriteString("Minute  Hour", Font_6x8, White);
	/*time value*/
	ssd1306_SetCursor(33,21);
	ssd1306_WriteString(minute, Font_6x8,0 != date_time_index );
	ssd1306_SetCursor(78,21);
	ssd1306_WriteString(hour, Font_6x8, date_time_index != 1);
	/*date header*/
	ssd1306_SetCursor(10,31);
	ssd1306_WriteString("Day   Month   Year", Font_6x8, White);
	/*date value*/
	ssd1306_SetCursor(14,39);
	ssd1306_WriteString(day, Font_6x8, date_time_index != 2);
	ssd1306_SetCursor(54,39);
	ssd1306_WriteString(month, Font_6x8, date_time_index != 3);
	ssd1306_SetCursor(94,39);
	ssd1306_WriteString(year, Font_6x8, date_time_index != 4);
    ssd1306_SetCursor(0,54);
	ssd1306_WriteString("osave     <>choose", Font_7x10, Black);
//	draw_Arrow();
    ssd1306_UpdateScreen();
}





static void Increase_Index(void){
date_time_index=(date_time_index+1)%5;
}
static void Decrease_Index(void){
date_time_index=(date_time_index-1)%5;
}   

static void Change_Date_Time(int8_t step){
    switch (date_time_index)
    {
    case 0:
        Change_Minute(step);
        break;
    case 1:
        Change_Hour(step);
        break;
    case 2:
        Change_Day(step);
        break;
    case 3:
        Change_Month(step);
        break;
    case 4:
        Change_Year(step);
        break;
    default:
        break;
    }
}

static void Change_Minute(int8_t step){
        int8_t new_minute= private_date_time.minute;
        if(0==new_minute%MINUTE_STEP){
        new_minute+=(step*MINUTE_STEP);
        }else{
            if(step>0){
               new_minute=new_minute-new_minute%MINUTE_STEP+MINUTE_STEP;
            }else{
                new_minute=new_minute-new_minute%MINUTE_STEP;
            }
        }
        if(0>new_minute ){
             private_date_time.minute=new_minute+60;
        }else if(60<=new_minute){
             private_date_time.minute=new_minute-60;
        }else{
             private_date_time.minute=new_minute;
        }
}

static void Change_Day(int8_t step){
    int8_t new_day= private_date_time.day;
    new_day+=step;
    uint8_t max_days;
    switch ( private_date_time.month)
    {
    case JANUARY:
    case MARCH:
    case MAY:
    case JULY:
    case AUGUST:
    case OCTOBER:
    case DECEMBER:
        max_days=31;
    break;
    case APRIL:
    case JUNE:
    case SEPTEMBER:
    case NOVEMBER:
        max_days=30;
    break;

    case FEBRUARY:
        if( private_date_time.year%4==0){
            max_days=29;
        }else{
            max_days=28;
        }
    break;
    default:
        break;
    }
    
    if(new_day<=0){
         private_date_time.day= new_day+max_days;
    }else if(new_day>max_days){
        private_date_time.day= new_day-max_days;
    }else{
         private_date_time.day= new_day;
    }
}


static void Change_Hour(int8_t step){
    int8_t new_hour= private_date_time.hour;
    new_hour+=step;
    if(new_hour<0){
         private_date_time.hour= new_hour+24;
    }else if(new_hour>23){
         private_date_time.hour= new_hour-24;
    }else{
         private_date_time.hour= new_hour;
        }
}
static void Change_Month(int8_t step){
    int8_t new_month= private_date_time.month;
    new_month+=step;
    if(new_month<1){
         private_date_time.month= new_month+12;
        }else if(new_month>12){
             private_date_time.month= new_month-12;
            }else{
                 private_date_time.month= new_month;
                }
}
static void Change_Year(int8_t step){
    int8_t new_year= private_date_time.year;
    new_year+=step;
    if(new_year<0){
         private_date_time.year= new_year+100;
        }else if(new_year>100){
             private_date_time.year= new_year-100;
            }else{
                 private_date_time.year= new_year;
                }
}

static void Date_Page_Save_Value(void){
//date_time = private_date_time;
change_RTC_Time(private_date_time);
}
