#include <Arduino.h>
#include <Adafruit_I2CDevice.h>
#include <MHZ19.h>
#include <SPI.h>

#include <Screen.h>
#include "LEDs.h"

#undef TEST_RUN

#define CO2_MEASURE_PERIOD_MS 1000

MHZ19 co2;
int last_co2_value = 0;

void setup() {

  InitLeds();

  Serial.begin(9600);
  co2.begin(Serial);
  co2.autoCalibration(true);

  InitScreen();

}


void loopColor(uint32_t pin){

  for(int i = 255; i >= 0; i--){
    analogWrite(pin,i);
    delay(5);
  }  

  for(int i = 0; i < 255; i++){
    analogWrite(pin,i);
    delay(5);
  }  
}

void loop() {
#ifdef TEST_RUN
  updateLeds(100);
  drawInfo(100);
  delay(1000);

  updateLeds(600);
  drawInfo(600);
  delay(1000);

  updateLeds(800);
  drawInfo(800);
  delay(1000);

  updateLeds(1000);
  drawInfo(1000);
  delay(1000);

  updateLeds(1500);
  drawInfo(1500);
  delay(1000);

  /*updateLeds(100);
  delay(100);*/

/*
  writeRGB(240,0,0);
  drawInfo(240);
  delay(1000);

  writeRGB(230,0,0);
    drawInfo(230);
  delay(1000);
*/
#else
  static unsigned long lastCo2Measure = millis();

  if( millis() - lastCo2Measure > CO2_MEASURE_PERIOD_MS){
    last_co2_value = co2.getCO2();
    drawInfo(last_co2_value);
    lastCo2Measure = millis();
  }

  updateLeds(last_co2_value);
  delay(50);
#endif
}
