#include <Arduino.h>
#include "PID_v1.h"
#include "Display.hpp"
#include "TempSense.hpp"
#include "../lib/pid/PIDtherms.h"


//relay needs one control pin, this was soldered on via the shield
#define RELAY_PIN 10

Display tempDisp;
ThermistorArray tempTherms;

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp=2, Ki=5, Kd=1;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

int WindowSize = 5000;
unsigned long windowStartTime;



void setup() {
  windowStartTime = millis();

  //init display and termperature sensing
  tempDisp = Display();
  tempTherms = ThermistorArray();

  //pid has goal of 37.0
  Setpoint = 37.0;

  //tell the PID to range between 0 and the full window size
  myPID.SetOutputLimits(0, WindowSize);
  myPID.SetMode(AUTOMATIC);


  Serial.begin(9600);
}

void loop() {
  tempTherms.refresh();
  delay(1000);

  tempDisp.refresh(tempTherms.getCurrTemp(), tempTherms.getAvgTemp(), tempTherms.getMaxTemp(), tempTherms.getMinTemp());
  Input = tempTherms.getCurrTemp();
  myPID.Compute();

  /************************************************
   * turn the output pin on/off based on pid output
   ************************************************/
  if (millis() - windowStartTime > WindowSize)
  { //time to shift the Relay Window
    windowStartTime += WindowSize;
  }
  if (Output < millis() - windowStartTime) digitalWrite(RELAY_PIN, HIGH);
  else digitalWrite(RELAY_PIN, LOW);
}