#ifndef TEMPSENSE_H
#define TEMPSENSE_H

#include <Arduino.h>

using namespace std;

//need 6 analog pins, one for each thermistor
#define TR0 A0
#define TR1 A1
#define TR2 A2
#define TR3 A3
#define TR4 A4
#define TR5 A5

#define NRES 10000//this is nominal res of thermistor aka 10kohm
#define BETA 3950//some coefficient of thermistor
#define SRES 10000//value of series resistor aka 10kohm

#define N 6

class ThermistorArray{
    public:
        ThermistorArray();
        void refresh();
        float getCurrTemp();
        float getMinTemp();
        float getMaxTemp();
        float getAvgTemp();

    private:
        float convertReading(float reading);
        float currTemp;
        float minTemp;
        float maxTemp;
        float totalTemp;
        long numSamples;
    
};

#endif