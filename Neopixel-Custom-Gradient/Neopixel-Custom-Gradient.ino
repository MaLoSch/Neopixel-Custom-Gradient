// Libraries
#include <Adafruit_NeoPixel.h> // include the adafruit neopixel library

// LEDs
#define LED_PIN 23 // pin at which the LED strip is connected
#define LED_COUNT 60 // <<<--- Set the number of LEDs per strip || Currently only working with multiples of 12 (12,24,36,48,60,72,...)
#define BRIGHTNESS 64 // Set BRIGHTNESS (max = 255)
int colorArr[LED_COUNT][3]; // 2D Array to store color values for each pixel
const int colorShift = 1; // <<<--- variable to offset the color
int colorOffset = 0; // variable which determines how much the gradient is offset

// NON-BLOCKING LOOP
unsigned long previousMillis = 0; // store previous millis
unsigned long loopInterval = 100; // set millis interval

// ------------------------------------------------------

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800); // <<<--- RGB || we need to set the color mode to GRB to work in the RGB color space
//Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800); // <<< --- RGBW || we need to set the color mode to GRBW to work in the RGB color space

void setup() {
  Serial.begin(9600); // open up Serial port at BAUD 9600
  strip.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show(); // Turn OFF all pixels ASAP
  strip.setBrightness(BRIGHTNESS); // Set the brightness of all pixels

  //setColorArray(255,0,0); // <<<--- function call for a single color
  setColorArray(255,0,0,0,255,0); // <<<--- function call for 2 color gradient
  //setColorArray(255,0,0,0,255,0,0,0,255); // <<<--- function call for 3 color gradient
  //setColorArray(255,0,0,0,255,0,0,0,255,255,255,0); // <<<--- function call for 4 color gradient
} 

void loop() {
  // main code goes here
  unsigned long currentMillis = millis(); // get the current millis value
  if(currentMillis - previousMillis > loopInterval) { // wait for a certain amount of time (e.g. loopInterval)
    previousMillis = currentMillis; // update previousMillis with currentMillis
    for(int i=0; i<LED_COUNT; i++) { // loop to update all pixels on the LED strip
      strip.setPixelColor((i+colorOffset)%LED_COUNT, strip.Color(colorArr[i][0],colorArr[i][1],colorArr[i][2])); // set the color of each pixel using the values from colorArr
    }
    strip.show(); // update the pixels on the LED strip
    colorOffset = (colorOffset + colorShift) % LED_COUNT; // shifting the colors along the LED strip
  }
}

void setColorArray(int c1r, int c1g, int c1b) {
  for(int i=0; i<LED_COUNT; i++) {
    colorArr[i][0] = c1r;
    colorArr[i][1] = c1g;
    colorArr[i][2] = c1b;
  }
}

void setColorArray(int c1r, int c1g, int c1b, int c2r, int c2g, int c2b) {
  // currently only works for LEDs that are a multiple of 12
  for(int i=0; i<LED_COUNT/2; i++) {
    colorArr[i + ((LED_COUNT/2)*0)][0] = int(map(i, 0, LED_COUNT/2, c1r, c2r));
    colorArr[i + ((LED_COUNT/2)*1)][0] = int(map(i, 0, LED_COUNT/2, c2r, c1r)); 

    colorArr[i + ((LED_COUNT/2)*0)][1] = int(map(i, 0, LED_COUNT/2, c1g, c2g));
    colorArr[i + ((LED_COUNT/2)*1)][1] = int(map(i, 0, LED_COUNT/2, c2g, c1g));

    colorArr[i + ((LED_COUNT/2)*0)][2] = int(map(i, 0, LED_COUNT/2, c1b, c2b));
    colorArr[i + ((LED_COUNT/2)*1)][2] = int(map(i, 0, LED_COUNT/2, c2b, c1b));
  }
}

void setColorArray(int c1r, int c1g, int c1b, int c2r, int c2g, int c2b, int c3r, int c3g, int c3b) {
  // currently only works for LEDs that are a multiple of 12
  for(int i=0; i<LED_COUNT/3; i++) {
    colorArr[i + ((LED_COUNT/3)*0)][0] = int(map(i, 0, LED_COUNT/3, c1r, c2r));
    colorArr[i + ((LED_COUNT/3)*1)][0] = int(map(i, 0, LED_COUNT/3, c2r, c3r));
    colorArr[i + ((LED_COUNT/3)*2)][0] = int(map(i, 0, LED_COUNT/3, c3r, c1r));

    colorArr[i + ((LED_COUNT/3)*0)][1] = int(map(i, 0, LED_COUNT/3, c1g, c2g));
    colorArr[i + ((LED_COUNT/3)*1)][1] = int(map(i, 0, LED_COUNT/3, c2g, c3g));
    colorArr[i + ((LED_COUNT/3)*2)][1] = int(map(i, 0, LED_COUNT/3, c3g, c1g));

    colorArr[i + ((LED_COUNT/3)*0)][2] = int(map(i, 0, LED_COUNT/3, c1b, c2b));
    colorArr[i + ((LED_COUNT/3)*1)][2] = int(map(i, 0, LED_COUNT/3, c2b, c3b));
    colorArr[i + ((LED_COUNT/3)*2)][2] = int(map(i, 0, LED_COUNT/3, c3b, c1b));
  }
}

void setColorArray(int c1r, int c1g, int c1b, int c2r, int c2g, int c2b, int c3r, int c3g, int c3b, int c4r, int c4g, int c4b) {
  // currently only works for LEDs that are a multiple of 12
  for(int i=0; i<LED_COUNT/4; i++) {
    colorArr[i + ((LED_COUNT/4)*0)][0] = int(map(i, 0, LED_COUNT/4, c1r, c2r));
    colorArr[i + ((LED_COUNT/4)*1)][0] = int(map(i, 0, LED_COUNT/4, c2r, c3r));
    colorArr[i + ((LED_COUNT/4)*2)][0] = int(map(i, 0, LED_COUNT/4, c3r, c4r));
    colorArr[i + ((LED_COUNT/4)*3)][0] = int(map(i, 0, LED_COUNT/4, c4r, c1r));

    colorArr[i + ((LED_COUNT/4)*0)][1] = int(map(i, 0, LED_COUNT/4, c1g, c2g));
    colorArr[i + ((LED_COUNT/4)*1)][1] = int(map(i, 0, LED_COUNT/4, c2g, c3g));
    colorArr[i + ((LED_COUNT/4)*2)][1] = int(map(i, 0, LED_COUNT/4, c3g, c4g));
    colorArr[i + ((LED_COUNT/4)*3)][1] = int(map(i, 0, LED_COUNT/4, c4g, c1g));

    colorArr[i + ((LED_COUNT/4)*0)][2] = int(map(i, 0, LED_COUNT/4, c1b, c2b));
    colorArr[i + ((LED_COUNT/4)*1)][2] = int(map(i, 0, LED_COUNT/4, c2b, c3b));
    colorArr[i + ((LED_COUNT/4)*2)][2] = int(map(i, 0, LED_COUNT/4, c3b, c4b));
    colorArr[i + ((LED_COUNT/4)*3)][2] = int(map(i, 0, LED_COUNT/4, c4b, c1b));
  }
}
