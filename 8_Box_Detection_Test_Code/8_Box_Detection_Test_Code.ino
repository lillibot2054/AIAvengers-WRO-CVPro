#include <FastLED.h>

#define LED_PIN 15
#define NUM_LEDS 1

CRGB leds[NUM_LEDS];

char ab;
int serial_count;
const int bufferSize = 1;  
char abd[bufferSize];  
int abdRead;
char red_value = '1';
char green_value = '2';

void setup() {
  Serial.begin(115200);

  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.show(); 
  delay(10);
}


void rgb_led(int r, int g, int b)
{
  leds[0] = CRGB(r, g, b);
  FastLED.show();
}

void box_detection()
{
    if(Serial.available() > 0)
    { 
      ab = Serial.read();
    }
    else
    {
      ab = 'n';
      buffer_limit();  //[*]
    }

    if(ab == '1') // Red Box
    {
      rgb_led(255, 0, 0);
      delay(1000);
      rgb_led(0, 0, 0); 

      buffer_limit(); //[*]
    } 

    if(ab == '2') // Green Box
    {
      rgb_led(0, 255, 0); 
      delay(1000);
      rgb_led(0, 0, 0); 

      buffer_limit(); //[*]
    }
            
}

void buffer_limit()
{
  while(Serial.available() > 0)
  {
    abdRead = Serial.readBytesUntil(red_value, abd, bufferSize);
    abdRead = Serial.readBytesUntil(green_value, abd, bufferSize);
    
    abd[abdRead] = '\0';
  }

}

void loop() 
{
  box_detection();
}