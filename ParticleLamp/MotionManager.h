///////////////////////////////////////////////////////////////////
// Class reading  and processing the motion and orientation of 
// the device
//
// This code is under A Creative Commons Attribution/Share-Alike License
// http://creativecommons.org/licenses/by-sa/4.0/
// 2018, Imanol Gomez
///////////////////////////////////////////////////////////////////

#pragma once
#include "Arduino.h"
#include "Constants.h"

#include <NXPMotionSense.h>
#include <Wire.h>
#include <EEPROM.h>


class MotionManager{

  public:
    
    MotionManager();
    
    void setup();
    void update();

    float ax, ay, az;
   
  private:

    void readMotion();

    NXPMotionSense imu;
    NXPSensorFusion filter;
    
    //float ax, ay, az;
    float gx, gy, gz;
    float mx, my, mz;
    float roll, pitch, heading;

};

MotionManager::MotionManager()
{
   //Intentionally left empty
}

void MotionManager::setup()
{
    imu.begin();
    filter.begin(100);

    Serial.print("MotionManager::setup");
}

void MotionManager::update()
{
    readMotion();
}


void MotionManager::readMotion()
{
    if (imu.available()) {
    // Read the motion sensors
    imu.readMotionSensor(ax, ay, az, gx, gy, gz, mx, my, mz);

    // Update the SensorFusion filter
    filter.update(gx, gy, gz, ax, ay, az, mx, my, mz);

    // print the heading, pitch and roll
    roll = filter.getRoll();
    pitch = filter.getPitch();
    heading = filter.getYaw();
//    Serial.print("Orientation: ");
//    Serial.print(heading);
//    Serial.print(" ");
//    Serial.print(pitch);
//    Serial.print(" ");
//    Serial.println(roll);
  }

   // Serial.print("MotionManager::toggleOnOff -> ");  Serial.println(lightOn);
}
