#ifndef DATE_PAGE_H
#define DATE_PAGE_H
#include <stdint.h>
#include "../screen.h"


enum Months{
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
    };


void Date_Page_View(void);
void Date_Page_Controller(uint8_t controller);
void Date_Page_Set_Value(Date_Time date);
#endif // DATE_PAGE_H

