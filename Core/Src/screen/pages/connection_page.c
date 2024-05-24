#include "../../../Inc/screen/pages/connection_page.h"
#include "../../../Inc/screen/screen.h"
#include "ssd1306.h"
#include "ssd1306_conf.h"
#include "ssd1306_fonts.h"
void Connection_Page_View(void){
//printf("IP:192.168.1.1\nWifi:inverter\n²");
	ssd1306_Fill(Black);
	ssd1306_SetCursor(0,0);
	ssd1306_WriteString("    Connections   ", Font_7x10, Black);
	ssd1306_SetCursor(0,12);
	ssd1306_WriteString("-IP:192.168.1.1", Font_6x8, White);
	ssd1306_SetCursor(0,22);
	ssd1306_WriteString("-WIFI: Inverter", Font_6x8, White);
	ssd1306_SetCursor(0,32);
	ssd1306_WriteString("-Password: 123456789", Font_6x8, White);
	ssd1306_SetCursor(0,54);
		 ssd1306_WriteString("            %Home  ", Font_7x10, Black);
	ssd1306_UpdateScreen();

}
void Connection_Page_Controller(uint8_t controller){}

