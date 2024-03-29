#ifndef WAITS_SCREEN_H
#define WAITS_SCREEN_H

#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "waits_screen_wrapper.h"
#include "waits_screen_helpers.h"
#include "arduino_secrets.h"

void init_waits_screen() {
    initRideRows();
}

bool get_waits(char resortName[])
{
    WiFiClientSecure client;
    client.setInsecure();
    HTTPClient http;
    char url[100] = SECRET_API_ROOT "/waitTimes/?previousResort=";
    strlcat(url, resortName, 100);

    Serial.printf("url: %s\n", url);

    http.begin(url);
    http.useHTTP10(true);

    int httpResponseCode = http.GET();

    if (httpResponseCode <= 0)
    {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
        http.end();
        return false;
    }

    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    Stream &stream = http.getStream();

    StaticJsonDocument<1536> response;
    DeserializationError error = deserializeJson(response, stream);
    Serial.println("deserialized json");

    http.end();
    if (error)
    {
        Serial.print("deserializeJson() failed with code ");
        Serial.println(error.c_str());
        return false;
    }

    strcpy(resortName, response["id"].as<const char*>());
    ResortWaitsScreen::text0_content = response["name"].as<String>();

    JsonArray rides = response["rides"].as<JsonArray>();

    // TODO: Check for empty array and don't draw screen
    int i = 0;
    for (JsonObject ride : rides)
    {
        Serial.printf("ride: %d\n", i);
        int waitTime = ride["wait_time"].as<int>();
        Serial.printf("Wait: %d\n", waitTime);
        rideRows[i]->setCurrentWait(waitTime);
        const char * name = ride["name"].as<const char*>();
        rideRows[i]->setName(name);
        Serial.println("set name");
        rideRows[i]->setOpen(ride["is_open"].as<bool>());
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

    return true;

};

void draw_waits_screen() {
    display.clearDisplay();
    ResortWaitsScreen::mainDraw();
    display.display();
}

#endif // WAITS_SCREEN_H