#ifndef __LEDS_H__
#define __LEDS_H__

#define R_PIN PD3
#define G_PIN PD5
#define B_PIN PD6


void InitLeds();
void writeRGB(uint8_t r, uint8_t g, uint8_t b);
void updateLeds(int pValue);

#endif //__LEDS_H__