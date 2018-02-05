///////////////////////////////////////////////////////////////////
// Class controlling the leds and it's position in the matrix
//
//
// This code is under A Creative Commons Attribution/Share-Alike License
// http://creativecommons.org/licenses/by-sa/4.0/
// 2018, Imanol Gomez
///////////////////////////////////////////////////////////////////

#pragma once
#include "Arduino.h"
#include "FastLED.h"
#include "Constants.h"

#define NUM_LEDS PIXELS_X*PIXELS_Y
#define DATA_PIN 11


class LedsManager{

  public:
    
    LedsManager();
    
    void setup();
    void update();
   
  private:

    void updateLightPattern();
    void setupLeds();
    void initMatrix();
    void fade(void);     //devide each pixel by half
    void fadeBy(byte amount); //substract amount from each pixel 
    
    CRGB leds[NUM_LEDS];
    int matrixIndex[PIXELS_X][PIXELS_Y];
    int count;
    
};

LedsManager::LedsManager()
{
    count = 0;
}

void LedsManager::setup()
{
    setupLeds();
    initMatrix();
    
    Serial.println("LightManager::setup");
}

void LedsManager::setupLeds()
{
    Serial.print("LightManager::setupLeds -> Num LEDs: ");Serial.println(NUM_LEDS);
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
    pinMode(7, OUTPUT);
    digitalWrite(7, HIGH);  // enable access to LEDs

    FastLED.setMaxPowerInVoltsAndMilliamps (5, 2400);
    FastLED.clear();
}


void LedsManager::update()
{
    updateLightPattern();
}


void LedsManager::initMatrix()
{
    for(int j=0; j< PIXELS_Y; j++){
      for(int i=0; i< PIXELS_X; i++){
            int index = i + j*PIXELS_Y;
            if(j%2!=0){
              index = PIXELS_X - 1 - i + j*PIXELS_Y;
            }
            matrixIndex[i][j] = index;
            Serial.print("LightManager::initMatrix: i = ");  Serial.print(i);
            Serial.print(", j = ");  Serial.print(j);
            Serial.print(", index = ");  Serial.println(index);
      }
    }
}

void LedsManager::updateLightPattern()
{
    fade();
    //fadeBy(100);
    int numLEDS = NUM_LEDS;
    int j = count/PIXELS_Y;
    int i = count%PIXELS_Y;
    int index = matrixIndex[i][j];
    
    leds[index] = CRGB::Red;
    FastLED.show();
    delay(80);
    //leds[index] = CRGB::Black;
    //Serial.print("LightManager::updateLightPattern: count = ");  Serial.println(count);

    count = (count +1)%numLEDS;
}

void LedsManager::fade(void)
{
    for (int i = 0; i < NUM_LEDS; i++) 
    {
        leds[i].r = leds[i].r>>1;
        leds[i].g = leds[i].g>>1;
        leds[i].b = leds[i].b>>1;
    }
    
}


void LedsManager::fadeBy(byte amount)
{
    for (int i = 0; i < NUM_LEDS; i++) 
    {
        leds[i].r = leds[i].r < amount ? 0 : leds[i].r - amount;
        leds[i].g = leds[i].g < amount ? 0 : leds[i].g - amount;
        leds[i].b = leds[i].b < amount ? 0 : leds[i].b - amount;
    }
    
}


