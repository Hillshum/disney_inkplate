#include "Arduino.h"
#include "Inkplate.h"
#include "Fonts/FreeSans24pt7b.h"
#include "Fonts/FreeSans18pt7b.h"
#include "Fonts/FreeSansBold24pt7b.h"

extern Inkplate display;

namespace weatherScreen {
int digital_clock0_h = 9;
int digital_clock0_m = 41;
int digital_clock0_location_x = 320;
int digital_clock0_location_y = 103;
int digital_clock0_size = 50;
int digital_clock0_bitmask[] = {119, 48, 93, 121, 58, 107, 111, 49, 127, 59};
int digital_clock0_triangleX[] = {83, 101, 108, 101, 108, 277, 101, 108, 277, 257, 277, 108, 257, 277, 286, 76, 60, 98, 60, 98, 80, 80, 39, 60, 80, 39, 55, 31, 55, 73, 31, 73, 52, 31, 9, 52, 9, 52, 20, 61, 86, 80, 86, 80, 233, 233, 227, 80, 233, 227, 252, 260, 292, 305, 305, 260, 240, 305, 281, 240, 240, 281, 260, 259, 234, 276, 234, 276, 256, 256, 214, 234, 214, 256, 237, 38, 27, 60, 38, 60, 207, 207, 38, 212, 212, 207, 230};
int digital_clock0_triangleY[] = {30, 13, 60, 13, 60, 14, 13, 60, 14, 57, 14, 60, 57, 14, 29, 36, 47, 61, 47, 61, 198, 198, 201, 47, 198, 201, 219, 252, 232, 253, 252, 253, 390, 252, 406, 390, 406, 390, 416, 227, 202, 249, 202, 249, 203, 203, 247, 249, 203, 247, 224, 60, 35, 49, 49, 60, 200, 50, 201, 200, 200, 201, 220, 231, 252, 252, 252, 252, 403, 403, 390, 252, 390, 403, 415, 439, 424, 392, 439, 392, 394, 394, 439, 439, 439, 394, 424};
int digital_clock0_maxX = 310;
int digital_clock0_maxY = 440;

String text1_content = "Orlando";
int text1_cursor_x = 40;
int text1_cursor_y = 145;
const GFXfont *text1_font = &FreeSans24pt7b;

String text2_content = "Anaheim";
int text2_cursor_x = 40;
int text2_cursor_y = 230;
const GFXfont *text2_font = &FreeSans24pt7b;

int digital_clock2_h = 9;
int digital_clock2_m = 41;
int digital_clock2_location_x = 320;
int digital_clock2_location_y = 188;
int digital_clock2_size = 50;
int digital_clock2_bitmask[] = {119, 48, 93, 121, 58, 107, 111, 49, 127, 59};
int digital_clock2_triangleX[] = {83, 101, 108, 101, 108, 277, 101, 108, 277, 257, 277, 108, 257, 277, 286, 76, 60, 98, 60, 98, 80, 80, 39, 60, 80, 39, 55, 31, 55, 73, 31, 73, 52, 31, 9, 52, 9, 52, 20, 61, 86, 80, 86, 80, 233, 233, 227, 80, 233, 227, 252, 260, 292, 305, 305, 260, 240, 305, 281, 240, 240, 281, 260, 259, 234, 276, 234, 276, 256, 256, 214, 234, 214, 256, 237, 38, 27, 60, 38, 60, 207, 207, 38, 212, 212, 207, 230};
int digital_clock2_triangleY[] = {30, 13, 60, 13, 60, 14, 13, 60, 14, 57, 14, 60, 57, 14, 29, 36, 47, 61, 47, 61, 198, 198, 201, 47, 198, 201, 219, 252, 232, 253, 252, 253, 390, 252, 406, 390, 406, 390, 416, 227, 202, 249, 202, 249, 203, 203, 247, 249, 203, 247, 224, 60, 35, 49, 49, 60, 200, 50, 201, 200, 200, 201, 220, 231, 252, 252, 252, 252, 403, 403, 390, 252, 390, 403, 415, 439, 424, 392, 439, 392, 394, 394, 439, 439, 439, 394, 424};
int digital_clock2_maxX = 310;
int digital_clock2_maxY = 440;

String text3_content = "Paris";
int text3_cursor_x = 40;
int text3_cursor_y = 315;
const GFXfont *text3_font = &FreeSans24pt7b;

String text4_content = "Tokyo";
int text4_cursor_x = 40;
int text4_cursor_y = 400;
const GFXfont *text4_font = &FreeSans24pt7b;

String text5_content = "Hong Kong";
int text5_cursor_x = 38;
int text5_cursor_y = 485;
const GFXfont *text5_font = &FreeSans24pt7b;

int digital_clock3_h = 9;
int digital_clock3_m = 41;
int digital_clock3_location_x = 320;
int digital_clock3_location_y = 273;
int digital_clock3_size = 50;
int digital_clock3_bitmask[] = {119, 48, 93, 121, 58, 107, 111, 49, 127, 59};
int digital_clock3_triangleX[] = {83, 101, 108, 101, 108, 277, 101, 108, 277, 257, 277, 108, 257, 277, 286, 76, 60, 98, 60, 98, 80, 80, 39, 60, 80, 39, 55, 31, 55, 73, 31, 73, 52, 31, 9, 52, 9, 52, 20, 61, 86, 80, 86, 80, 233, 233, 227, 80, 233, 227, 252, 260, 292, 305, 305, 260, 240, 305, 281, 240, 240, 281, 260, 259, 234, 276, 234, 276, 256, 256, 214, 234, 214, 256, 237, 38, 27, 60, 38, 60, 207, 207, 38, 212, 212, 207, 230};
int digital_clock3_triangleY[] = {30, 13, 60, 13, 60, 14, 13, 60, 14, 57, 14, 60, 57, 14, 29, 36, 47, 61, 47, 61, 198, 198, 201, 47, 198, 201, 219, 252, 232, 253, 252, 253, 390, 252, 406, 390, 406, 390, 416, 227, 202, 249, 202, 249, 203, 203, 247, 249, 203, 247, 224, 60, 35, 49, 49, 60, 200, 50, 201, 200, 200, 201, 220, 231, 252, 252, 252, 252, 403, 403, 390, 252, 390, 403, 415, 439, 424, 392, 439, 392, 394, 394, 439, 439, 439, 394, 424};
int digital_clock3_maxX = 310;
int digital_clock3_maxY = 440;

int digital_clock4_h = 9;
int digital_clock4_m = 41;
int digital_clock4_location_x = 320;
int digital_clock4_location_y = 358;
int digital_clock4_size = 50;
int digital_clock4_bitmask[] = {119, 48, 93, 121, 58, 107, 111, 49, 127, 59};
int digital_clock4_triangleX[] = {83, 101, 108, 101, 108, 277, 101, 108, 277, 257, 277, 108, 257, 277, 286, 76, 60, 98, 60, 98, 80, 80, 39, 60, 80, 39, 55, 31, 55, 73, 31, 73, 52, 31, 9, 52, 9, 52, 20, 61, 86, 80, 86, 80, 233, 233, 227, 80, 233, 227, 252, 260, 292, 305, 305, 260, 240, 305, 281, 240, 240, 281, 260, 259, 234, 276, 234, 276, 256, 256, 214, 234, 214, 256, 237, 38, 27, 60, 38, 60, 207, 207, 38, 212, 212, 207, 230};
int digital_clock4_triangleY[] = {30, 13, 60, 13, 60, 14, 13, 60, 14, 57, 14, 60, 57, 14, 29, 36, 47, 61, 47, 61, 198, 198, 201, 47, 198, 201, 219, 252, 232, 253, 252, 253, 390, 252, 406, 390, 406, 390, 416, 227, 202, 249, 202, 249, 203, 203, 247, 249, 203, 247, 224, 60, 35, 49, 49, 60, 200, 50, 201, 200, 200, 201, 220, 231, 252, 252, 252, 252, 403, 403, 390, 252, 390, 403, 415, 439, 424, 392, 439, 392, 394, 394, 439, 439, 439, 394, 424};
int digital_clock4_maxX = 310;
int digital_clock4_maxY = 440;

int digital_clock5_h = 9;
int digital_clock5_m = 41;
int digital_clock5_location_x = 320;
int digital_clock5_location_y = 443;
int digital_clock5_size = 50;
int digital_clock5_bitmask[] = {119, 48, 93, 121, 58, 107, 111, 49, 127, 59};
int digital_clock5_triangleX[] = {83, 101, 108, 101, 108, 277, 101, 108, 277, 257, 277, 108, 257, 277, 286, 76, 60, 98, 60, 98, 80, 80, 39, 60, 80, 39, 55, 31, 55, 73, 31, 73, 52, 31, 9, 52, 9, 52, 20, 61, 86, 80, 86, 80, 233, 233, 227, 80, 233, 227, 252, 260, 292, 305, 305, 260, 240, 305, 281, 240, 240, 281, 260, 259, 234, 276, 234, 276, 256, 256, 214, 234, 214, 256, 237, 38, 27, 60, 38, 60, 207, 207, 38, 212, 212, 207, 230};
int digital_clock5_triangleY[] = {30, 13, 60, 13, 60, 14, 13, 60, 14, 57, 14, 60, 57, 14, 29, 36, 47, 61, 47, 61, 198, 198, 201, 47, 198, 201, 219, 252, 232, 253, 252, 253, 390, 252, 406, 390, 406, 390, 416, 227, 202, 249, 202, 249, 203, 203, 247, 249, 203, 247, 224, 60, 35, 49, 49, 60, 200, 50, 201, 200, 200, 201, 220, 231, 252, 252, 252, 252, 403, 403, 390, 252, 390, 403, 415, 439, 424, 392, 439, 392, 394, 394, 439, 439, 439, 394, 424};
int digital_clock5_maxX = 310;
int digital_clock5_maxY = 440;

int digital_clock6_h = 9;
int digital_clock6_m = 41;
int digital_clock6_location_x = 320;
int digital_clock6_location_y = 528;
int digital_clock6_size = 50;
int digital_clock6_bitmask[] = {119, 48, 93, 121, 58, 107, 111, 49, 127, 59};
int digital_clock6_triangleX[] = {83, 101, 108, 101, 108, 277, 101, 108, 277, 257, 277, 108, 257, 277, 286, 76, 60, 98, 60, 98, 80, 80, 39, 60, 80, 39, 55, 31, 55, 73, 31, 73, 52, 31, 9, 52, 9, 52, 20, 61, 86, 80, 86, 80, 233, 233, 227, 80, 233, 227, 252, 260, 292, 305, 305, 260, 240, 305, 281, 240, 240, 281, 260, 259, 234, 276, 234, 276, 256, 256, 214, 234, 214, 256, 237, 38, 27, 60, 38, 60, 207, 207, 38, 212, 212, 207, 230};
int digital_clock6_triangleY[] = {30, 13, 60, 13, 60, 14, 13, 60, 14, 57, 14, 60, 57, 14, 29, 36, 47, 61, 47, 61, 198, 198, 201, 47, 198, 201, 219, 252, 232, 253, 252, 253, 390, 252, 406, 390, 406, 390, 416, 227, 202, 249, 202, 249, 203, 203, 247, 249, 203, 247, 224, 60, 35, 49, 49, 60, 200, 50, 201, 200, 200, 201, 220, 231, 252, 252, 252, 252, 403, 403, 390, 252, 390, 403, 415, 439, 424, 392, 439, 392, 394, 394, 439, 439, 439, 394, 424};
int digital_clock6_maxX = 310;
int digital_clock6_maxY = 440;

String text6_content = "Shanghai";
int text6_cursor_x = 42;
int text6_cursor_y = 570;
const GFXfont *text6_font = &FreeSans24pt7b;

String text7_content = "14F";
int text7_cursor_x = 580;
int text7_cursor_y = 145;
const GFXfont *text7_font = &FreeSans18pt7b;

String text8_content = "14F";
int text8_cursor_x = 580;
int text8_cursor_y = 230;
const GFXfont *text8_font = &FreeSans18pt7b;

String text9_content = "36F";
int text9_cursor_x = 580;
int text9_cursor_y = 315;
const GFXfont *text9_font = &FreeSans18pt7b;

String text10_content = "43F";
int text10_cursor_x = 580;
int text10_cursor_y = 400;
const GFXfont *text10_font = &FreeSans18pt7b;

String text11_content = "110F";
int text11_cursor_x = 580;
int text11_cursor_y = 485;
const GFXfont *text11_font = &FreeSans18pt7b;

String text12_content = "35F";
int text12_cursor_x = 580;
int text12_cursor_y = 570;
const GFXfont *text12_font = &FreeSans18pt7b;

int line0_start_x = 1;
int line0_start_y = 80;
int line0_end_x = 800;
int line0_end_y = 80;
int line0_color = 0;
int line0_thickness = 10;
int line0_gradient = 0;

String text13_content = "All Across the Magic";
int text13_cursor_x = 129;
int text13_cursor_y = 57;
const GFXfont *text13_font = &FreeSansBold24pt7b;

int line1_start_x = 0;
int line1_start_y = 165;
int line1_end_x = 800;
int line1_end_y = 165;
int line1_color = 6;
int line1_thickness = 5;
int line1_gradient = 0;

int line2_start_x = 0;
int line2_start_y = 250;
int line2_end_x = 800;
int line2_end_y = 250;
int line2_color = 6;
int line2_thickness = 5;
int line2_gradient = 0;

int line3_start_x = 0;
int line3_start_y = 335;
int line3_end_x = 800;
int line3_end_y = 335;
int line3_color = 6;
int line3_thickness = 5;
int line3_gradient = 0;

int line4_start_x = 0;
int line4_start_y = 420;
int line4_end_x = 800;
int line4_end_y = 420;
int line4_color = 6;
int line4_thickness = 5;
int line4_gradient = 0;

int line5_start_x = 0;
int line5_start_y = 505;
int line5_end_x = 800;
int line5_end_y = 505;
int line5_color = 6;
int line5_thickness = 5;
int line5_gradient = 0;

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

