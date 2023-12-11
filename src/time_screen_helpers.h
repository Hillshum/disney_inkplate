#include "generatedUI.h"
#include "icons.h"

class ClockRow {
private:
    int* hours;
    int* minutes;

    String iconUrl;
    int iconId;

    int iconX;
    int iconY;

    String* name;

public:
    ClockRow(int* hours, int* minutes, String* name, int iconX, int iconY) {
        this->hours = hours;
        this->minutes = minutes;
        this->name = name;
        this->iconX = iconX;
        this->iconY = iconY;
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

    // bool drawIcon() {
    //     return display.drawImage(iconUrl, display.PNG, iconX, iconY);
    // }

    bool drawIcon() {

        display.drawBitmap(iconX, iconY, icons[iconId], 64 , 64, 0, 7);
        return 1;
    }
};

void initClockRows(ClockRow* clockRows[]) {
    clockRows[0] = new ClockRow(&digital_clock0_h, &digital_clock0_m, &text1_content, 650, 60);
    clockRows[1] = new ClockRow(&digital_clock2_h, &digital_clock2_m, &text2_content, 650, 150);
    clockRows[2] = new ClockRow(&digital_clock3_h, &digital_clock3_m, &text3_content, 650, 240);
    clockRows[3] = new ClockRow(&digital_clock4_h, &digital_clock4_m, &text4_content, 650, 330);
    clockRows[4] = new ClockRow(&digital_clock5_h, &digital_clock5_m, &text5_content, 650, 420);
    clockRows[5] = new ClockRow(&digital_clock6_h, &digital_clock6_m, &text6_content, 650, 510);
}