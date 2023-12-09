#include "Arduino.h"
#include "Inkplate.h"
#include "Fonts/FreeSansBold24pt7b.h"

extern Inkplate display;

int digital_clock0_h = 9;
int digital_clock0_m = 41;
int digital_clock0_location_x = 300;
int digital_clock0_location_y = 70;
int digital_clock0_size = 64;
int digital_clock0_bitmask[] = {119, 48, 93, 121, 58, 107, 111, 49, 127, 59};
int digital_clock0_triangleX[] = {83, 101, 108, 101, 108, 277, 101, 108, 277, 257, 277, 108, 257, 277, 286, 76, 60, 98, 60, 98, 80, 80, 39, 60, 80, 39, 55, 31, 55, 73, 31, 73, 52, 31, 9, 52, 9, 52, 20, 61, 86, 80, 86, 80, 233, 233, 227, 80, 233, 227, 252, 260, 292, 305, 305, 260, 240, 305, 281, 240, 240, 281, 260, 259, 234, 276, 234, 276, 256, 256, 214, 234, 214, 256, 237, 38, 27, 60, 38, 60, 207, 207, 38, 212, 212, 207, 230};
int digital_clock0_triangleY[] = {30, 13, 60, 13, 60, 14, 13, 60, 14, 57, 14, 60, 57, 14, 29, 36, 47, 61, 47, 61, 198, 198, 201, 47, 198, 201, 219, 252, 232, 253, 252, 253, 390, 252, 406, 390, 406, 390, 416, 227, 202, 249, 202, 249, 203, 203, 247, 249, 203, 247, 224, 60, 35, 49, 49, 60, 200, 50, 201, 200, 200, 201, 220, 231, 252, 252, 252, 252, 403, 403, 390, 252, 390, 403, 415, 439, 424, 392, 439, 392, 394, 394, 439, 439, 439, 394, 424};
int digital_clock0_maxX = 310;
int digital_clock0_maxY = 440;

String text1_content = "Orlando";
int text1_cursor_x = 70;
int text1_cursor_y = 112;
const GFXfont *text1_font = &FreeSansBold24pt7b;

String text2_content = "Anaheim";
int text2_cursor_x = 70;
int text2_cursor_y = 202;
const GFXfont *text2_font = &FreeSansBold24pt7b;

int digital_clock2_h = 9;
int digital_clock2_m = 41;
int digital_clock2_location_x = 300;
int digital_clock2_location_y = 160;
int digital_clock2_size = 64;
int digital_clock2_bitmask[] = {119, 48, 93, 121, 58, 107, 111, 49, 127, 59};
int digital_clock2_triangleX[] = {83, 101, 108, 101, 108, 277, 101, 108, 277, 257, 277, 108, 257, 277, 286, 76, 60, 98, 60, 98, 80, 80, 39, 60, 80, 39, 55, 31, 55, 73, 31, 73, 52, 31, 9, 52, 9, 52, 20, 61, 86, 80, 86, 80, 233, 233, 227, 80, 233, 227, 252, 260, 292, 305, 305, 260, 240, 305, 281, 240, 240, 281, 260, 259, 234, 276, 234, 276, 256, 256, 214, 234, 214, 256, 237, 38, 27, 60, 38, 60, 207, 207, 38, 212, 212, 207, 230};
int digital_clock2_triangleY[] = {30, 13, 60, 13, 60, 14, 13, 60, 14, 57, 14, 60, 57, 14, 29, 36, 47, 61, 47, 61, 198, 198, 201, 47, 198, 201, 219, 252, 232, 253, 252, 253, 390, 252, 406, 390, 406, 390, 416, 227, 202, 249, 202, 249, 203, 203, 247, 249, 203, 247, 224, 60, 35, 49, 49, 60, 200, 50, 201, 200, 200, 201, 220, 231, 252, 252, 252, 252, 403, 403, 390, 252, 390, 403, 415, 439, 424, 392, 439, 392, 394, 394, 439, 439, 439, 394, 424};
int digital_clock2_maxX = 310;
int digital_clock2_maxY = 440;

String text3_content = "Paris";
int text3_cursor_x = 70;
int text3_cursor_y = 292;
const GFXfont *text3_font = &FreeSansBold24pt7b;

