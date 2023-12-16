#include <WiFiMulti.h>
#include "Inkplate.h"
#include "driver/rtc_io.h"
#include "weather_screen_wrapper.h"
#include "arduino_secrets.h"
#include "time_helpers.h"
#include "weather_screen.h"
#include "waits_screen/waits_screen.h"
#include "Fonts/Roboto_Light_36.h"

Inkplate display(INKPLATE_1BIT);

enum Screen
{
    WEATHER,
    WAITS
};

RTC_DATA_ATTR Screen nextScreen = Screen::WEATHER;
RTC_DATA_ATTR bool isFirstBoot = true;
RTC_DATA_ATTR char lastResort[20] = "";

#define uS_TO_S_FACTOR 1000000 /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP 10        /* Time ESP32 will go to sleep (in seconds) */

WiFiMulti wifiMulti;

int connectWifi()
{
    ADD_WIFI_AP_DETAILS(wifiMulti);
    WiFi.mode(WIFI_STA);
    // int n = WiFi.scanNetworks();
    // Serial.println("scan done");
    // if (n == 0) {
    //     Serial.println("no networks found");
    // } 
    // else {
    //     Serial.print(n);
    //     Serial.println(" networks found");
    //     for (int i = 0; i < n; ++i) {
    //     // Print SSID and RSSI for each network found
    //     Serial.print(i + 1);
    //     Serial.print(": ");
    //     Serial.print(WiFi.SSID(i));
    //     Serial.print(" (");
    //     Serial.print(WiFi.RSSI(i));
    //     Serial.print(")");
    //     Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
    //     delay(10);
    //     }
    // }

    Serial.println("Connecting Wifi...");
    if (wifiMulti.run() == WL_CONNECTED) {
        Serial.println("");
        Serial.println("WiFi connected");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
        Serial.print("SSID: ");
        Serial.println(WiFi.SSID());
        return true;
    }
    return false;
}

void drawLoadScreen()
{
    display.clearDisplay();
    display.setFont(&Roboto_Light_36);
    display.setCursor(50, 600);
    display.setTextSize(1);
    display.print("Connecting to WiFi...");
    display.display();
    
}

void draw_weather()
{
    init_timescreen();
    if (get_weather())
    {
        Serial.println("got weather");
        draw_timescreen();
    }

}

void draw_wait_times()
{
    init_waits_screen();
    if (get_waits(lastResort)) {
        Serial.println("got wait times");
        draw_waits_screen();
    }
}

void drawNextScreen()
{
    display.setDisplayMode(INKPLATE_3BIT);
    switch(nextScreen)
    {
        case Screen::WEATHER:
            draw_weather();
            nextScreen = Screen::WAITS;
            break;
        case Screen::WAITS:
            draw_wait_times();
            nextScreen = Screen::WEATHER;
            break;
    }
    isFirstBoot = false;

}

void setup()
{

    Serial.begin(115200);
    while (!Serial)
    {
        ;
    }

    Serial.println("serial monitor initialized");
    display.begin();
    if (isFirstBoot)
    {
        drawLoadScreen();
    }

    if (connectWifi())
    {
        Serial.println("connected to wifi");
        if (isFirstBoot) 
        {
            display.print("connected!");
            display.partialUpdate();
        }

        drawNextScreen();
    }
    else
    {
        Serial.println("failed to connect to wifi");
        display.print("unable to connect");
        display.display();
    }


    esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
    esp_deep_sleep_start();
}

void loop()
{
}
