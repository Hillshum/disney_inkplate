#include "Inkplate.h"
#include "generatedUI.h"
#include "arduino_secrets.h"
#include "time_helpers.h"
#include "time_screen.h"

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

void setup()
{

    Serial.begin(115200);
    while (!Serial)
    {
        ;
    }

    Serial.println("serial monitor initialized");
    display.begin();
    display.clearDisplay();

    display.setTextColor(0, 7);
    display.setCursor(150, 320);
    display.setTextSize(4);
    display.print("Welcome to Inkplate 6!");
    display.display();

    init_timescreen();

    connectWifi();

    get_weather();

    Serial.println("got weather");
    display.clearDisplay();
    draw_timescreen();
    delay(3000);
}

void loop()
{
}
