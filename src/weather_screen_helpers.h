#include "weather_screen_wrapper.h"
#include "binary_icons/day/day_icons.h"
#include "binary_icons/night/night_icons.h"
#include "Fonts/FreeSansOblique12pt7b.h"

#define ICON_X 700
#define ICON_Y_START 95
#define ICON_Y_INCREMENT 85
#define ICON_Y(i) ICON_Y_START + ICON_Y_INCREMENT * (i)

#define AM_X_OFFSET -230
#define AM_Y_OFFSET 30
#define PM_Y_OFFSET 50

class ClockRow {
private:
    int* hours;
    int* minutes;
    String* name;
    String* temperature;

    String iconUrl;
    int iconId = 0;
    bool isDay;
    bool isAm;

    int iconX;
    int iconY;


public:
    ClockRow(int* hours, int* minutes, String* name, String* temperature, int iconX, int iconY) {
        this->hours = hours;
        this->minutes = minutes;
        this->name = name;
        this->iconX = iconX;
        this->iconY = iconY;
        this->temperature = temperature;
    }

    int getHours() {
        return *hours;
    }

    void setHours(int newHours) {
        *hours = newHours;
    } 

    int getMinutes() {
        return *minutes;
    }

    void setMinutes(int newMinutes) {
        *minutes = newMinutes;
    }

    String getName() {
        return *name;
    }

    void setName(const String &newName) {
        *name = newName;
    }

    String getTemperature() {
        return *temperature;
    } 

    void setTemperature(const String &newTemperature) {
        *temperature = newTemperature;
    }

    String getIconUrl() {
        return iconUrl;
    }   

    void setIconUrl(const String &newIconUrl) {
        iconUrl = newIconUrl;
    }

    int getIconId() {
        return iconId;
    }

    void setIconId(int newIconId) {
        iconId = newIconId;
    }

    bool getIsDay() {
        return isDay;
    }

    void setIsDay(bool newIsDay) {
        isDay = newIsDay;
    }

    bool getIsAm() {
        return isAm;
    }

    void setIsAm(bool newIsAm) {
        isAm = newIsAm;
    }

    void drawAmPm()
    {
        int x_position = AM_X_OFFSET + iconX;
        int y_position = (isAm ? AM_Y_OFFSET : PM_Y_OFFSET) + iconY;
        display.setCursor(x_position, y_position);
        display.setFont(&FreeSansOblique12pt7b);
        display.setTextColor(0, 7);
        display.setTextSize(1);
        display.print(isAm ? "AM" : "PM");
    }

    bool drawIcon() {
        unsigned char const * icon;
        if (isDay) {
            icon = day_icons[iconId];
        } else {
            icon = night_icons[iconId];
        }
        if (icon == nullptr) {
            return 0;
        }
        display.drawBitmap(iconX, iconY, icon, 64 , 64, 0, 7);
        return 1;
    }
};

void initClockRows(ClockRow* clockRows[]) {
    using namespace weatherScreen; 
    clockRows[0] = new ClockRow(&digital_clock0_h, &digital_clock0_m, &text1_content, &text7_content, ICON_X, ICON_Y(0));
    clockRows[1] = new ClockRow(&digital_clock2_h, &digital_clock2_m, &text2_content, &text8_content, ICON_X, ICON_Y(1));
    clockRows[2] = new ClockRow(&digital_clock3_h, &digital_clock3_m, &text3_content, &text9_content, ICON_X, ICON_Y(2));
    clockRows[3] = new ClockRow(&digital_clock4_h, &digital_clock4_m, &text4_content, &text10_content, ICON_X, ICON_Y(3));
    clockRows[4] = new ClockRow(&digital_clock5_h, &digital_clock5_m, &text5_content, &text11_content, ICON_X, ICON_Y(4));
    clockRows[5] = new ClockRow(&digital_clock6_h, &digital_clock6_m, &text6_content, &text12_content, ICON_X, ICON_Y(5));
}