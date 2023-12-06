#include <Arduino.h>
#include "GxEPD2_GFX.h"
#include "GxEPD2_BW.h"                          // 3 colour screen
#include "GxEPD2_display_selection_new_style.h" // For selecting screen
#include <Fonts/FreeMonoBold9pt7b.h>

const uint SCREEN_WIDTH = 176;
const uint SCREEN_HEIGHT = 264;

void setup() {
  // Your setup code
  initialiseDisplay();
  displayInformation();
}

void loop() {
  // Your loop code
}

void initialiseDisplay() {
    display.init(115200, true, 2, false); // USE THIS for Waveshare boards with "clever" reset circuit, 2ms reset pulse
    display.setRotation(0);
    display.setTextSize(0);
    display.setFont(&FreeMonoBold9pt7b);
    display.setTextColor(GxEPD_BLACK);
    display.setFullWindow();
    display.firstPage();
    display.hibernate();
    delay(1000);
}

void displayInformation(void)
{
    display.setFullWindow();
    display.firstPage();
//    do {
        display.fillScreen(GxEPD_WHITE);

        // draw box lines
        // top
        display.drawLine(0, 0, 145, 0, GxEPD_BLACK);
        display.drawLine(147, 0, 276, 0, GxEPD_BLACK);
        display.drawLine(278, 0, 399, 0, GxEPD_BLACK);

        // right
        display.drawLine(399, 0, 399, 150, GxEPD_BLACK);
        display.drawLine(399, 152, 399, 180, GxEPD_BLACK);
        display.drawLine(399, 182, 399, 299, GxEPD_BLACK);

        // bottom
        display.drawLine(0, 299, 262, 299, GxEPD_BLACK);
        display.drawLine(264, 299, 399, 299, GxEPD_BLACK);

        // left
        display.drawLine(0, 0, 0, 150, GxEPD_BLACK);
        display.drawLine(0, 152, 0, 180, GxEPD_BLACK);
        display.drawLine(0, 182, 0, 299, GxEPD_BLACK);

        // lines between temp/icon/wind
        display.drawLine(145, 0, 145, 109, GxEPD_BLACK);
        display.drawLine(147, 0, 147, 109, GxEPD_BLACK);
        display.drawLine(276, 0, 276, 109, GxEPD_BLACK);
        display.drawLine(278, 0, 278, 109, GxEPD_BLACK);

        // line after the two graphs
        display.drawLine(262, 182, 262, 299, GxEPD_BLACK);
        display.drawLine(264, 182, 264, 299, GxEPD_BLACK);

        // top middle lines
        display.drawLine(0, 110, 145, 110, GxEPD_BLACK); //x=125
        display.drawLine(147, 110, 399, 110, GxEPD_BLACK); //x=125
        display.drawLine(0, 112, 119, 112, GxEPD_BLACK); //x=125
        display.drawLine(121, 112, 399, 112, GxEPD_BLACK); //x=125

        // lines between sun and forecasts
        display.drawLine(119, 112, 119, 180, GxEPD_BLACK);
        display.drawLine(121, 112, 121, 180, GxEPD_BLACK);
        
        // bottom middle lines
        display.drawLine(0, 180, 119, 180, GxEPD_BLACK);  // x=125
        display.drawLine(121, 180, 399, 180, GxEPD_BLACK);  // x=125


        display.drawLine(0, 182, 262, 182, GxEPD_BLACK);  // x=125
        display.drawLine(264, 182, 399, 182, GxEPD_BLACK);  // x=125                         // Forecast

//    } while (display.nextPage());
    display.display(false);  // works instead of do:while loop
    delay(500);
    
    display.hibernate();
}
