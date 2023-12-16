#ifndef WAITS_SCREEN_HELPERS_H
#define WAITS_SCREEN_HELPERS_H

#include "waits_screen_wrapper.h"

#define NUM_RIDES 4

class RideRow {
private: 
    String* waitTime;
    String* name;
    int currentWait;

public: 

    RideRow(String* name, String* waitTime) {
        this->waitTime = waitTime;
        this->name = name;
    }

    void setName(const String &newName) {
        *name = newName;
    }

    void setCurrentWait(int newWait) {

        currentWait = newWait;
        if (newWait == -1)
        {
            *waitTime = String("");
            return;
        }

        String newWaitString = String(newWait);
        newWaitString.concat(" min");
        Serial.printf("new wait string: %s\n", newWaitString.c_str());
        *waitTime = newWaitString;
        Serial.printf("setting wait to %d\n", newWait);
    }

};

RideRow* rideRows[NUM_RIDES];

void initRideRows() {
    using namespace ResortWaitsScreen;
    
    rideRows[0] = new RideRow(&text1_content, &text2_content);
    rideRows[1] = new RideRow(&text3_content, &text4_content);
    rideRows[2] = new RideRow(&text5_content, &text6_content);
    rideRows[3] = new RideRow(&text7_content, &text8_content);
    Serial.println("initialized ride rows");
}

#endif // WAITS_SCREEN_HELPERS_H