    display.setFont(text7_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text7_cursor_x, text7_cursor_y);
    display.print(text7_content);

    display.setFont(text8_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text8_cursor_x, text8_cursor_y);
    display.print(text8_content);

    display.setFont(text9_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text9_cursor_x, text9_cursor_y);
    display.print(text9_content);

    display.setFont(text10_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text10_cursor_x, text10_cursor_y);
    display.print(text10_content);

    display.setFont(text11_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text11_cursor_x, text11_cursor_y);
    display.print(text11_content);

    display.setFont(text12_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text12_cursor_x, text12_cursor_y);
    display.print(text12_content);

   if (line0_gradient <= line0_color && line0_thickness == 1)
       display.drawLine(line0_start_x, line0_start_y, line0_end_x, line0_end_y, line0_color);
   else if (line0_gradient <= line0_color && line0_thickness != 1)
       display.drawThickLine(line0_start_x, line0_start_y, line0_end_x, line0_end_y, line0_color, line0_thickness);
   else if (line0_gradient > line0_color && line0_thickness == 1)
       display.drawGradientLine(line0_start_x, line0_start_y, line0_end_x, line0_end_y, line0_color, line0_gradient, 1);
   else if (line0_gradient > line0_color && line0_thickness != 1)
       display.drawGradientLine(line0_start_x, line0_start_y, line0_end_x, line0_end_y, line0_color, line0_gradient, line0_thickness);

