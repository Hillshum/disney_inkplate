#ifndef WEATEHR_SCREEN_H
#define WEATHER_SCREEN_H

#include <HTTPClient.h>
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

void get_weather()
{
    // Create an HTTPClient object
    HTTPClient http;

    // Specify the URL
    http.begin(SECRET_API_ROOT "/getWeathers");

    // Send the GET request
    int httpResponseCode = http.GET();

    // Check the response code
    if (httpResponseCode > 0)
    {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);

        // Get the response payload
        String payload = http.getString();
        Serial.println(payload);

        // Parse the JSON array
        DynamicJsonDocument response(4096 * 2);
        DeserializationError error = deserializeJson(response, payload);
        Serial.println("deserialized json");

        // Check for parsing errors
        if (error)
        {
            Serial.print(F("deserializeJson() failed with code "));
            Serial.println(error.c_str());
            return;
        }

        // Get the array from the JSON document
        JsonArray parksArray = response.as<JsonArray>();

        // Iterate over the array and populate the Park structs
        int i = 0;
        for (JsonObject parkObj : parksArray)
        {
            String name = parkObj["city"].as<String>();
            time_t epoch = parkObj["time"].as<int>();
            float temp = parkObj["temperature"].as<float>();
            int conditionCode = parkObj["conditions"].as<int>() - 1000; // indexes offset to make array smaller
            Serial.printf("condition code: %d\n", conditionCode);
            int iconId = conditions[conditionCode]->iconId;
            // int iconId = 374;

            Serial.printf("epoch in %s: %d\n", name, epoch);

            // time_t unixTimestamp = parks[i].time; // Replace with your Unix timestamp

            // Using gmtime
            tm* timeinfo = gmtime(&epoch);

            int hour = timeinfo->tm_hour % 12;
            if (hour == 0)
            {
                hour = 12;
            }
            bool isAM = timeinfo->tm_hour < 12;
            
            clockRows[i]->setName(name);
            clockRows[i]->setHours(hour);
            clockRows[i]->setMinutes(timeinfo->tm_min);
            clockRows[i]->setIconId(iconId);
            clockRows[i]->setTemperature(String(temp,0) + "°F");
            clockRows[i]->setIconUrl("https://disney.hillshum.com/assets/icons/" + String(iconId) + ".png");
            Serial.printf("icon url: %s\n", clockRows[i]->getIconUrl().c_str());
            i++;

            if (i >= CLOCK_ROW_COUNT)
            {
                break;
            }
        }
    }
    else
    {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }

    // Close the connection
    http.end();
}

void draw_timescreen()
{
    display.clearDisplay();

    for (int i = 0; i < CLOCK_ROW_COUNT; i++)
    {
        bool success = clockRows[i]->drawIcon();
        Serial.printf("draw icon %d: %d\n", i, success);

    }

    weatherScreen::mainDraw();
    display.display();
}

#endif // WEATHER_SCREEN_H