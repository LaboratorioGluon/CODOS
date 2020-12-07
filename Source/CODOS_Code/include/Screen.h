#ifndef __SCREEN_H__
#define __SCREEN_H__
#include <Adafruit_SSD1306.h>

extern Adafruit_SSD1306 display;

void InitScreen();

/**
 * Draw and animate the start up logo
 **/
void drawLogo();


/**
 * Draw the information page: CO2 level and scale
 * It only redraws the screen if the pValue has changed.
 * 
 * #
**/
void drawInfo(uint16_t pValue);

#endif // __SCREEN_H__