    display.setFont(text13_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text13_cursor_x, text13_cursor_y);
    display.print(text13_content);

   if (line1_gradient <= line1_color && line1_thickness == 1)
       display.drawLine(line1_start_x, line1_start_y, line1_end_x, line1_end_y, line1_color);
   else if (line1_gradient <= line1_color && line1_thickness != 1)
       display.drawThickLine(line1_start_x, line1_start_y, line1_end_x, line1_end_y, line1_color, line1_thickness);
   else if (line1_gradient > line1_color && line1_thickness == 1)
       display.drawGradientLine(line1_start_x, line1_start_y, line1_end_x, line1_end_y, line1_color, line1_gradient, 1);
   else if (line1_gradient > line1_color && line1_thickness != 1)
       display.drawGradientLine(line1_start_x, line1_start_y, line1_end_x, line1_end_y, line1_color, line1_gradient, line1_thickness);

   if (line2_gradient <= line2_color && line2_thickness == 1)
       display.drawLine(line2_start_x, line2_start_y, line2_end_x, line2_end_y, line2_color);
   else if (line2_gradient <= line2_color && line2_thickness != 1)
       display.drawThickLine(line2_start_x, line2_start_y, line2_end_x, line2_end_y, line2_color, line2_thickness);
   else if (line2_gradient > line2_color && line2_thickness == 1)
       display.drawGradientLine(line2_start_x, line2_start_y, line2_end_x, line2_end_y, line2_color, line2_gradient, 1);
   else if (line2_gradient > line2_color && line2_thickness != 1)
       display.drawGradientLine(line2_start_x, line2_start_y, line2_end_x, line2_end_y, line2_color, line2_gradient, line2_thickness);

