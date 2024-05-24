/*
 * screen_model.c
 *
 *  Created on: May 18, 2024
 *      Author: anis
 */

#include "../../Inc/Models/screen_model.h"
#include<string.h>
#include <stdio.h>
#include "ssd1306.h"
#include "ssd1306_conf.h"
#include "ssd1306_fonts.h"
//char Veff[9]={"Veff:"};
void Screen_Init()
{
	ssd1306_Init();
}

void Home_Screen(int Vo,float Io,int P,int Q,int S)
{
char Veff[9]={0};
char Ieff[9]={0};
char pAct[9]={0};
char qReaAct[9]={0};
char sApparent[9]={0};

	 sprintf(Veff, "%s%dV", "Veff:", Vo);
	 sprintf(Ieff, "%s%.2fA", "Ieff:", Io);
	 sprintf(pAct, "%s%dW", "P:", P);
	 sprintf(qReaAct, "%s%dVAR", "Q:", Q);
	 sprintf(sApparent, "%s%dVA", "S:", S);

	 ssd1306_SetCursor(0,0);
	 ssd1306_WriteString("18/05/2024  ", Font_7x10, Black);
	 ssd1306_SetCursor(84,0);
	 ssd1306_WriteString(" 13:44", Font_7x10, Black);
	 ssd1306_SetCursor(0,20);
	 ssd1306_WriteString(Veff, Font_6x8, White);
	 ssd1306_SetCursor(70,15);
	 ssd1306_WriteString(pAct, Font_6x8, White);

	 ssd1306_SetCursor(70,27);
	 ssd1306_WriteString(qReaAct, Font_6x8, White);

	 ssd1306_SetCursor(70,41);
	 ssd1306_WriteString(sApparent, Font_6x8, White);


	 ssd1306_SetCursor(0,36);
	 ssd1306_WriteString(Ieff, Font_6x8, White);
	 ssd1306_SetCursor(0,54);
	 ssd1306_WriteString("            *Menu ", Font_7x10, Black);
	 ssd1306_UpdateScreen();

}
//#include "ssd1306_conf.h"




