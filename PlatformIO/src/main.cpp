#include <Arduino.h>
#include "PID_v1.h"
#include "Display.hpp"
#include "TempSense.hpp"

//relay needs one control pin, this was soldered on via the shield
#define RELAY 10

Display tempDisp;
ThermistorArray tempTherms;


void setup() {
  // put your setup code here, to run once:
  tempDisp = Display();
  tempTherms = ThermistorArray();
  Serial.begin(9600);
}

void loop() {
  tempTherms.refresh();
  

  tempDisp.refresh(tempTherms.getCurrTemp(), tempTherms.getAvgTemp(), tempTherms.getMaxTemp(), tempTherms.getMinTemp());
}