   if (line3_gradient <= line3_color && line3_thickness == 1)
       display.drawLine(line3_start_x, line3_start_y, line3_end_x, line3_end_y, line3_color);
   else if (line3_gradient <= line3_color && line3_thickness != 1)
       display.drawThickLine(line3_start_x, line3_start_y, line3_end_x, line3_end_y, line3_color, line3_thickness);
   else if (line3_gradient > line3_color && line3_thickness == 1)
       display.drawGradientLine(line3_start_x, line3_start_y, line3_end_x, line3_end_y, line3_color, line3_gradient, 1);
   else if (line3_gradient > line3_color && line3_thickness != 1)
       display.drawGradientLine(line3_start_x, line3_start_y, line3_end_x, line3_end_y, line3_color, line3_gradient, line3_thickness);

   if (line4_gradient <= line4_color && line4_thickness == 1)
       display.drawLine(line4_start_x, line4_start_y, line4_end_x, line4_end_y, line4_color);
   else if (line4_gradient <= line4_color && line4_thickness != 1)
       display.drawThickLine(line4_start_x, line4_start_y, line4_end_x, line4_end_y, line4_color, line4_thickness);
   else if (line4_gradient > line4_color && line4_thickness == 1)
       display.drawGradientLine(line4_start_x, line4_start_y, line4_end_x, line4_end_y, line4_color, line4_gradient, 1);
   else if (line4_gradient > line4_color && line4_thickness != 1)
       display.drawGradientLine(line4_start_x, line4_start_y, line4_end_x, line4_end_y, line4_color, line4_gradient, line4_thickness);

   if (line5_gradient <= line5_color && line5_thickness == 1)
       display.drawLine(line5_start_x, line5_start_y, line5_end_x, line5_end_y, line5_color);
   else if (line5_gradient <= line5_color && line5_thickness != 1)
       display.drawThickLine(line5_start_x, line5_start_y, line5_end_x, line5_end_y, line5_color, line5_thickness);
   else if (line5_gradient > line5_color && line5_thickness == 1)
       display.drawGradientLine(line5_start_x, line5_start_y, line5_end_x, line5_end_y, line5_color, line5_gradient, 1);
   else if (line5_gradient > line5_color && line5_thickness != 1)
       display.drawGradientLine(line5_start_x, line5_start_y, line5_end_x, line5_end_y, line5_color, line5_gradient, line5_thickness);

}
}