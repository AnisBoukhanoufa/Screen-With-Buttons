#include "../../../Inc/screen/pages/menu_page.h"
#include "../../../Inc/screen/screen.h"
#include "ssd1306.h"
#include "ssd1306_conf.h"
#include "ssd1306_fonts.h"

#define PAGES_NUMBER 3u

static uint8_t children_pages[PAGES_NUMBER] ={SCREEN_DATE_PAGE,SCREEN_CONNECTION_PAGE,SCREEN_INFO_PAGE} ;
static uint8_t page_index=0;


static void Increase_Index(void);
static void Decrease_Index(void);   
static void Select_Page(void);   

void Menu_Page_Controller(uint8_t controller){
    switch(controller){
    case   SCREEN_UP_CONTROLLER:
        Decrease_Index();
        Page_View();
    break;
    case   SCREEN_DOWN_CONTROLLER:
        Increase_Index();
        Page_View();
    break;
    case   SCREEN_LEFT_CONTROLLER:
    case   SCREEN_RIGHT_CONTROLLER:
    break;
    case   SCREEN_SELECT_CONTROLLER:
        Select_Page();
        Page_View();
    break;
    }
}

void Menu_Page_View(void){


	ssd1306_Fill(Black);
	ssd1306_SetCursor(0,0);

	ssd1306_WriteString("       Menu       ", Font_7x10, Black);

	if(page_index==0){

    	ssd1306_SetCursor(0,10);
    	ssd1306_WriteString(" -Date and Time      ", Font_6x8, Black);
    	ssd1306_SetCursor(0,18);
    	ssd1306_WriteString(" -Connections        ", Font_6x8, White );
    	ssd1306_SetCursor(0,26);
    	ssd1306_WriteString(" -Info               ", Font_6x8, White);
    }
    if(page_index==1){

    	ssd1306_SetCursor(0,10);
        	ssd1306_WriteString(" -Date and Time      ", Font_6x8, White);
        	ssd1306_SetCursor(0,18);
        	ssd1306_WriteString(" -Connections        ", Font_6x8, Black );
        	ssd1306_SetCursor(0,26);
        	ssd1306_WriteString(" -Info               ", Font_6x8, White);
        }
    if(page_index==2){

    	ssd1306_SetCursor(0,10);
      	ssd1306_WriteString(" -Date and Time      ", Font_6x8, White);
      	ssd1306_SetCursor(0,18);
      	ssd1306_WriteString(" -Connections        ", Font_6x8, White );
      	ssd1306_SetCursor(0,26);
      	ssd1306_WriteString(" -Info               ", Font_6x8, Black);
      }

	ssd1306_Line(4, 55, 4, 63, Black);

	ssd1306_SetCursor(0,54);
	ssd1306_WriteString("  Choose   Select", Font_7x10, Black);
	draw_Arrow();
	ssd1306_DrawCircle(72, 58,3, Black);
	ssd1306_UpdateScreen();
}

static void Increase_Index(void){
    page_index=(page_index+1)%PAGES_NUMBER;
}

static void Decrease_Index(void){
    page_index=(page_index-1)%PAGES_NUMBER;
}   

static void Select_Page(void){
    current_page= children_pages[page_index];
}

