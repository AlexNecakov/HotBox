#include "TempSense.hpp"

ThermistorArray::ThermistorArray(){
  numSamples = 0;
  totalTemp = 0;
}

float ThermistorArray::convertReading(float reading){
  float converted;
  converted = (1023 / reading)  - 1;     // (1023/ADC - 1) 
  converted = SRES / converted;  // 10K / (1023/ADC - 1)
  return converted;
}

void ThermistorArray::refresh(){
  float reading0;
  float reading1;
  float reading2;
  float reading3;
  float reading4;
  float reading5;
 
  reading0 = analogRead(TR0);
  reading1 = analogRead(TR1);
  reading2 = analogRead(TR2);
  reading3 = analogRead(TR3);
  reading4 = analogRead(TR4);
  reading5 = analogRead(TR5);
 
  // convert the value to resistance
  
  float temp0 = convertReading(reading0);
  float temp1 = convertReading(reading1);
  float temp2 = convertReading(reading2);
  float temp3 = convertReading(reading3);
  float temp4 = convertReading(reading4);
  float temp5 = convertReading(reading5);

  currTemp = float((temp0+temp1+temp2+temp3+temp4+temp5)/N);
  currTemp = temp0;

  if (currTemp < minTemp){
    minTemp = currTemp;
  }

  if(currTemp > maxTemp){
    maxTemp = currTemp;
  }

  totalTemp += currTemp;
  numSamples++;
}




float ThermistorArray::getCurrTemp(){
  return currTemp;
}
float ThermistorArray::getAvgTemp(){//to fix later
  return float(totalTemp/numSamples);
}
float ThermistorArray::getMaxTemp(){
  return maxTemp;
}
float ThermistorArray::getMinTemp(){
  return minTemp;
}