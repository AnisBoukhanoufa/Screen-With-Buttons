#include "../../../Inc/screen/pages/home_page.h"
#include "../../../Inc/screen/screen.h"
#include <stdio.h>
#include "ssd1306.h"
#include "ssd1306_conf.h"
#include "ssd1306_fonts.h"

void Home_Page_Controller(uint8_t controller){
    switch(controller){
    case   SCREEN_UP_CONTROLLER:
    case   SCREEN_DOWN_CONTROLLER:
    case   SCREEN_LEFT_CONTROLLER:
    case   SCREEN_RIGHT_CONTROLLER:
    break;
    case   SCREEN_SELECT_CONTROLLER:
        current_page=SCREEN_MENU_PAGE;
        Page_View();
    break;
    }
}

void Home_Page_View(void){
	 extern Date_Time date_time;
	 extern int Vo;
	 extern float Io;
	 extern int P;
	 extern int Q;
	 extern int S;
	 extern int Freq;

	 char Veff[9]={0};
	 char Ieff[9]={0};
	 char pAct[9]={0};
	 char qReact[9]={0};
	 char sApparent[9]={0};
	 char date[12]={0};
	 char time[7]={0};
	 char frequency[9];
	 ssd1306_Fill(Black);
	 sprintf(Veff, "%s%dV", "Veff:", Vo);
	 sprintf(Ieff, "%s%.2fA", "Ieff:", Io);
	 sprintf(pAct, "%s%dW", "P:", P);
	 sprintf(qReact, "%s%dVAR", "Q:", Q);
	 sprintf(sApparent, "%s%dVA", "S:", S);
	 sprintf(date, "%02d/%02d/2%03d ", date_time.day,date_time.month,date_time.year);
	 sprintf(time, "  %02d:%02d", date_time.hour,date_time.minute);
	 sprintf(frequency, "%s%02dHz", "Freq:", Freq);

	 ssd1306_SetCursor(0,0);
	 ssd1306_WriteString(date, Font_7x10, Black);
	 ssd1306_SetCursor(77,0);
	 ssd1306_WriteString(time, Font_7x10, Black);
	 ssd1306_SetCursor(0,15);
	 ssd1306_WriteString(Veff, Font_6x8, White);
	 ssd1306_SetCursor(70,15);
	 ssd1306_WriteString(pAct, Font_6x8, White);
	 ssd1306_SetCursor(0,27);
	 ssd1306_WriteString(Ieff, Font_6x8, White);
	 ssd1306_SetCursor(70,27);
	 ssd1306_WriteString(qReact, Font_6x8, White);
	 ssd1306_SetCursor(0,41);
	 ssd1306_WriteString(frequency, Font_6x8, White);
	 ssd1306_SetCursor(70,41);
	 ssd1306_WriteString(sApparent, Font_6x8, White);
	 ssd1306_SetCursor(0,54);
	 ssd1306_WriteString("            Menu  ", Font_7x10, Black);
	 ssd1306_DrawCircle(77, 58,3, Black);
	 ssd1306_UpdateScreen();
}
