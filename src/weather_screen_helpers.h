#include "weather_screen_wrapper.h"
#include "icons.h"

class ClockRow {
private:
    int* hours;
    int* minutes;
    String* name;
    String* temperature;

    String iconUrl;
    int iconId;

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

    bool drawIcon() {

        display.drawBitmap(iconX, iconY, icons[iconId], 64 , 64, 0, 7);
        return 1;
    }
};

void initClockRows(ClockRow* clockRows[]) {
    using namespace weatherScreen; 
    clockRows[0] = new ClockRow(&digital_clock0_h, &digital_clock0_m, &text1_content, &text7_content, 650, 60);
    clockRows[1] = new ClockRow(&digital_clock2_h, &digital_clock2_m, &text2_content, &text8_content, 650, 150);
    clockRows[2] = new ClockRow(&digital_clock3_h, &digital_clock3_m, &text3_content, &text9_content, 650, 240);
    clockRows[3] = new ClockRow(&digital_clock4_h, &digital_clock4_m, &text4_content, &text10_content, 650, 330);
    clockRows[4] = new ClockRow(&digital_clock5_h, &digital_clock5_m, &text5_content, &text11_content, 650, 420);
    clockRows[5] = new ClockRow(&digital_clock6_h, &digital_clock6_m, &text6_content, &text12_content, 650, 510);
}