#ifndef TIME_HELPERS_H
#define TIME_HELPERS_H

#include "Inkplate.h"

void initializeTime(bool isFirstBoot = false, bool pingNtp = false)
{
    char tzString[8] = "CDT+5";
    if (isFirstBoot)
    {
        // getTZString(tzString);
    }

    Serial.printf("Using tzString %s\n", tzString);
    setenv("TZ", tzString, 1);
    tzset();

    if (pingNtp)
    {
    configTzTime(tzString, "0.pool.ntp.org", "1.pool.ntp.org");
    delay(5000);
    }

}

#endif // TIME_HELPERS_H