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
            String name = parkObj["name"].as<String>();
            time_t epoch = parkObj["time"].as<int>();
            float temp = parkObj["temperature"].as<float>();
            String conditions = parkObj["conditions"].as<String>();


            // time_t unixTimestamp = parks[i].time; // Replace with your Unix timestamp

            // Using gmtime
            tm* timeinfo = gmtime(&epoch);
            
            clockRows[i]->setName(name);
            clockRows[i]->setHours(timeinfo->tm_hour);
            clockRows[i]->setMinutes(timeinfo->tm_min);
            i++;

            if (i >= CLOCK_ROW_COUNT)
            {
                break;
            }

            // Using localtime
            // tm* timeinfo = localtime(&unixTimestamp);

            // // Access the individual components of the time struct
            // int year = timeinfo->tm_year + 1900; // Years since 1900
            // int month = timeinfo->tm_mon + 1;    // Months since January (0-11)
            // int day = timeinfo->tm_mday;         // Day of the month (1-31)
            // int hour = timeinfo->tm_hour;        // Hours since midnight (0-23)
            // int minute = timeinfo->tm_min;       // Minutes after the hour (0-59)
            // int second = timeinfo->tm_sec;       // Seconds after the minute (0-60)

            // // Print the converted time
            // printf("Year: %d\n", year);
            // printf("Month: %d\n", month);
            // printf("Day: %d\n", day);
            // printf("Hour: %d\n", hour);
            // printf("Minute: %d\n", minute);
            // printf("Second: %d\n", second);

            // clockRows[i]->setMinutes(parks[i].temperature);

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