#include "../../Inc/screen/pages/home_page.h"
#include "../../Inc/screen/pages/menu_page.h"
//#include "pages/menu_page.h"
//#include "pages/date_page.h"
//#include "pages/connection_page.h"
//#include "pages/info_page.h"
#include "../../Inc/screen/screen.h"
#include "ssd1306.h"
#include "ssd1306_conf.h"

#include <stdio.h>
// gcc screen.c .\pages\date_page.c .\pages\home_page.c .\pages\info_page.c .\pages\menu_page.c .\pages\connection_page.c -o my_program

enum Screen_View current_page = SCREEN_HOME_PAGE;
Date_Time date_time;

//void key_event_listener(void)
//{
//    int ch;
//
//    while (1)
//    {
//        if (_kbhit())
//        {
//            ch = _getch();
//            switch (ch)
//            {
//            case 'h':
//                current_page = SCREEN_HOME_PAGE;
//                Page_View();
//                break;
//            case 'k':
//                Page_Controller(SCREEN_SELECT_CONTROLLER);
//                break;
//            case 'z':
//                Page_Controller(SCREEN_UP_CONTROLLER);
//                break;
//            case 's':
//                Page_Controller(SCREEN_DOWN_CONTROLLER);
//                break;
//            case 'q':
//                Page_Controller(SCREEN_LEFT_CONTROLLER);
//                break;
//            case 'd':
//                Page_Controller(SCREEN_RIGHT_CONTROLLER);
//                break;
//            case 'v':
//                exit(0);
//
//            }
//        }
//    }
//}

void Page_View(void)
{
//    system("cls");
    switch (current_page)
    {
    case SCREEN_HOME_PAGE:
        Home_Page_View();
        break;
    case SCREEN_MENU_PAGE:
        Menu_Page_View();
        break;
    case SCREEN_DATE_PAGE:
        Date_Page_View();
        break;
    case SCREEN_CONNECTION_PAGE:
        Connection_Page_View();
        break;
    case SCREEN_INFO_PAGE:
        Info_Page_View();
        break;
    default:
        printf("non page has selected");
    }
}

void Page_Controller(uint8_t controller)
{

    switch (current_page)
    {
    case SCREEN_HOME_PAGE:
        Home_Page_Controller(controller);
        break;
    case SCREEN_MENU_PAGE:
        Menu_Page_Controller(controller);
        break;
    case SCREEN_DATE_PAGE:
        Date_Page_Controller(controller);
        break;
    case SCREEN_CONNECTION_PAGE:
        Connection_Page_Controller(controller);
        break;
    case SCREEN_INFO_PAGE:
        Info_Page_Controller(controller);
        break;
    default:
    }
}

void Init_Screen(void)
{
	ssd1306_Init();
//    date_time.day = 12;
//    date_time.month = 9;
//    date_time.year = 24;
//    date_time.hour = 13;
//    date_time.minute = 23;
	get_Time(&date_time);
	Date_Page_Set_Value(date_time);

    Page_View();
}


