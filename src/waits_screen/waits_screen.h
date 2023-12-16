#ifndef WAITS_SCREEN_H
#define WAITS_SCREEN_H

#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "waits_screen_wrapper.h"
#include "waits_screen_helpers.h"

void init_waits_screen() {
    initRideRows();
}

void get_waits()
{
    HTTPClient http;

    http.begin("https://disney.hillshum.com/waitTimes/");

    int httpResponseCode = http.GET();

    if (httpResponseCode > 0)
    {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);

        String payload = http.getString();
        Serial.println(payload);

        DynamicJsonDocument response(4096 * 2);
        DeserializationError error = deserializeJson(response, payload);
        Serial.println("deserialized json");

        if (error)
        {
            Serial.print(F("deserializeJson() failed with code "));
            Serial.println(error.c_str());
            return;
        }

        ResortWaitsScreen::text0_content = response["name"].as<String>();

        JsonArray rides = response["rides"].as<JsonArray>();

        int i = 0;
        for (JsonObject ride : rides)
        {
            Serial.printf("ride: %d\n", i);
            int waitTime = ride["wait_time"].as<int>();
            Serial.printf("Wait: %d\n", waitTime);
            rideRows[i]->setCurrentWait(waitTime);
            String name = ride["name"].as<String>();
            rideRows[i]->setName(name);
            Serial.println("set name");
            i++;

            if (i == NUM_RIDES)
            {
                break;
            }
        }

        // clear remaining rows
        for (int j = i; j < NUM_RIDES; j++)
        {
            rideRows[j]->setCurrentWait(-1);
            rideRows[j]->setName("");
        }
    }
    else
    {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }
};

void draw_waits_screen() {
    display.clearDisplay();
    ResortWaitsScreen::mainDraw();
    display.display();
}

#endif // WAITS_SCREEN_H