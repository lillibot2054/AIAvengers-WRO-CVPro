// Kindly Check whether the Library Files are installed in Library Manager.

#include <Wire.h>
#include <Adafruit_TCS34725.h>

///////////////////color sensor///////////////////

#define TCS3414CS_ADDRESS 0x29 //ColorSensor address 0x29

// Initializing ColorSensor
Adafruit_TCS34725 tcs1 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_4X); // Front Color Sensor

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);       // Set ADC resolution to 12 bits (0-4095)
  analogSetAttenuation(ADC_0db);  // Set attenuation to 0dB (for full-scale voltage range)
}

void loop() {
  front_colour_sensor();
}

//ColorSensor Function
void front_colour_sensor() {
  uint16_t r, g, b, c;
  tcs1.getRawData(&r, &g, &b, &c);
  uint16_t colorTemp = tcs1.calculateColorTemperature(r, g, b);
  Serial.println("CS-1 Color Temp: "+ String(colorTemp));
  //uint16_t lux = tcs1.calculateLux(r, g, b);
  //Serial.println("CS-1 : Red: "+ String(r)+", Green: "+String(g)+", Blue: "+String(b) +", Clear: "+String(c) +", Color Temp: "+ String(colorTemp));
}
