#include "../../../Inc/screen/pages/info_page.h"
#include <stdio.h>
#include "../../../Inc/screen/screen.h"
#include "ssd1306.h"
#include "ssd1306_conf.h"
#include "ssd1306_fonts.h"

#define PAGES_NUMBER 3u

#define PAGE_INFO_0  "info page 1\n"
#define PAGE_INFO_1  "info page 2\n"
#define PAGE_INFO_2  "info page 3\n"


static uint8_t page_index=0;

static void Increase_Index(void);
static void Decrease_Index(void);   

void Info_Page_Controller(uint8_t controller){
    switch(controller){
    case   SCREEN_UP_CONTROLLER:
    case   SCREEN_DOWN_CONTROLLER:
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
    break;
    }
}


void Info_Page_View(void){
		ssd1306_Fill(Black);
		ssd1306_SetCursor(0,0);
		ssd1306_WriteString("       Info       ", Font_7x10, Black);
    switch (page_index)
    {
    case 0:
    		ssd1306_SetCursor(0,12);
    		ssd1306_WriteString("-Chouder", Font_6x8, White);
    		ssd1306_SetCursor(0,22);
    		ssd1306_WriteString("-Boukhennoufa", Font_6x8, White);
    		ssd1306_SetCursor(0,32);
    		ssd1306_WriteString("-Iddou", Font_6x8, White);
    		ssd1306_SetCursor(0,54);
    		ssd1306_WriteString("      1/3   Next >", Font_7x10, Black);
        break;
    case 1:

    			ssd1306_SetCursor(0,12);
        		ssd1306_WriteString("-Chouder2", Font_6x8, White);
        		ssd1306_SetCursor(0,22);
        		ssd1306_WriteString("-Boukhennoufa2", Font_6x8, White);
        		ssd1306_SetCursor(0,32);
        		ssd1306_WriteString("-Iddou2", Font_6x8, White);
        		ssd1306_SetCursor(0,54);
        		ssd1306_WriteString("< Prev 2/3  Next >", Font_7x10, Black);
        break;
    case 2:

    			ssd1306_SetCursor(0,12);
        		ssd1306_WriteString("-Chouder3", Font_6x8, White);
        		ssd1306_SetCursor(0,22);
        		ssd1306_WriteString("-Boukhennoufa3", Font_6x8, White);
        		ssd1306_SetCursor(0,32);
        		ssd1306_WriteString("-Iddou3", Font_6x8, White);
        		ssd1306_SetCursor(0,54);
        		ssd1306_WriteString("< Prev 3/3        ", Font_7x10, Black);
        break;
    
    default:
        break;
    }
    ssd1306_UpdateScreen();
}


static void Increase_Index(void){
    page_index=(page_index+1)%PAGES_NUMBER;
}

static void Decrease_Index(void){
    page_index=(page_index-1)%PAGES_NUMBER;
}   
