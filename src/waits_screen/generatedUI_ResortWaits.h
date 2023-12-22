#include "Arduino.h"
#include "Inkplate.h"
#include "Fonts/FreeSansBold24pt7b.h"
#include "Fonts/FreeSans18pt7b.h"
#include "Fonts/FreeSans9pt7b.h"

extern Inkplate display;

namespace ResortWaitsScreen {
String text0_content = "Walt Disney World Resort";
int text0_cursor_x = 36;
int text0_cursor_y = 75;
const GFXfont *text0_font = &FreeSansBold24pt7b;

int line0_start_x = 0;
int line0_start_y = 115;
int line0_end_x = 800;
int line0_end_y = 115;
int line0_color = 0;
int line0_thickness = 10;
int line0_gradient = 0;

String text1_content = "Space Mountain";
int text1_cursor_x = 26;
int text1_cursor_y = 180;
const GFXfont *text1_font = &FreeSans18pt7b;

int line1_start_x = 0;
int line1_start_y = 200;
int line1_end_x = 800;
int line1_end_y = 200;
int line1_color = 3;
int line1_thickness = 5;
int line1_gradient = 0;

String text2_content = "50 minutes";
int text2_cursor_x = 643;
int text2_cursor_y = 175;
const GFXfont *text2_font = &FreeSans9pt7b;

int line2_start_x = 0;
int line2_start_y = 280;
int line2_end_x = 800;
int line2_end_y = 280;
int line2_color = 3;
int line2_thickness = 5;
int line2_gradient = 0;

String text3_content = "Star Wars: Rise of the Resistance";
int text3_cursor_x = 24;
int text3_cursor_y = 260;
const GFXfont *text3_font = &FreeSans18pt7b;

String text4_content = "120 minutes";
int text4_cursor_x = 643;
int text4_cursor_y = 255;
const GFXfont *text4_font = &FreeSans9pt7b;

String text5_content = "Minnie and Mickey's Runaway Railway";
int text5_cursor_x = 24;
int text5_cursor_y = 340;
const GFXfont *text5_font = &FreeSans18pt7b;

String text6_content = "120 minutes";
int text6_cursor_x = 643;
int text6_cursor_y = 335;
const GFXfont *text6_font = &FreeSans9pt7b;

String text7_content = "Remy's Ratatouille Adventure";
int text7_cursor_x = 24;
int text7_cursor_y = 420;
const GFXfont *text7_font = &FreeSans18pt7b;

String text8_content = "120 minutes";
int text8_cursor_x = 643;
int text8_cursor_y = 415;
const GFXfont *text8_font = &FreeSans9pt7b;

String text9_content = "Tiana's Bayou Adventure";
int text9_cursor_x = 24;
int text9_cursor_y = 500;
const GFXfont *text9_font = &FreeSans18pt7b;

int line3_start_x = 0;
int line3_start_y = 360;
int line3_end_x = 800;
int line3_end_y = 360;
int line3_color = 3;
int line3_thickness = 5;
int line3_gradient = 0;

int line4_start_x = 0;
int line4_start_y = 440;
int line4_end_x = 800;
int line4_end_y = 440;
int line4_color = 3;
int line4_thickness = 5;
int line4_gradient = 0;

int line5_start_x = 0;
int line5_start_y = 520;
int line5_end_x = 800;
int line5_end_y = 520;
int line5_color = 3;
int line5_thickness = 5;
int line5_gradient = 0;

String text10_content = "5 minutes";
int text10_cursor_x = 643;
int text10_cursor_y = 495;
const GFXfont *text10_font = &FreeSans9pt7b;

String text11_content = "Slinky Dog Dash";
int text11_cursor_x = 24;
int text11_cursor_y = 580;
const GFXfont *text11_font = &FreeSans18pt7b;

String text12_content = "15 minutes";
int text12_cursor_x = 643;
int text12_cursor_y = 575;
const GFXfont *text12_font = &FreeSans9pt7b;

void mainDraw() {
    display.setFont(text0_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text0_cursor_x, text0_cursor_y);
    display.print(text0_content);

   if (line0_gradient <= line0_color && line0_thickness == 1)
       display.drawLine(line0_start_x, line0_start_y, line0_end_x, line0_end_y, line0_color);
   else if (line0_gradient <= line0_color && line0_thickness != 1)
       display.drawThickLine(line0_start_x, line0_start_y, line0_end_x, line0_end_y, line0_color, line0_thickness);
   else if (line0_gradient > line0_color && line0_thickness == 1)
       display.drawGradientLine(line0_start_x, line0_start_y, line0_end_x, line0_end_y, line0_color, line0_gradient, 1);
   else if (line0_gradient > line0_color && line0_thickness != 1)
       display.drawGradientLine(line0_start_x, line0_start_y, line0_end_x, line0_end_y, line0_color, line0_gradient, line0_thickness);

    display.setFont(text1_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text1_cursor_x, text1_cursor_y);
    display.print(text1_content);

   if (line1_gradient <= line1_color && line1_thickness == 1)
       display.drawLine(line1_start_x, line1_start_y, line1_end_x, line1_end_y, line1_color);
   else if (line1_gradient <= line1_color && line1_thickness != 1)
       display.drawThickLine(line1_start_x, line1_start_y, line1_end_x, line1_end_y, line1_color, line1_thickness);
   else if (line1_gradient > line1_color && line1_thickness == 1)
       display.drawGradientLine(line1_start_x, line1_start_y, line1_end_x, line1_end_y, line1_color, line1_gradient, 1);
   else if (line1_gradient > line1_color && line1_thickness != 1)
       display.drawGradientLine(line1_start_x, line1_start_y, line1_end_x, line1_end_y, line1_color, line1_gradient, line1_thickness);

    display.setFont(text2_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text2_cursor_x, text2_cursor_y);
    display.print(text2_content);

   if (line2_gradient <= line2_color && line2_thickness == 1)
       display.drawLine(line2_start_x, line2_start_y, line2_end_x, line2_end_y, line2_color);
   else if (line2_gradient <= line2_color && line2_thickness != 1)
       display.drawThickLine(line2_start_x, line2_start_y, line2_end_x, line2_end_y, line2_color, line2_thickness);
   else if (line2_gradient > line2_color && line2_thickness == 1)
       display.drawGradientLine(line2_start_x, line2_start_y, line2_end_x, line2_end_y, line2_color, line2_gradient, 1);
   else if (line2_gradient > line2_color && line2_thickness != 1)
       display.drawGradientLine(line2_start_x, line2_start_y, line2_end_x, line2_end_y, line2_color, line2_gradient, line2_thickness);

    display.setFont(text3_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text3_cursor_x, text3_cursor_y);
    display.print(text3_content);

    display.setFont(text4_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text4_cursor_x, text4_cursor_y);
    display.print(text4_content);

    display.setFont(text5_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text5_cursor_x, text5_cursor_y);
    display.print(text5_content);

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

    display.setFont(text10_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text10_cursor_x, text10_cursor_y);
    display.print(text10_content);

    display.setFont(text11_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text11_cursor_x, text11_cursor_y);
    display.print(text11_content);

    display.setFont(text12_font);
    display.setTextColor(0, 7);    display.setTextSize(1);    display.setCursor(text12_cursor_x, text12_cursor_y);
    display.print(text12_content);

}
}