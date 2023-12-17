#ifndef WAITS_SCREEN_HELPERS_H
#define WAITS_SCREEN_HELPERS_H

#include "waits_screen_wrapper.h"

#define NUM_RIDES 6
#define MAX_CHARS_PER_LINE 40

class RideRow {
private: 
    String* waitTime;
    String* name;
    String fullName;

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


public: 

    RideRow(String* name, String* waitTime) {
        this->waitTime = waitTime;
        this->name = name;
    }

    void setName(const String &newName) {

        fullName = newName;
        *name = newName;

        if (newName.length() > MAX_CHARS_PER_LINE)
        {
            *name = newName.substring(0, MAX_CHARS_PER_LINE-3);
            name->concat("...");
        }
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
    
    rideRows[0] = new RideRow(&text1_content, &text2_content);
    rideRows[1] = new RideRow(&text3_content, &text4_content);
    rideRows[2] = new RideRow(&text5_content, &text6_content);
    rideRows[3] = new RideRow(&text7_content, &text8_content);
    rideRows[4] = new RideRow(&text9_content, &text10_content);
    rideRows[5] = new RideRow(&text11_content, &text12_content);
    Serial.println("initialized ride rows");
}

#endif // WAITS_SCREEN_HELPERS_H