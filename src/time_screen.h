#ifndef TIME_SCREEN_H
#define TIME_SCREEN_H

#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "time_screen_helpers.h"
#include "generatedUI.h"

#define CLOCK_ROW_COUNT 6

ClockRow* clockRows[CLOCK_ROW_COUNT];

// struct Park
// {
//     String name;
//     int time;
//     float temperature;
//     String conditions;
// };

void init_timescreen()
{
    initClockRows(clockRows);
}

void get_weather()
{
    // Create an HTTPClient object
    HTTPClient http;

    // Specify the URL
    http.begin("https://disney.hillshum.com/getWeathers");

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
        DynamicJsonDocument response(4096);
        DeserializationError error = deserializeJson(response, payload);

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
            int conditions = parkObj["conditions"].as<int>();

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

#endif // TIME_SCREEN_H