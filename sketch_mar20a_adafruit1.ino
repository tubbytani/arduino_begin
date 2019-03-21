#include <Wire.h> 
#include <Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#include<SPI.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void setup(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  Serial.begin(9600);
}
void loop(){
  if (Serial.available()) {
    delay(100);
    display.clearDisplay();
    while (Serial.available() > 0) {
      display.write(Serial.read());
    }
  }
}
