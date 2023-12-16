#include "Inkplate.h"
#include "weather_screen_wrapper.h"
#include "arduino_secrets.h"
#include "time_helpers.h"
#include "weather_screen.h"
#include "waits_screen/waits_screen.h"

Inkplate display(INKPLATE_3BIT);

void connectWifi()
{

    int ConnectCount = 20;

    if (WiFi.status() != WL_CONNECTED)
    {
        WiFi.mode(WIFI_STA);
        while (WiFi.status() != WL_CONNECTED)
        {
            if (ConnectCount++ == 20)
            {
                Serial.println("Connect WiFi");
                WiFi.begin(SECRET_SSID, SECRET_WIFI_PW);
                Serial.print("Connecting.");
                ConnectCount = 0;
            }
            Serial.print(".");
            delay(1000);
        }
        Serial.print("\nConnected to: ");
        Serial.println(SECRET_SSID);
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
        Serial.println("Connected WiFi");
    }
} //======================== END WIFI CONNECT =======================

void drawLoadScreen()
{
    display.clearDisplay();
    display.setTextColor(0, 7);
    display.setCursor(150, 320);
    display.setTextSize(4);
    display.print("Welcome to Inkplate 6!");
    display.display();
    
}

void draw_weather()
{
    init_timescreen();
    get_weather();

    Serial.println("got weather");
    draw_timescreen();

}

void draw_wait_times()
{
    init_waits_screen();
    get_waits();

    Serial.println("got wait times");
    draw_waits_screen();
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
    drawLoadScreen();


    connectWifi();
    // draw_weather();
    draw_wait_times();

}

void loop()
{
}