String text4_content = "Tokyo";
int text4_cursor_x = 70;
int text4_cursor_y = 382;
const GFXfont *text4_font = &FreeSansBold24pt7b;

String text5_content = "Hong Kong";
int text5_cursor_x = 70;
int text5_cursor_y = 472;
const GFXfont *text5_font = &FreeSansBold24pt7b;

int digital_clock3_h = 9;
int digital_clock3_m = 41;
int digital_clock3_location_x = 300;
int digital_clock3_location_y = 250;
int digital_clock3_size = 64;
int digital_clock3_bitmask[] = {119, 48, 93, 121, 58, 107, 111, 49, 127, 59};
int digital_clock3_triangleX[] = {83, 101, 108, 101, 108, 277, 101, 108, 277, 257, 277, 108, 257, 277, 286, 76, 60, 98, 60, 98, 80, 80, 39, 60, 80, 39, 55, 31, 55, 73, 31, 73, 52, 31, 9, 52, 9, 52, 20, 61, 86, 80, 86, 80, 233, 233, 227, 80, 233, 227, 252, 260, 292, 305, 305, 260, 240, 305, 281, 240, 240, 281, 260, 259, 234, 276, 234, 276, 256, 256, 214, 234, 214, 256, 237, 38, 27, 60, 38, 60, 207, 207, 38, 212, 212, 207, 230};
int digital_clock3_triangleY[] = {30, 13, 60, 13, 60, 14, 13, 60, 14, 57, 14, 60, 57, 14, 29, 36, 47, 61, 47, 61, 198, 198, 201, 47, 198, 201, 219, 252, 232, 253, 252, 253, 390, 252, 406, 390, 406, 390, 416, 227, 202, 249, 202, 249, 203, 203, 247, 249, 203, 247, 224, 60, 35, 49, 49, 60, 200, 50, 201, 200, 200, 201, 220, 231, 252, 252, 252, 252, 403, 403, 390, 252, 390, 403, 415, 439, 424, 392, 439, 392, 394, 394, 439, 439, 439, 394, 424};
int digital_clock3_maxX = 310;
int digital_clock3_maxY = 440;

int digital_clock4_h = 9;
int digital_clock4_m = 41;
int digital_clock4_location_x = 300;
int digital_clock4_location_y = 340;
int digital_clock4_size = 64;
int digital_clock4_bitmask[] = {119, 48, 93, 121, 58, 107, 111, 49, 127, 59};
int digital_clock4_triangleX[] = {83, 101, 108, 101, 108, 277, 101, 108, 277, 257, 277, 108, 257, 277, 286, 76, 60, 98, 60, 98, 80, 80, 39, 60, 80, 39, 55, 31, 55, 73, 31, 73, 52, 31, 9, 52, 9, 52, 20, 61, 86, 80, 86, 80, 233, 233, 227, 80, 233, 227, 252, 260, 292, 305, 305, 260, 240, 305, 281, 240, 240, 281, 260, 259, 234, 276, 234, 276, 256, 256, 214, 234, 214, 256, 237, 38, 27, 60, 38, 60, 207, 207, 38, 212, 212, 207, 230};
int digital_clock4_triangleY[] = {30, 13, 60, 13, 60, 14, 13, 60, 14, 57, 14, 60, 57, 14, 29, 36, 47, 61, 47, 61, 198, 198, 201, 47, 198, 201, 219, 252, 232, 253, 252, 253, 390, 252, 406, 390, 406, 390, 416, 227, 202, 249, 202, 249, 203, 203, 247, 249, 203, 247, 224, 60, 35, 49, 49, 60, 200, 50, 201, 200, 200, 201, 220, 231, 252, 252, 252, 252, 403, 403, 390, 252, 390, 403, 415, 439, 424, 392, 439, 392, 394, 394, 439, 439, 439, 394, 424};
int digital_clock4_maxX = 310;
int digital_clock4_maxY = 440;

