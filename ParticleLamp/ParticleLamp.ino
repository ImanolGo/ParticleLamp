/*
  Particle Lamp
   
 Description:
 * Software simulating glowy physics

 Software:
 * NXPMotionSense Library 
 * FastLed Library
 
 Hardware:
* Teensy 3.2
* Digi-Dot Panel 8X8 WS2812B-LEDs
* PJRC Prop Shield With Motion Sensors
   
 created 05 February 2018
 This code is under A Creative Commons Attribution/Share-Alike License http://creativecommons.org/licenses/by-sa/4.0/
   (2018) by Imanol Gomez

 
 */
 

#include "Constants.h"
#include "MotionManager.h"
#include "LedsManager.h"
#include "ParticlesManager.h"


uint32_t  prevTime   = 0;      // Used for frames-per-second throttle

MotionManager motionManager;
ParticlesManager particlesManager;
LedsManager ledsManager;


void setup() {
  
    Serial.begin(115200);
    delay(1000);
    Serial.println("Starting Software!!!!");

    motionManager.setup();
    particlesManager.setup();
    ledsManager.setup();
}

void loop() 
{
    // Limit the animation frame rate to MAX_FPS. 
    uint32_t t;
    while(((t = micros()) - prevTime) < (1000000L / MAX_FPS));
    prevTime = t;

    motionManager.update();
    particlesManager.update(&motionManager);
    ledsManager.update(&particlesManager);
    
}
