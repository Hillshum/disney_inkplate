#ifndef WAITS_SCREEN_HELPERS_H
#define WAITS_SCREEN_HELPERS_H

#include "waits_screen_wrapper.h"

#define NUM_RIDES 6
#define MAX_CHARS_PER_LINE 38

class RideRow {
private: 
    String* waitTime;
    String* name;
    String fullName;

    const GFXfont** nameFont;

    bool bIsOpen;
    int currentWait;

    void updateWaitString() {

        if (currentWait == -1)
        {
            *waitTime = String("");
            return;
        }

        String newWaitString = String(currentWait);
        newWaitString.concat(" min");
        Serial.printf("new wait string: %s\n", newWaitString.c_str());
        *waitTime = newWaitString;
    }

    void trimNameString(char* nameChars) {
        Serial.printf("trimming name string: %s\n", nameChars);
        int len = strlen(nameChars);
        if (len < 5) // String already as short as it gets
        {
            Serial.println("name string already as short as it gets");
            return;
        }
        int16_t x1, y1;
        uint16_t w, h;
        display.setFont(*nameFont);
        display.getTextBounds(nameChars, 24, 0, &x1, &y1, &w, &h);
        Serial.printf("w: %d\n", w);
        if (w < 610) // TODO get correct number
        {
            Serial.println("name string fits");
            return;
        }

        // add elipsis and try again
        int hasElipsis = strcasecmp(nameChars + len - 3, "...") == 0;
        if (hasElipsis)
        {
            nameChars[len-3] = '\0';
            len = len - 3;
            Serial.printf("removed elipsis, new name string: %s\n", nameChars);
        }
        nameChars[len-1] = '.';
        nameChars[len-2] = '.';
        nameChars[len-3] = '.';
        return trimNameString(nameChars);
        

    }


public: 

    RideRow(String* name, String* waitTime,  const GFXfont** nameFont) {
        this->waitTime = waitTime;
        this->name = name;
        this->nameFont = nameFont;
    }

    void setName(const String &newName) {

        fullName = newName;
        char nameToTrim[100];
        newName.toCharArray(nameToTrim, 100); 

        trimNameString(nameToTrim);
        *name = String(nameToTrim);
        // *name = newName;

        // if (newName.length() > MAX_CHARS_PER_LINE)
        // {
        //     *name = newName.substring(0, MAX_CHARS_PER_LINE-3);
        //     name->concat("...");
        // }
    }

    void setCurrentWait(int newWait) {

        currentWait = newWait;

        updateWaitString();

    }

    void setOpen(bool isOpen) {
        bIsOpen = isOpen;
        if (isOpen)
        {
            updateWaitString();
            return;
        }
        *waitTime = String("Closed");
    }

    bool isOpen() {
        return bIsOpen;
    }

};

RideRow* rideRows[NUM_RIDES];

void initRideRows() {
    using namespace ResortWaitsScreen;
    
    rideRows[0] = new RideRow(&text1_content, &text2_content, &text1_font);
    rideRows[1] = new RideRow(&text3_content, &text4_content, &text3_font);
    rideRows[2] = new RideRow(&text5_content, &text6_content, &text5_font);
    rideRows[3] = new RideRow(&text7_content, &text8_content, &text7_font);
    rideRows[4] = new RideRow(&text9_content, &text10_content, &text9_font);
    rideRows[5] = new RideRow(&text11_content, &text12_content, &text11_font);
    Serial.println("initialized ride rows");
}

#endif // WAITS_SCREEN_HELPERS_H