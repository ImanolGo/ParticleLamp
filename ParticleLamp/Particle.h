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

    void update();

    void addForce(float x, float y);

    float getPosX() const {return x;}

    float getPosY() const  {return y;}

 private:

 	void updateParticle();

 	void checkEdges();


 	float x; 
 	float y; 
 	float vel_x;
 	float vel_y;
 	float acc_x; 
 	float acc_y; 

 	float mass;
	float topSpeed;
	float bounce;
	float offset;

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
	bounce = 1.0;
	topSpeed = 20;
	offset = 2;
}


void Particle::update()
{
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
	vel_x+=acc_x;
	vel_y+=acc_y;

	x+=vel_x;
	y+=vel_y;

	acc_x= 0;
 	acc_y= 0;

}

void Particle::checkEdges() {
	
	if (y > PIXELS_Y) {
		vel_y *= -bounce;
		y = PIXELS_Y - offset;
	}

	if (y < 0.0) {
		vel_y *= -bounce;
		y = offset;
	}
	if (x > PIXELS_X) {
		vel_x *= -bounce;
		x = PIXELS_X - offset;
	}
	if (x < 0.0) {
		vel_x *= -bounce;
		x = offset;
	}
}
