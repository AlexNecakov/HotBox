#ifndef DISPLAY_h
#define DISPLAY_h

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>

using namespace std;

const int RS_PIN = 12;
const int EN_PIN = 11;
const int D4 = 5;
const int D5 = 6;
const int D6 = 0;
const int D7 = 1;

class Display{
    public:
        Display();
        void refresh(float current, float avg, float max, float min);

    private:
        LiquidCrystal lcd = LiquidCrystal(RS_PIN, EN_PIN, D4, D5, D6, D7);
};

#endif