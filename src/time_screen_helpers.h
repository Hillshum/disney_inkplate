#include "generatedUI.h"

class ClockRow {
private:
    int* hours;
    int* minutes;

    String* name;

public:
    ClockRow(int* hours, int* minutes, String* name) {
        this->hours = hours;
        this->minutes = minutes;
        this->name = name;
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
};

void initClockRows(ClockRow* clockRows[]) {
    clockRows[0] = new ClockRow(&digital_clock0_h, &digital_clock0_m, &text1_content);
    clockRows[1] = new ClockRow(&digital_clock2_h, &digital_clock2_m, &text2_content);
    clockRows[2] = new ClockRow(&digital_clock3_h, &digital_clock3_m, &text3_content);
    clockRows[3] = new ClockRow(&digital_clock4_h, &digital_clock4_m, &text4_content);
    clockRows[4] = new ClockRow(&digital_clock5_h, &digital_clock5_m, &text5_content);
    clockRows[5] = new ClockRow(&digital_clock6_h, &digital_clock6_m, &text6_content);
}