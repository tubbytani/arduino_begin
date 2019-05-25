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
  pinMode(7,INPUT);
  Serial.begin(9600);
}
void loop()
{display.clearDisplay();
 display.setTextColor(WHITE);
display.setCursor(0,0);
 display.print("IRSensorip ");
display.println(digitalRead(7));
if(digitalRead(7)==0)
  {
  display.print("blocked");
  }
 else{
  
    display.print("transmitted");
    }

display.display();
}
