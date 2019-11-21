#include "Display.hpp"


Display::Display(){

    lcd.begin(16,2);               // initialize the lcd with 16x2 chars
    lcd.home();                   // move cursor to top left of lcd

    lcd.print("Now00.0CMax00.0C");
    lcd.setCursor ( 0, 1 );        // go to the next line
    lcd.print("Avg00.0CMin00.0C");
}

void Display::refresh(float current, float avg, float max, float min){
    lcd.home();

    lcd.print("Now");
    lcd.setCursor(3,0);
    lcd.print(current, 3);
    lcd.setCursor(7,0);
    lcd.print("C");

    lcd.setCursor(8,0);
    lcd.print("Max");
    lcd.setCursor(11,0);
    lcd.print(max, 3);
    lcd.setCursor(15,0);
    lcd.print("C");

    lcd.setCursor(0,1);

    lcd.print("Avg");
    lcd.setCursor(3,1);
    lcd.print(avg, 3);
    lcd.setCursor(7,1);
    lcd.print("C");

    lcd.setCursor(8,1);
    lcd.print("Min");
    lcd.setCursor(11,1);
    lcd.print(min, 3);
    lcd.setCursor(15,1);
    lcd.print("C");

    lcd.home();

}