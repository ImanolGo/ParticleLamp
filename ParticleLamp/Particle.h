///////////////////////////////////////////////////////////////////
// Particle class
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

class Particle {

public:

  // constructors
  Particle();

    void update(float x, float y, float z);

    void addForce(float x, float y);

 public:

    float x; 
    float y; 

 private:

  void updateParticle();

  void checkEdges();



  float vel_x;
  float vel_y;
  float acc_x; 
  float acc_y; 

  float mass;
  float topSpeed;
  float bounce;
  float offset;

  float wall_restitution;
  float collide_restitution;
  float progression;
  float gravity;

  CRGB color;

};




Particle::Particle()
{
    x = 0; //left
  y = 0; //top
  vel_x= 0;
  vel_y= 0;
  acc_x= 0;
  acc_y= 0;
  mass = 1.0;
  bounce = 0.4;
  topSpeed = 20;
  offset = 0.1;

  collide_restitution = 0.59f;
  wall_restitution =  -0.79f;
  progression = 0.75f;
  gravity = 0.14f;
}


void Particle::update(float x, float y, float z)
{
    addForce(x, y);
    updateParticle();
    checkEdges();
}

void Particle::addForce(float x, float y)
{
    acc_x += x;
    acc_y += y;

}

void Particle::updateParticle()
{
  vel_x+=  gravity*acc_x;
  vel_y+= gravity*acc_y;

  x+=vel_x;
  y+=vel_y;

  acc_x= 0;
  acc_y= 0;

}

void Particle::checkEdges() {

   if (x > PIXELS_X) {
      vel_x *= wall_restitution;
      vel_y *= progression;
      x = PIXELS_X - offset;
    }
  
    if (x < 0.0) {
      vel_x *= wall_restitution;
      vel_y *= progression;
      x = offset;
    }
  
    if (y > PIXELS_Y) {
      y = PIXELS_Y - offset;
      vel_y *= wall_restitution;
      vel_x *= progression;
    }

  if (y < 0.0) {
     y = offset;
     vel_y *= wall_restitution;
     vel_x *= progression;
  }
  


  
}