int digital_clock5_h = 9;
int digital_clock5_m = 41;
int digital_clock5_location_x = 300;
int digital_clock5_location_y = 430;
int digital_clock5_size = 64;
int digital_clock5_bitmask[] = {119, 48, 93, 121, 58, 107, 111, 49, 127, 59};
int digital_clock5_triangleX[] = {83, 101, 108, 101, 108, 277, 101, 108, 277, 257, 277, 108, 257, 277, 286, 76, 60, 98, 60, 98, 80, 80, 39, 60, 80, 39, 55, 31, 55, 73, 31, 73, 52, 31, 9, 52, 9, 52, 20, 61, 86, 80, 86, 80, 233, 233, 227, 80, 233, 227, 252, 260, 292, 305, 305, 260, 240, 305, 281, 240, 240, 281, 260, 259, 234, 276, 234, 276, 256, 256, 214, 234, 214, 256, 237, 38, 27, 60, 38, 60, 207, 207, 38, 212, 212, 207, 230};
int digital_clock5_triangleY[] = {30, 13, 60, 13, 60, 14, 13, 60, 14, 57, 14, 60, 57, 14, 29, 36, 47, 61, 47, 61, 198, 198, 201, 47, 198, 201, 219, 252, 232, 253, 252, 253, 390, 252, 406, 390, 406, 390, 416, 227, 202, 249, 202, 249, 203, 203, 247, 249, 203, 247, 224, 60, 35, 49, 49, 60, 200, 50, 201, 200, 200, 201, 220, 231, 252, 252, 252, 252, 403, 403, 390, 252, 390, 403, 415, 439, 424, 392, 439, 392, 394, 394, 439, 439, 439, 394, 424};
int digital_clock5_maxX = 310;
int digital_clock5_maxY = 440;

int digital_clock6_h = 9;
int digital_clock6_m = 41;
int digital_clock6_location_x = 300;
int digital_clock6_location_y = 520;
int digital_clock6_size = 64;
int digital_clock6_bitmask[] = {119, 48, 93, 121, 58, 107, 111, 49, 127, 59};
int digital_clock6_triangleX[] = {83, 101, 108, 101, 108, 277, 101, 108, 277, 257, 277, 108, 257, 277, 286, 76, 60, 98, 60, 98, 80, 80, 39, 60, 80, 39, 55, 31, 55, 73, 31, 73, 52, 31, 9, 52, 9, 52, 20, 61, 86, 80, 86, 80, 233, 233, 227, 80, 233, 227, 252, 260, 292, 305, 305, 260, 240, 305, 281, 240, 240, 281, 260, 259, 234, 276, 234, 276, 256, 256, 214, 234, 214, 256, 237, 38, 27, 60, 38, 60, 207, 207, 38, 212, 212, 207, 230};
int digital_clock6_triangleY[] = {30, 13, 60, 13, 60, 14, 13, 60, 14, 57, 14, 60, 57, 14, 29, 36, 47, 61, 47, 61, 198, 198, 201, 47, 198, 201, 219, 252, 232, 253, 252, 253, 390, 252, 406, 390, 406, 390, 416, 227, 202, 249, 202, 249, 203, 203, 247, 249, 203, 247, 224, 60, 35, 49, 49, 60, 200, 50, 201, 200, 200, 201, 220, 231, 252, 252, 252, 252, 403, 403, 390, 252, 390, 403, 415, 439, 424, 392, 439, 392, 394, 394, 439, 439, 439, 394, 424};
int digital_clock6_maxX = 310;
int digital_clock6_maxY = 440;

String text6_content = "Shanghai";
int text6_cursor_x = 70;
int text6_cursor_y = 562;
const GFXfont *text6_font = &FreeSansBold24pt7b;

