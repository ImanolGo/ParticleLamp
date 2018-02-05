///////////////////////////////////////////////////////////////////
// Class holding and updating a particle system
//
//
// This code is under A Creative Commons Attribution/Share-Alike License
// http://creativecommons.org/licenses/by-sa/4.0/
// 2018, Imanol Gomez
///////////////////////////////////////////////////////////////////

#pragma once
#include "Arduino.h"
#include "Particle.h"
#include "MotionManager.h"
#include "Constants.h"



class ParticlesManager{

  public:
    
    ParticlesManager();
    
    void setup();
    void update(MotionManager* motionManager);

    float getX(int index) const;
    float getY(int index) const;
   
  private:

    void updateParticles(float x, float y, float z);
    
    Particle particles[NUM_PARTICLES];

    MotionManager* motionManager;   
    
};

ParticlesManager::ParticlesManager()
{
    //Intentionally left empty
}

void ParticlesManager::setup()
{
    ///
}

void ParticlesManager::update(MotionManager* motionManager)
{
    updateParticles(motionManager->ax, motionManager->ay, motionManager->az);
}


void ParticlesManager::updateParticles(float x, float y, float z)
{
    for(int i=0 ; i<NUM_PARTICLES; i++){
          particles[i].update(x,y,z);
    }  
}


float ParticlesManager::getX(int index) const
{
    if(index <0 || index >=NUM_PARTICLES){
      return -1;
    }

    return particles[index].getPosX();
}

float ParticlesManager::getY(int index) const
{
    if(index <0 || index >=NUM_PARTICLES){
      return -1;
    }

    return particles[index].getPosY();
}




