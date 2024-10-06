#ifndef displayimpl
#define displayimpl

#include "display.h"
#include <MCP40xx.h>
#include <LiquidCrystal.h>


void Display::setup() {
  
  brightness.setup();
  brightness.begin();
  brightness.zeroWiper();
  lcd.begin(16, 2);
  
}

void Display::brighter() {
  brightness.inc();
}
void Display::darker() {
  brightness.dec();
}

void Display::disable() {
  lcd.noDisplay();
}

void Display::enable(){
  lcd.display();
}

void Display::showText(const char* line1, const char* line2){
  lcd.autoscroll();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}

#endif

