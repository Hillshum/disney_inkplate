#ifndef LOAD_SCREEN_H
#define LOAD_SCREEN_H

#include "Inkplate.h"
#include "Fonts/Roboto_Light_36.h"


extern Inkplate display;

#define NUM_EARS 6

struct Ear
{
    int x;
    int y;
    int radius;
    int rotation;
};

void drawMouseEars(int x, int y, int radius, int rotation = 0)
{
    display.fillCircle(x, y, radius, BLACK);
    int earRadius = radius * 2 / 3;
    double earDistance = radius * sqrt(2);
    Serial.printf("earDistance: %f\n", earDistance);

    // Calculate the rotation in radians
    double rotationRad = rotation * PI / 180.0;

    double ear1RotationRad = rotationRad - PI / 4;
    Serial.printf("ear1RotationRad: %f\n", ear1RotationRad);
    int earX1 = x + earDistance * cos(ear1RotationRad);
    int earY1 = y + earDistance * sin(ear1RotationRad);
    Serial.printf("earX1: %d, earY1: %d\n", earX1, earY1);
    // float ear2RotationRad = rotationRad - PI / 4;

    double ear2RotationRad = rotationRad - PI / 4 * 3;
    Serial.printf("ear2RotationRad: %f\n", ear2RotationRad);
    int earX2 = x + earDistance * cos(ear2RotationRad);
    int earY2 = y + earDistance * sin(ear2RotationRad);
    Serial.printf("earX2: %d, earY2: %d\n", earX2, earY2);
    
    
    // Draw the rotated ears
    display.fillCircle(earX1, earY1, earRadius, BLACK);
    // display.drawCircle(earX2, earY2, earRadius, BLACK);
    display.fillCircle(earX2, earY2, earRadius, BLACK);
}

bool checkDistance(int x1, int y1, int x2, int y2, float distance)
{
    float xDiff = x1 - x2;
    float yDiff = y1 - y2;
    float dist = sqrt(xDiff * xDiff + yDiff * yDiff);
    return dist < distance;
}

float getEarSize(float radius)
{
    float baseDistance = radius * sqrt(2);
    float earRadius = radius * 2 / 3;
    return baseDistance + earRadius + radius;
}


void drawRandomEars()
{
    Ear ears[NUM_EARS];

    for (int i = 0; i < NUM_EARS; i++)
    {
        bool isTooClose = false;

        int x, y, radius, rotation;
        int attempts = 0;
        do {

            isTooClose = false;
            // Generate random values for the ears
            x = random(0, 800);
            y = random(0, 600);
            radius = random(20, 80);
            rotation = random(0, 90) - 45;
            Serial.printf("x: %d, y: %d, radius: %d, rotation: %d\n", x, y, radius, rotation);

            for (int j = 0; j < i; j++)
            {
                Ear ear = ears[j];

                float targetDistance = (getEarSize(radius) + getEarSize(ear.radius)) * .5f;
                
                if (checkDistance(x, y, ear.x, ear.y, targetDistance))
                {
                    Serial.printf("ear %d is too close to ear %d\n", i, j);
                    isTooClose = true;
                }
            }
            attempts++;
            Serial.printf("attempts: %d\n", attempts);

        } while (isTooClose);

        drawMouseEars(x, y, radius, rotation);

        Ear ear = {x, y, radius, rotation};

        ears[i] = ear;
    }
}

void debugDrawMouseEars()
{
    while(true) {
        Serial.println("begging loop");
        display.clearDisplay();
        display.setDisplayMode(INKPLATE_1BIT);
        drawRandomEars();
        display.display();
        delay(3000);
    }
}

void drawLoadScreen()
{
    display.clearDisplay();
    drawRandomEars();
    display.setFont(&Roboto_Light_36);
    display.setCursor(50, 530);
    display.setTextSize(1);
    display.fillRect(40, 490, 440, 50, WHITE);
    display.print("Tapping into the magic...");
    display.display();
    
}

void drawConnectedScreen()
{
    display.fillRect(40, 490, 620, 100, WHITE);
    display.setCursor(50, 530);
    display.print("Tapping into the magic...connected!\n");
    display.setCursor(50, 580);
    display.print("Distilling information...");
    display.partialUpdate();
}

#endif // LOAD_SCREEN_H