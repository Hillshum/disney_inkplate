#ifndef WEATEHR_SCREEN_H
#define WEATHER_SCREEN_H

#include <HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#include "weather_screen_helpers.h"
#include "conditions.h"
#include "weather_screen_wrapper.h"
#include "arduino_secrets.h"

#define CLOCK_ROW_COUNT 6

ClockRow* clockRows[CLOCK_ROW_COUNT];


void init_timescreen()
{
    initClockRows(clockRows);
    initConditions();
}

bool get_weather()
{
    WiFiClientSecure client;
    client.setInsecure();
    // Create an HTTPClient object
    HTTPClient http;

    // Specify the URL
    http.begin(client, SECRET_API_ROOT "/getWeathers");
    http.useHTTP10(true);

    // Send the GET request
    int httpResponseCode = http.GET();

    // Check the response code
    if (httpResponseCode <= 0)
    {
        Serial.print(F("Error code: "));
        Serial.println(httpResponseCode);
        return false;
    }

    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    // create a new stream to hold the response data
    Stream &stream = http.getStream();

    // Parse the JSON array
    StaticJsonDocument<768> response;
    DeserializationError error = deserializeJson(response, stream);
    Serial.println("deserialized json");

    // Check for parsing errors
    if (error)
    {
        Serial.print(F("deserializeJson() failed with code "));
        Serial.println(error.c_str());
        return false;
    }

    // Get the array from the JSON document
    JsonArray parksArray = response.as<JsonArray>();

    http.end();
    // Iterate over the array and populate the Park structs
    int i = 0;
    for (JsonObject parkObj : parksArray)
    {
        String name = parkObj["city"].as<String>();
        time_t epoch = parkObj["time"].as<int>();
        float temp = parkObj["temperature"].as<float>();
        int conditionCode = parkObj["conditions"].as<int>() - 1000; // indexes offset to make array smaller
        bool isDay = parkObj["isDay"].as<bool>();
        Serial.printf("condition code: %d\n", conditionCode);
        int iconId = conditions[conditionCode]->iconId;

        Serial.printf("epoch in %s: %d\n", name, epoch);


        // Using gmtime
        tm* timeinfo = gmtime(&epoch);

        int hour = timeinfo->tm_hour % 12;
        if (hour == 0)
        {
            hour = 12;
        }
        bool isAM = timeinfo->tm_hour < 12;
        
        const unsigned int TEMPERATURE_STRING_LENGTH = 5;
        char tempString[TEMPERATURE_STRING_LENGTH];
        dtostrf(temp, TEMPERATURE_STRING_LENGTH - 2, 0, tempString);
        strlcat(tempString, "F", TEMPERATURE_STRING_LENGTH);

        clockRows[i]->setName(name);
        clockRows[i]->setHours(hour);
        clockRows[i]->setMinutes(timeinfo->tm_min);
        clockRows[i]->setIconId(iconId);
        clockRows[i]->setTemperature(tempString);
        clockRows[i]->setIsDay(isDay);
        clockRows[i]->setIsAm(isAM);
        i++;

        if (i >= CLOCK_ROW_COUNT)
        {
            break;
        }
    }

    return true;
}

void draw_timescreen()
{
    display.clearDisplay();

    for (int i = 0; i < CLOCK_ROW_COUNT; i++)
    {
        bool success = clockRows[i]->drawIcon();
        Serial.printf("draw icon %d: %d\n", i, success);
        clockRows[i]->drawAmPm();

    }

    weatherScreen::mainDraw();
    display.display();
}

#endif // WEATHER_SCREEN_H