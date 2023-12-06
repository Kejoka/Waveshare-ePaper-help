#include <Arduino.h>
#include "GxEPD2_BW.h"                          // 3 colour screen

#define RST_PIN 16
#define DC_PIN 17
#define CS_PIN 5
#define BUSY_PIN 4

// you are using GxEPD2_270, im pretty sure waveshare is this one GxEPD2_270_T91 with SSD1608 driver
GxEPD2_BW<GxEPD2_270_T91, GxEPD2_270_T91::HEIGHT> display(GxEPD2_270_T91(CS_PIN, DC_PIN, RST_PIN, BUSY_PIN));

#define MOSI 33
#define CLK 18

void setup() {
  Serial.println("Setup Start");

  // comment this out if it doesn't work. This may help or it may not.
  hspi.begin(CLK, -1, MOSI, -1); 
  display.epd2.selectSPI(hspi, SPISettings(4000000, MSBFIRST, SPI_MODE0));
  // end
  
  
  display.init(); 
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
  // center bounding box by transposition of origin:
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  uint16_t y = ((display.height() - tbh) / 2) - tby;
  display.setFullWindow();
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.print(HelloWorld);
  }
  while (display.nextPage());
  Serial.println("Set up Done");
}

void loop() {
  // Your loop code
}