void mainDraw() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < sizeof(digital_clock0_triangleX) / sizeof(digital_clock0_triangleX[0]); j += 3) {
            int temp[4] = {digital_clock0_h / 10 % 10, digital_clock0_h % 10, digital_clock0_m / 10 % 10, digital_clock0_m % 10};
            int b = digital_clock0_bitmask[temp[i]];
            if (b & (1 << ((j - 1) / (3 * 4)))) {
                display.fillTriangle(
                    (int)((float)i * (float)digital_clock0_maxX / (float)digital_clock0_maxY * (float)digital_clock0_size * 1.1 + (float)digital_clock0_location_x + (float)digital_clock0_maxX / (float)digital_clock0_maxY * (float)digital_clock0_size * (float)digital_clock0_triangleX[j + 0] / (float)digital_clock0_maxX),
                    (int)((float)digital_clock0_location_y + (float)digital_clock0_size * (float)digital_clock0_triangleY[j + 0] / (float)digital_clock0_maxY),

                    (int)((float)i * (float)digital_clock0_maxX / (float)digital_clock0_maxY * (float)digital_clock0_size * 1.1 + (float)digital_clock0_location_x + (float)digital_clock0_maxX / (float)digital_clock0_maxY * (float)digital_clock0_size * (float)digital_clock0_triangleX[j + 1] / (float)digital_clock0_maxX),
                    (int)((float)digital_clock0_location_y + (float)digital_clock0_size * (float)digital_clock0_triangleY[j + 1] / (float)digital_clock0_maxY),

                    (int)((float)i * (float)digital_clock0_maxX / (float)digital_clock0_maxY * (float)digital_clock0_size * 1.1 + (float)digital_clock0_location_x + (float)digital_clock0_maxX / (float)digital_clock0_maxY * (float)digital_clock0_size * (float)digital_clock0_triangleX[j + 2] / (float)digital_clock0_maxX),
                    (int)((float)digital_clock0_location_y + (float)digital_clock0_size * (float)digital_clock0_triangleY[j + 2] / (float)digital_clock0_maxY),

                    0);
            }
        }
    }

    int digital_clock0_r = 0.05 * (float)digital_clock0_size;

    display.fillCircle((int)((float)digital_clock0_location_x + 4.0 * (float)digital_clock0_maxX / (float)digital_clock0_maxY * (float)digital_clock0_size * 1.075 / 2.0), (int)((float)digital_clock0_location_y + (float)digital_clock0_size * 0.4), digital_clock0_r, 0);
    display.fillCircle((int)((float)digital_clock0_location_x + 4.0 * (float)digital_clock0_maxX / (float)digital_clock0_maxY * (float)digital_clock0_size * 1.075 / 2.0), (int)((float)digital_clock0_location_y + (float)digital_clock0_size * 0.6), digital_clock0_r, 0);
    display.setFont(text1_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text1_cursor_x, text1_cursor_y);
    display.print(text1_content);

    display.setFont(text2_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text2_cursor_x, text2_cursor_y);
    display.print(text2_content);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < sizeof(digital_clock2_triangleX) / sizeof(digital_clock2_triangleX[0]); j += 3) {
            int temp[4] = {digital_clock2_h / 10 % 10, digital_clock2_h % 10, digital_clock2_m / 10 % 10, digital_clock2_m % 10};
            int b = digital_clock2_bitmask[temp[i]];
            if (b & (1 << ((j - 1) / (3 * 4)))) {
                display.fillTriangle(
                    (int)((float)i * (float)digital_clock2_maxX / (float)digital_clock2_maxY * (float)digital_clock2_size * 1.1 + (float)digital_clock2_location_x + (float)digital_clock2_maxX / (float)digital_clock2_maxY * (float)digital_clock2_size * (float)digital_clock2_triangleX[j + 0] / (float)digital_clock2_maxX),
                    (int)((float)digital_clock2_location_y + (float)digital_clock2_size * (float)digital_clock2_triangleY[j + 0] / (float)digital_clock2_maxY),

                    (int)((float)i * (float)digital_clock2_maxX / (float)digital_clock2_maxY * (float)digital_clock2_size * 1.1 + (float)digital_clock2_location_x + (float)digital_clock2_maxX / (float)digital_clock2_maxY * (float)digital_clock2_size * (float)digital_clock2_triangleX[j + 1] / (float)digital_clock2_maxX),
                    (int)((float)digital_clock2_location_y + (float)digital_clock2_size * (float)digital_clock2_triangleY[j + 1] / (float)digital_clock2_maxY),

                    (int)((float)i * (float)digital_clock2_maxX / (float)digital_clock2_maxY * (float)digital_clock2_size * 1.1 + (float)digital_clock2_location_x + (float)digital_clock2_maxX / (float)digital_clock2_maxY * (float)digital_clock2_size * (float)digital_clock2_triangleX[j + 2] / (float)digital_clock2_maxX),
                    (int)((float)digital_clock2_location_y + (float)digital_clock2_size * (float)digital_clock2_triangleY[j + 2] / (float)digital_clock2_maxY),

                    0);
            }
        }
    }

    int digital_clock2_r = 0.05 * (float)digital_clock2_size;

    display.fillCircle((int)((float)digital_clock2_location_x + 4.0 * (float)digital_clock2_maxX / (float)digital_clock2_maxY * (float)digital_clock2_size * 1.075 / 2.0), (int)((float)digital_clock2_location_y + (float)digital_clock2_size * 0.4), digital_clock2_r, 0);
    display.fillCircle((int)((float)digital_clock2_location_x + 4.0 * (float)digital_clock2_maxX / (float)digital_clock2_maxY * (float)digital_clock2_size * 1.075 / 2.0), (int)((float)digital_clock2_location_y + (float)digital_clock2_size * 0.6), digital_clock2_r, 0);
    display.setFont(text3_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text3_cursor_x, text3_cursor_y);
    display.print(text3_content);

    display.setFont(text4_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text4_cursor_x, text4_cursor_y);
    display.print(text4_content);

    display.setFont(text5_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text5_cursor_x, text5_cursor_y);
    display.print(text5_content);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < sizeof(digital_clock3_triangleX) / sizeof(digital_clock3_triangleX[0]); j += 3) {
            int temp[4] = {digital_clock3_h / 10 % 10, digital_clock3_h % 10, digital_clock3_m / 10 % 10, digital_clock3_m % 10};
            int b = digital_clock3_bitmask[temp[i]];
            if (b & (1 << ((j - 1) / (3 * 4)))) {
                display.fillTriangle(
                    (int)((float)i * (float)digital_clock3_maxX / (float)digital_clock3_maxY * (float)digital_clock3_size * 1.1 + (float)digital_clock3_location_x + (float)digital_clock3_maxX / (float)digital_clock3_maxY * (float)digital_clock3_size * (float)digital_clock3_triangleX[j + 0] / (float)digital_clock3_maxX),
                    (int)((float)digital_clock3_location_y + (float)digital_clock3_size * (float)digital_clock3_triangleY[j + 0] / (float)digital_clock3_maxY),

                    (int)((float)i * (float)digital_clock3_maxX / (float)digital_clock3_maxY * (float)digital_clock3_size * 1.1 + (float)digital_clock3_location_x + (float)digital_clock3_maxX / (float)digital_clock3_maxY * (float)digital_clock3_size * (float)digital_clock3_triangleX[j + 1] / (float)digital_clock3_maxX),
                    (int)((float)digital_clock3_location_y + (float)digital_clock3_size * (float)digital_clock3_triangleY[j + 1] / (float)digital_clock3_maxY),

                    (int)((float)i * (float)digital_clock3_maxX / (float)digital_clock3_maxY * (float)digital_clock3_size * 1.1 + (float)digital_clock3_location_x + (float)digital_clock3_maxX / (float)digital_clock3_maxY * (float)digital_clock3_size * (float)digital_clock3_triangleX[j + 2] / (float)digital_clock3_maxX),
                    (int)((float)digital_clock3_location_y + (float)digital_clock3_size * (float)digital_clock3_triangleY[j + 2] / (float)digital_clock3_maxY),

                    0);
            }
        }
    }

    int digital_clock3_r = 0.05 * (float)digital_clock3_size;

    display.fillCircle((int)((float)digital_clock3_location_x + 4.0 * (float)digital_clock3_maxX / (float)digital_clock3_maxY * (float)digital_clock3_size * 1.075 / 2.0), (int)((float)digital_clock3_location_y + (float)digital_clock3_size * 0.4), digital_clock3_r, 0);
    display.fillCircle((int)((float)digital_clock3_location_x + 4.0 * (float)digital_clock3_maxX / (float)digital_clock3_maxY * (float)digital_clock3_size * 1.075 / 2.0), (int)((float)digital_clock3_location_y + (float)digital_clock3_size * 0.6), digital_clock3_r, 0);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < sizeof(digital_clock4_triangleX) / sizeof(digital_clock4_triangleX[0]); j += 3) {
            int temp[4] = {digital_clock4_h / 10 % 10, digital_clock4_h % 10, digital_clock4_m / 10 % 10, digital_clock4_m % 10};
            int b = digital_clock4_bitmask[temp[i]];
            if (b & (1 << ((j - 1) / (3 * 4)))) {
                display.fillTriangle(
                    (int)((float)i * (float)digital_clock4_maxX / (float)digital_clock4_maxY * (float)digital_clock4_size * 1.1 + (float)digital_clock4_location_x + (float)digital_clock4_maxX / (float)digital_clock4_maxY * (float)digital_clock4_size * (float)digital_clock4_triangleX[j + 0] / (float)digital_clock4_maxX),
                    (int)((float)digital_clock4_location_y + (float)digital_clock4_size * (float)digital_clock4_triangleY[j + 0] / (float)digital_clock4_maxY),

                    (int)((float)i * (float)digital_clock4_maxX / (float)digital_clock4_maxY * (float)digital_clock4_size * 1.1 + (float)digital_clock4_location_x + (float)digital_clock4_maxX / (float)digital_clock4_maxY * (float)digital_clock4_size * (float)digital_clock4_triangleX[j + 1] / (float)digital_clock4_maxX),
                    (int)((float)digital_clock4_location_y + (float)digital_clock4_size * (float)digital_clock4_triangleY[j + 1] / (float)digital_clock4_maxY),

                    (int)((float)i * (float)digital_clock4_maxX / (float)digital_clock4_maxY * (float)digital_clock4_size * 1.1 + (float)digital_clock4_location_x + (float)digital_clock4_maxX / (float)digital_clock4_maxY * (float)digital_clock4_size * (float)digital_clock4_triangleX[j + 2] / (float)digital_clock4_maxX),
                    (int)((float)digital_clock4_location_y + (float)digital_clock4_size * (float)digital_clock4_triangleY[j + 2] / (float)digital_clock4_maxY),

                    0);
            }
        }
    }

    int digital_clock4_r = 0.05 * (float)digital_clock4_size;

    display.fillCircle((int)((float)digital_clock4_location_x + 4.0 * (float)digital_clock4_maxX / (float)digital_clock4_maxY * (float)digital_clock4_size * 1.075 / 2.0), (int)((float)digital_clock4_location_y + (float)digital_clock4_size * 0.4), digital_clock4_r, 0);
    display.fillCircle((int)((float)digital_clock4_location_x + 4.0 * (float)digital_clock4_maxX / (float)digital_clock4_maxY * (float)digital_clock4_size * 1.075 / 2.0), (int)((float)digital_clock4_location_y + (float)digital_clock4_size * 0.6), digital_clock4_r, 0);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < sizeof(digital_clock5_triangleX) / sizeof(digital_clock5_triangleX[0]); j += 3) {
            int temp[4] = {digital_clock5_h / 10 % 10, digital_clock5_h % 10, digital_clock5_m / 10 % 10, digital_clock5_m % 10};
            int b = digital_clock5_bitmask[temp[i]];
            if (b & (1 << ((j - 1) / (3 * 4)))) {
                display.fillTriangle(
                    (int)((float)i * (float)digital_clock5_maxX / (float)digital_clock5_maxY * (float)digital_clock5_size * 1.1 + (float)digital_clock5_location_x + (float)digital_clock5_maxX / (float)digital_clock5_maxY * (float)digital_clock5_size * (float)digital_clock5_triangleX[j + 0] / (float)digital_clock5_maxX),
                    (int)((float)digital_clock5_location_y + (float)digital_clock5_size * (float)digital_clock5_triangleY[j + 0] / (float)digital_clock5_maxY),

                    (int)((float)i * (float)digital_clock5_maxX / (float)digital_clock5_maxY * (float)digital_clock5_size * 1.1 + (float)digital_clock5_location_x + (float)digital_clock5_maxX / (float)digital_clock5_maxY * (float)digital_clock5_size * (float)digital_clock5_triangleX[j + 1] / (float)digital_clock5_maxX),
                    (int)((float)digital_clock5_location_y + (float)digital_clock5_size * (float)digital_clock5_triangleY[j + 1] / (float)digital_clock5_maxY),

                    (int)((float)i * (float)digital_clock5_maxX / (float)digital_clock5_maxY * (float)digital_clock5_size * 1.1 + (float)digital_clock5_location_x + (float)digital_clock5_maxX / (float)digital_clock5_maxY * (float)digital_clock5_size * (float)digital_clock5_triangleX[j + 2] / (float)digital_clock5_maxX),
                    (int)((float)digital_clock5_location_y + (float)digital_clock5_size * (float)digital_clock5_triangleY[j + 2] / (float)digital_clock5_maxY),

                    0);
            }
        }
    }

    int digital_clock5_r = 0.05 * (float)digital_clock5_size;

    display.fillCircle((int)((float)digital_clock5_location_x + 4.0 * (float)digital_clock5_maxX / (float)digital_clock5_maxY * (float)digital_clock5_size * 1.075 / 2.0), (int)((float)digital_clock5_location_y + (float)digital_clock5_size * 0.4), digital_clock5_r, 0);
    display.fillCircle((int)((float)digital_clock5_location_x + 4.0 * (float)digital_clock5_maxX / (float)digital_clock5_maxY * (float)digital_clock5_size * 1.075 / 2.0), (int)((float)digital_clock5_location_y + (float)digital_clock5_size * 0.6), digital_clock5_r, 0);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < sizeof(digital_clock6_triangleX) / sizeof(digital_clock6_triangleX[0]); j += 3) {
            int temp[4] = {digital_clock6_h / 10 % 10, digital_clock6_h % 10, digital_clock6_m / 10 % 10, digital_clock6_m % 10};
            int b = digital_clock6_bitmask[temp[i]];
            if (b & (1 << ((j - 1) / (3 * 4)))) {
                display.fillTriangle(
                    (int)((float)i * (float)digital_clock6_maxX / (float)digital_clock6_maxY * (float)digital_clock6_size * 1.1 + (float)digital_clock6_location_x + (float)digital_clock6_maxX / (float)digital_clock6_maxY * (float)digital_clock6_size * (float)digital_clock6_triangleX[j + 0] / (float)digital_clock6_maxX),
                    (int)((float)digital_clock6_location_y + (float)digital_clock6_size * (float)digital_clock6_triangleY[j + 0] / (float)digital_clock6_maxY),

                    (int)((float)i * (float)digital_clock6_maxX / (float)digital_clock6_maxY * (float)digital_clock6_size * 1.1 + (float)digital_clock6_location_x + (float)digital_clock6_maxX / (float)digital_clock6_maxY * (float)digital_clock6_size * (float)digital_clock6_triangleX[j + 1] / (float)digital_clock6_maxX),
                    (int)((float)digital_clock6_location_y + (float)digital_clock6_size * (float)digital_clock6_triangleY[j + 1] / (float)digital_clock6_maxY),

                    (int)((float)i * (float)digital_clock6_maxX / (float)digital_clock6_maxY * (float)digital_clock6_size * 1.1 + (float)digital_clock6_location_x + (float)digital_clock6_maxX / (float)digital_clock6_maxY * (float)digital_clock6_size * (float)digital_clock6_triangleX[j + 2] / (float)digital_clock6_maxX),
                    (int)((float)digital_clock6_location_y + (float)digital_clock6_size * (float)digital_clock6_triangleY[j + 2] / (float)digital_clock6_maxY),

                    0);
            }
        }
    }

    int digital_clock6_r = 0.05 * (float)digital_clock6_size;

    display.fillCircle((int)((float)digital_clock6_location_x + 4.0 * (float)digital_clock6_maxX / (float)digital_clock6_maxY * (float)digital_clock6_size * 1.075 / 2.0), (int)((float)digital_clock6_location_y + (float)digital_clock6_size * 0.4), digital_clock6_r, 0);
    display.fillCircle((int)((float)digital_clock6_location_x + 4.0 * (float)digital_clock6_maxX / (float)digital_clock6_maxY * (float)digital_clock6_size * 1.075 / 2.0), (int)((float)digital_clock6_location_y + (float)digital_clock6_size * 0.6), digital_clock6_r, 0);
    display.setFont(text6_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text6_cursor_x, text6_cursor_y);
    display.print(text6_content);

}
