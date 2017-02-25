// Code modified for Loveland Robotics test
// By Chris Reinhold
// Version 1.0
// This used to drive cool lights for the robot
// Cannot be used for competition robot

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
int redLevel = 0;
int greenLevel = 255;
int blueLevel = 255;
int lightDelay = 100;
int barLength = 5; 


void loop() {
  for (int len = 0; len < barLength; len++)
  {
    for(int x = 0; x <= totalLED; x++)
    {
        if ( (x + len) % barLength != 0)
        {
        strip.setPixelColor(x, greenLevel, redLevel, blueLevel);
  
        }
        else
        {
          strip.setPixelColor(x,0);
        }
  
    }
    strip.show();  
  
    delay (lightDelay);
  }

}
