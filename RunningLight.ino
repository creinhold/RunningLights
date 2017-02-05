
#include <Adafruit_DotStar.h>
#include <SPI.h> 
#define NUMPIXELS 60 // Number of LEDs in strip

// Here's how to control the LEDs from any two pins:
#define DATAPIN    9
#define CLOCKPIN   8
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);


void setup() {



  strip.begin(); // Initialize pins for output
  strip.setBrightness(25);
  strip.show();  // Turn all LEDs off ASAP
}

// This requires about 200 mA for all the 'on' pixels + 1 mA per 'off' pixel.

int numLED = 30;
int totalLED = 60;
int redLevel = 255;
int greenLevel = 40;
int blueLevel = 0; 


void loop() {

  for(int x = 0; x <= numLED; x++)
  {
      strip.setPixelColor(totalLED -1 - x, greenLevel, redLevel, blueLevel);
      strip.setPixelColor(x, greenLevel, redLevel, blueLevel);
      strip.show();                    
      delay(30);
  }
  for(int x = 0; x <= numLED; x++)
  {
      strip.setPixelColor(totalLED -1 - x, 0, 0, 0);
      strip.setPixelColor(x, 0, 0, 0);
      strip.show();                     
      delay(30);                        
  }

}
