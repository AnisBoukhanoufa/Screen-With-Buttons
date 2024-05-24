#ifndef SCREEN_H
#define SCREEN_H

enum Screen_View {
    SCREEN_HOME_PAGE,
    SCREEN_MENU_PAGE,
    SCREEN_DATE_PAGE,
    SCREEN_CONNECTION_PAGE,
    SCREEN_INFO_PAGE,
    SCREEN_UNKNOWN_PAGE,
};

enum Screen_Controller {
    SCREEN_UP_CONTROLLER,
    SCREEN_DOWN_CONTROLLER,
    SCREEN_LEFT_CONTROLLER,
    SCREEN_RIGHT_CONTROLLER,
    SCREEN_HOME_CONTROLLER,
    SCREEN_SELECT_CONTROLLER,
};

typedef struct{
    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
}
Date_Time;

extern Date_Time date_time;

extern enum Screen_View current_page;  

void Page_Controller(uint8_t controller);
void Page_View(void);

#endif // SCREEN_H
