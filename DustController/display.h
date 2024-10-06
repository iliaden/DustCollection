#ifndef custom_display
#define custom_display

#include <MCP40xx.h>
#include <LiquidCrystal.h>
#include "constants.h"

class Display {

public:
  Display(){
    // brightness ;
    // lcd = 
  }

  void setup();
  void brighter();
  void darker();
  void disable();
  void enable();
  void showText(const char* line1, const char* line2);


private:
  MCP40xx brightness = MCP40xx(lcd_brightness_cs, lcd_brightness_ud);
  LiquidCrystal lcd = LiquidCrystal(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

};
#endif
;