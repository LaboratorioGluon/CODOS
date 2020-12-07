#include <Arduino.h>
#include "LEDs.h"

void InitLeds(){
    
  analogWrite(R_PIN,255);
  analogWrite(G_PIN,255);
  analogWrite(B_PIN,255);

}

void writeRGB(uint8_t r, uint8_t g, uint8_t b){
    analogWrite(R_PIN, 255-r);
    analogWrite(G_PIN, 255-g);
    analogWrite(B_PIN, 255-b);
}



void updateLeds(int pValue){
    static int lastRange = 0;
    static int16_t delta = 0;
    static int8_t direction = 1;
    static unsigned long lastMillis = millis();

    float fDelta = (float)(millis()-lastMillis);

    delta += direction * (int16_t)(fDelta/10.0f);
    if(delta >= 100){
        delta = 100;
        direction = -1;
    }
    if(delta <= 00){
        delta = 0;
        direction = 1;
    }
    

    int range = -1;

    if( pValue < 600){
        writeRGB(0,0,255-delta);
        range = 1;
    }else if(pValue < 800){
        writeRGB(0,255-delta,0);
        range = 2;
    }else if(pValue < 1000){
        writeRGB(150-delta,110-delta,0);
        range = 3;
    }else{
        writeRGB(255-delta,0,0);
        range = 4;
    }

    if( lastRange != range ){
        
    }



    lastMillis = millis();
    lastRange = range;

}
